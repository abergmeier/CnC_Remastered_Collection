package write

import (
	"fmt"
	"io"
	"log"
	"sort"

	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/crc"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/db"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/file"
)

func writeHeader(w io.Writer) {
	fmt.Fprintln(w, `apiVersion: 1
kind: Files`)
}

func writeRootEntry(entry *file.KnownRootEntry, w io.Writer) {
	fmt.Fprintf(w, `- contentHash: "sha256:%X"
`, entry.ContentHash)

	fmt.Fprintf(w, `  size: %d
`, entry.Size)

	if len(entry.RootInfos) == 0 {
		return
	}

	fmt.Fprintln(w, `  info:`)

	for _, ri := range entry.RootInfos {
		fmt.Fprintf(w, `  - filename: "%s"
`, ri.Filename)

		fmt.Fprintf(w, `    raChecksum: %s
`, crc.RAHexStringFromInt32(ri.RACRC))
	}
}

func writeEmbeddedEntry(entry *file.KnownEmbeddedEntry, w io.Writer) {

	fmt.Fprintf(w, `- contentHash: "sha256:%X"
`, entry.ContentHash)

	fmt.Fprintf(w, `  size: %d
`, entry.Size)

	if len(entry.EmbeddedIn) == 0 {
		return
	}

	fmt.Println(w, `  embeddedIn:`)

	for _, ei := range entry.EmbeddedIn {
		fmt.Fprintf(w, `  - asRaChecksum: %s
		`, crc.RAHexStringFromInt32(ei.AsRACRC))

		if ei.AsFilename != "" {
			fmt.Fprintf(w, `    asFilename: "%s"
`, ei.AsFilename)
		}

		if !ei.ContentHash.IsZero() {
			fmt.Fprintf(w, `    contentHash: "sha256:%X"
`, ei.ContentHash)
		}

		if ei.Offset != 0 {
			fmt.Fprintf(w, `    offset: %d
`, ei.Offset)
		}
	}
}

func writeUnknownEntry(entry *file.UnknownEntry, w io.Writer) {
	fmt.Fprintf(w, `- raChecksum: %s
`, crc.RAHexStringFromInt32(entry.RACRC))

	if entry.Filename != "" {
		fmt.Fprintf(w, `  filename: "%s"
`, entry.Filename)
	}

	if entry.Comment != "" {
		fmt.Fprintf(w, `  comment: "%s"
`, entry.Comment)
	}
}

func EntriestoYAML(entries *db.Entries, w io.Writer) {

	writeHeader(w)

	fmt.Fprintln(w, "unknown:")
	writeSortedByCRC(entries.UnknownEmbedded, w)
	log.Printf("Wrote %d file entries without sha\n", len(entries.UnknownEmbedded))

}

func writeSortedByCRC(m map[int32]*file.UnknownEntry, w io.Writer) {
	keys := make([]string, 0, len(m))
	sm := make(map[string]*file.UnknownEntry, len(m))

	for k, v := range m {
		c := crc.RAHexStringFromInt32(k)
		keys = append(keys, c)
		sm[c] = v
	}

	sort.Strings(keys)

	for _, key := range keys {
		entry := sm[key]
		writeUnknownEntry(entry, w)
	}
}

func writeSortedByContentHash(rootEntries map[file.ShaDigest]*file.KnownRootEntry, embeddedEntries map[file.ShaDigest]*file.KnownEmbeddedEntry, w io.Writer) {
	sortedRootEntries := db.SortRootDigests(rootEntries)
	sortedEmbeddedEntries := db.SortEmbeddedDigests(embeddedEntries)

	ri := 0
	ei := 0

	for ri != len(sortedRootEntries) && ei != len(sortedEmbeddedEntries) {

		if file.Less(sortedEmbeddedEntries[ei].ContentHash, sortedRootEntries[ri].ContentHash) {
			writeEmbeddedEntry(&sortedEmbeddedEntries[ei], w)
			ei++
			continue
		}

		writeRootEntry(&sortedRootEntries[ri], w)
		ri++
	}
}
