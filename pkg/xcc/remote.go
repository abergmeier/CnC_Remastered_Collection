package xcc

import (
	"io"
	"log"
	"net/http"
)

// MustGetFromRemote fetches latest XCC file from Remote
func MustGetFromRemote() io.ReadCloser {

	url := "https://github.com/OpenRA/OpenRA/blob/bleed/global%20mix%20database.dat?raw=true"

	resp, err := http.Get(url)
	if err != nil {
		log.Fatal(err)
	}
	if resp.StatusCode != 200 {
		log.Fatalf("Could not download %s\n", url)
	}
	return resp.Body
}
