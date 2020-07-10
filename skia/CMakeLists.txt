add_library(gbuffer_skia STATIC
    gbuffer.cpp
    gbuffer.h
)

add_executable(gbuffer_skia_test_exe
    gbuffer_test.cpp
)

add_dependencies(gbuffer_skia_test_exe
    gbuffer_skia
)

add_test(NAME gbuffer_skia_test COMMAND gbuffer_skia_test_exe)
