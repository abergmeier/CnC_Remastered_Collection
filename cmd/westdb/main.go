package main

import (
	"flag"
	"fmt"
	"os"
	"path"
)

func printRootUsage() {
	fmt.Fprintf(flag.CommandLine.Output(), `usage: %s <command>
Available commands:
  %s - Handles XCC Database operations
`, path.Base(os.Args[0]), xccFlagSet.Name())
	flag.PrintDefaults()
}

func main() {
	flag.Usage = printRootUsage

	command := ""

	flag.Parse()

	args := []string{}

	if flag.NArg() > 0 {
		args = flag.Args()[1:]
		command = flag.Arg(0)
	}

	if command == xccFlagSet.Name() {
		xccCommand(args)
		return
	}

	flag.Usage()
	os.Exit(1)
}
