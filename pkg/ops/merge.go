package ops

// #include <stdlib.h>
// #include <string.h>
// #include "../../REDALERT/platformlib/PLATCRC.H"
import "C"

import (
	"fmt"
	"log"

	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/crc"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/db"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/file"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/xcc"
)

func MustMerge(xdb *xcc.Database, y *db.Entries) {

	for _, xe := range xdb.Entries {
		c := crc.RA(string(xe.Filename))
		ue, ok := y.UnknownEmbedded[c]
		if !ok {
			ne := &file.UnknownEntry{
				Filename: string(xe.Filename),
				RACRC:    c,
				Comment:  string(xe.Comment),
			}
			y.UnknownEmbedded[ne.RACRC] = ne
			continue
		}
		ue.Comment = string(xe.Comment)

		// Paranoia testing
		if string(xe.Filename) != ue.Filename {
			panic("Filename mismatch")
		}
	}
}

func MustMergeEntries(dest *db.Entries, other *db.Entries) {

	err := mergeUnknown(dest.UnknownEmbedded, other.UnknownEmbedded)
	if err != nil {
		log.Fatal(err)
	}
}

func mergeRootInfoSlice(dest *[]file.RootInfo, other []file.RootInfo) error {

	rim := map[int32]file.RootInfo{}

	for _, ri := range *dest {
		rim[ri.RACRC] = ri
	}

	for _, ri := range other {
		dri, ok := rim[ri.RACRC]
		if !ok {
			rim[ri.RACRC] = ri
			continue
		}

		err := mergeRootInfo(&dri, &ri)
		if err != nil {
			return err
		}
	}

	*dest = (*dest)[:0]

	for _, ri := range rim {
		*dest = append(*dest, ri)
	}

	return nil
}

func mergeRootInfo(dest *file.RootInfo, other *file.RootInfo) error {

	err := mergeCRC(&dest.RACRC, other.RACRC)
	if err != nil {
		return err
	}

	if dest.Filename == "" {
		dest.Filename = other.Filename
	} else if other.Filename != "" {
		return fmt.Errorf("Conflicting Filenames for RACRC %s: %s <-> %s", crc.RAHexStringFromInt32(dest.RACRC), dest.Filename, other.Filename)
	}

	return nil
}

func mergeUnknown(dest map[int32]*file.UnknownEntry, other map[int32]*file.UnknownEntry) error {
	for ocrc, oe := range other {
		de, ok := dest[ocrc]
		if !ok {
			dest[ocrc] = oe
			continue
		}

		err := mergeUnknownEntry(de, oe)
		if err != nil {
			return err
		}
	}

	return nil
}

func mergeUnknownEntry(dest *file.UnknownEntry, other *file.UnknownEntry) error {
	err := mergeCRC(&dest.RACRC, other.RACRC)
	if err != nil {
		return err
	}

	if dest.Filename == "" {
		dest.Filename = other.Filename
	} else if other.Filename != "" {
		return fmt.Errorf("Conflicting Filenames for RACRC %s: %s <-> %s", crc.RAHexStringFromInt32(dest.RACRC), dest.Filename, other.Filename)
	}

	if dest.Comment == "" {
		dest.Comment = other.Comment
	}

	return nil
}

func mergeCRC(dest *int32, other int32) error {
	if *dest == other {
		return nil
	}

	if *dest == 0 {
		*dest = other
	} else if other != 0 {
		return fmt.Errorf("Conflicting CRC values: %s <-> %s", crc.RAHexStringFromInt32(*dest), crc.RAHexStringFromInt32(other))
	}

	return nil
}
