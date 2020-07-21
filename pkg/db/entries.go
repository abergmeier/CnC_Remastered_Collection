package db

import (
	"sort"

	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/file"
)

// Entries that can happen
// May be a file entry (root) or a embedded entry (in root).
// Embedded entries may be Unknown.
type Entries struct {
	UnknownEmbedded map[int32]*file.UnknownEntry
}

func NewEntries() *Entries {
	return &Entries{
		UnknownEmbedded: map[int32]*file.UnknownEntry{},
	}
}

func SortRootDigests(entries map[file.ShaDigest]*file.KnownRootEntry) []file.KnownRootEntry {

	sortedKeys := make(file.ShaDigests, 0, len(entries))
	for k := range entries {
		sortedKeys = append(sortedKeys, k)
	}

	sort.Sort(sortedKeys)

	sorted := make([]file.KnownRootEntry, 0, len(entries))

	for _, k := range sortedKeys {
		e := entries[k]
		sorted = append(sorted, *e)
	}

	return sorted
}

func SortEmbeddedDigests(entries map[file.ShaDigest]*file.KnownEmbeddedEntry) []file.KnownEmbeddedEntry {

	sortedKeys := make(file.ShaDigests, 0, len(entries))
	for k := range entries {
		sortedKeys = append(sortedKeys, k)
	}

	sort.Sort(sortedKeys)

	sorted := make([]file.KnownEmbeddedEntry, 0, len(entries))

	for _, k := range sortedKeys {
		e := entries[k]
		sorted = append(sorted, *e)
	}

	return sorted
}
