
add_library(REDALERT_Unicode STATIC
    WIN32LIB/UNICODE.H
)

set_target_properties(REDALERT_Unicode PROPERTIES LINKER_LANGUAGE CXX)

add_executable(REDALERT_UnicodeTestExe
    WIN32LIB/UNICODE_TEST.CPP
)

add_dependencies(REDALERT_UnicodeTestExe
    REDALERT_Unicode
)

add_test(NAME REDALERT_Unicode COMMAND REDALERT_UnicodeTestExe)
