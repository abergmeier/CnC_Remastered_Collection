
add_library(gbuffer_win32 STATIC
    BUFFER.CPP
    BUFFER.H
    DDRAW.CPP
    DRAWBUFF.H
    GBUFFER.CPP
    GBUFFER.H
    ICONCACH.H
    MISC.H
    TILE.H
    WWSTD.H
)

add_executable(gbuffer_win32_test_exe WIN32
    GBUFFER_TEST.CPP
)

target_link_libraries(gbuffer_win32_test_exe
    gbuffer_win32
)

add_test(NAME gbuffer_win32_test COMMAND gbuffer_win32_test_exe)
