
add_library(crc STATIC
    CRC.CPP
    CRC.H
)

target_include_directories(crc PUBLIC
    ..
)

target_include_directories(crc PRIVATE
    .
)
