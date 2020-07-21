package read

import (
	"io"
	"io/ioutil"
	"log"

	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/crc"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/db"
	ydb "github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/db/yaml"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/file"
	"gopkg.in/yaml.v2"
)

func MustFromYAMLDatabase(r io.Reader) *db.Entries {

	buf, err := ioutil.ReadAll(r)
	if err != nil {
		log.Fatalln(err)
	}

	ydb := ydb.DatabaseV1{}

	err = yaml.Unmarshal(buf, &ydb)
	if err != nil {
		log.Fatal(err)
	}

	if ydb.Kind != "Files" || ydb.APIVersion != "1" {
		if len(ydb.UnknownFileEntries) == 0 {
			return db.NewEntries()
		}
		log.Fatalf("Unsupported %s %s", ydb.Kind, ydb.APIVersion)
	}

	log.Printf("Read %d file entries without sha\n", len(ydb.UnknownFileEntries))

	es, err := convertEntries(ydb.UnknownFileEntries)
	if err != nil {
		log.Fatal(err)
	}
	return es
}

func convertEntries(yUnknown []ydb.UnknownFileEntry) (*db.Entries, error) {

	es := db.NewEntries()

	for _, uf := range yUnknown {
		ue := convertUnknown(&uf)
		es.UnknownEmbedded[ue.RACRC] = ue
	}

	return es, nil
}

func convertUnknown(fe *ydb.UnknownFileEntry) *file.UnknownEntry {
	return &file.UnknownEntry{
		Comment:  fe.Comment,
		Filename: fe.Filename,
		RACRC:    crc.FromUint32(fe.RaCRC),
	}
}
