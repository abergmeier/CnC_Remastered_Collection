package main

import (
	"bytes"
	"fmt"
	"strings"
	"testing"

	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/ops"
	"github.com/abergmeier/CnC_Remastered_Multiplatform/pkg/xcc"
)

func TestYamlHandling(t *testing.T) {
	yaml := `apiVersion: 1
kind: Files
unknown:
- raChecksum: 0x82261816
  filename: "minigun.shp"
- raChecksum: 0x819FAAE2
  filename: "Bar"
  comment: "icon: a10 warthog"
`

	yamlExpected := `apiVersion: 1
kind: Files
unknown:
- raChecksum: 0x004F4F4F
  filename: "OOO"
- raChecksum: 0x819FAAE2
  filename: "Bar"
  comment: "icon: a10 warthog"
- raChecksum: 0x82261816
  filename: "minigun.shp"
  comment: "icon"
`

	xr := bytes.NewReader([]byte{2, 0, 0, 0, 'O', 'O', 'O', 0, 0, 'm', 'i', 'n', 'i', 'g', 'u', 'n', '.', 's', 'h', 'p', 0, 'i', 'c', 'o', 'n', 0})
	xdb := xcc.MustReadDatabase(xr)

	yr := bytes.NewReader([]byte(yaml))
	fe := mustReadEntries(yr)

	ops.MustMerge(xdb, fe)
	buf := bytes.NewBuffer([]byte{})
	mustWriteToYaml(fe, buf)

	if buf.String() != yamlExpected {
		errorDiff(t, buf.String(), yamlExpected)
	}
}

func errorDiff(t *testing.T, lhs, rhs string) {
	b := ""
	lhsSlice := strings.Split(lhs, "\n")
	rhsSlice := strings.Split(rhs, "\n")
	for i := 0; i < len(lhsSlice) || i < len(rhsSlice); i++ {
		lhsl := getLine(i, lhsSlice)
		rhsl := getLine(i, rhsSlice)
		if lhsl != rhsl {
			b = fmt.Sprintf(`%s~ %s <-> %s
`, b, lhsl, rhsl)
			continue
		}
		b = fmt.Sprintf(`%s  %s
`, b, lhsl)
	}
	t.Errorf(`Mismatch:
%s`, b)
}

func getLine(i int, lines []string) string {
	if i < len(lines) {
		return lines[i]
	}

	return ""
}
