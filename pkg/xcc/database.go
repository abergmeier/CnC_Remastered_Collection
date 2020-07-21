package xcc

import (
	"bufio"
	"encoding/binary"
	"io"
	"log"
)

// Entry is a Go representation of C data
// Has to be byte arrays since we run out of memory
type Entry struct {
	Filename []byte
	Comment  []byte
}

// Database is the representation of binary files
type Database struct {
	Entries []Entry
}

func mustReadCString(r io.Reader, buf *[]byte) {
	*buf = (*buf)[:0]
	for {
		var c byte
		err := binary.Read(r, binary.LittleEndian, &c)
		if err != nil {
			if err == io.EOF {
				return
			}
			panic(err)
		}

		if c == 0 {
			return
		}

		*buf = append(*buf, c)

		// ASCII, UTF-8 and CP437 have overlap in the standard
		// printable characters. Ensure that no filename is outside
		// that range.
		if c < 0x20 || c > 0x7E {
			log.Fatalf("Character %X from %s not in ASCII range\n", c, string(*buf))
		}

	}
}

func MustReadDatabase(r io.Reader) *Database {

	var count int32

	buffered := bufio.NewReaderSize(r, 1024)
	err := binary.Read(buffered, binary.LittleEndian, &count)
	if err != nil {
		if err == io.EOF || err == io.ErrUnexpectedEOF {
			panic("Unexpected EOF")
		}
		panic(err)
	}

	log.Printf("Found %d XCC entries\n", count)

	db := &Database{}

	csBuf := []byte{}

	for i := int32(0); i != count; i++ {
		var entry Entry
		mustReadCString(buffered, &csBuf)
		entry.Filename = make([]byte, len(csBuf), len(csBuf))
		copy(entry.Filename, csBuf)
		mustReadCString(buffered, &csBuf)
		entry.Comment = make([]byte, len(csBuf), len(csBuf))
		copy(entry.Comment, csBuf)
		db.Entries = append(db.Entries, entry)
	}

	return db
}
