package main

import (
	"bufio"
	"flag"
	"fmt"
	"io"
	"log"
	"os"
	"path"
	"sync"

	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/db"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/db/read"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/db/write"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/ops"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/xcc"
)

var (
	xccFlagSet = flag.NewFlagSet("xcc", flag.ContinueOnError)
)

func printXccUsage() {
	fmt.Fprintf(xccFlagSet.Output(), `usage: %s xcc <command>
Available commands:
  import - Imports from XCC Database (and save to disk)
`, path.Base(os.Args[0]))
	xccFlagSet.PrintDefaults()
}

func xccCommand(args []string) {
	xccFlagSet.Usage = printXccUsage

	if len(args) != 1 || args[0] != "import" {
		xccFlagSet.Usage()
		os.Exit(1)
	}

	var xdb *xcc.Database
	var fe *db.Entries

	wg := sync.WaitGroup{}

	wg.Add(2)
	go func() {
		defer wg.Done()
		r := xcc.MustGetFromRemote()
		defer r.Close()
		xdb = xcc.MustReadDatabase(r)
	}()

	go func() {
		defer wg.Done()
		fe = mustReadFileEntries("files.yaml")
	}()

	wg.Wait()
	ops.MustMerge(xdb, fe)
	mustWriteToYamlFile(fe, "files.yaml")
}

func mustReadFileEntries(p string) *db.Entries {
	f, err := os.Open(p)
	if err != nil {
		if os.IsNotExist(err) {
			return db.NewEntries()
		}
	}
	defer f.Close()
	return mustReadEntries(f)
}

func mustReadEntries(r io.Reader) *db.Entries {
	rb := bufio.NewReader(r)
	return read.MustFromYAMLDatabase(rb)
}

func mustWriteToYaml(fe *db.Entries, w io.Writer) {
	bw := bufio.NewWriter(w)
	defer func() {
		err := bw.Flush()
		if err != nil {
			log.Println(err)
		}
	}()

	write.EntriestoYAML(fe, bw)
}

func mustWriteToYamlFile(fe *db.Entries, p string) {
	file, err := os.OpenFile(p, os.O_CREATE|os.O_WRONLY, 0611)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	mustWriteToYaml(fe, file)
}
