
add_library(TD_MIXFILE
    CCFILE.CPP
    CCFILE.H
    CDFILE.CPP
    CDFILE.H
    LINK.CPP
    LINK.H
    MIXFILE.CPP
    MIXFILE.H
    RAWFILE.CPP
    RAWFILE.H
)

target_include_directories(TD_MIXFILE PUBLIC
    ..
)

target_include_directories(TD_MIXFILE PRIVATE
    platformlib
)
