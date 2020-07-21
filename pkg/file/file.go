package file

import (
	"crypto/sha256"
	"encoding/binary"
	"unsafe"
)

// Embedding represents where a file was embedded into.
// References embedding file by its ContentHash.
// Includes details like which Offset inside the file
type Embedding struct {
	ContentHash ShaDigest
	AsFilename  string
	AsRACRC     int32
	Offset      int32
}

type EmbeddingId = [sha256.Size + 4]byte

func (e *Embedding) Id() EmbeddingId {
	result := EmbeddingId{}
	copy(result[:sha256.Size], e.AsFilename)
	op := unsafe.Pointer(&e.Offset)
	binary.LittleEndian.PutUint32(result[sha256.Size:], *(*uint32)(op))
	return result
}

type RootInfo struct {
	Filename string
	RACRC    int32
}

// Entry represents a file with Metadata
type KnownEmbeddedEntry struct {
	ContentHash ShaDigest
	Size        int32
	EmbeddedIn  []Embedding
}

type KnownRootEntry struct {
	ContentHash ShaDigest
	Size        int32
	RootInfos   []RootInfo
}

type UnknownEntry struct {
	Filename string
	RACRC    int32
	Comment  string
}

type ShaDigest [sha256.Size]byte

func (d ShaDigest) IsZero() bool {
	for i := 0; i != sha256.Size; i++ {
		if d[i] != 0 {
			return false
		}
	}
	return true
}

type CRCs []int32

func (c CRCs) Len() int {
	return len(c)
}

func (c CRCs) Less(i, j int) bool {
	return c[i] < c[j]
}

func (c CRCs) Swap(i, j int) {
	v := c[i]
	c[i] = c[j]
	c[j] = v
}

type ShaDigests []ShaDigest

func (d ShaDigests) Len() int {
	return len(d)
}

func (d ShaDigests) Less(i, j int) bool {
	id := d[i]
	jd := d[j]
	return Less(id, jd)
}

func Less(lhs ShaDigest, rhs ShaDigest) bool {
	for index := 0; index != sha256.Size; index++ {
		if lhs[index] < rhs[index] {
			return true
		}

		if lhs[index] == rhs[index] {
			continue
		}

		return false
	}
	return false
}

func (d ShaDigests) Swap(i, j int) {
	v := d[i]
	d[i] = d[j]
	d[j] = v
}
