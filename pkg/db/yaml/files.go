package yaml

// DatabaseV1 represents V1 of stored data
type DatabaseV1 struct {
	APIVersion         string             `yaml:"apiVersion"`
	Kind               string             `yaml:"kind"`
	UnknownFileEntries []UnknownFileEntry `yaml:"unknown"`
}

type UnknownFileEntry struct {
	Filename string
	Comment  string
	RaCRC    uint32 `yaml:"raChecksum"` // Only unsigned can be converted hex from YAML
}
