
#add_library(TIBERIANDAWN SHARED
#    UNICODE.H
#)

add_library(Unicode STATIC
    WIN32LIB/UNICODE.H
)

set_target_properties(Unicode PROPERTIES LINKER_LANGUAGE CXX)

add_executable(UnicodeTestExe
    WIN32LIB/UNICODE_TEST.CPP
)

add_dependencies(UnicodeTestExe
    Unicode
)

add_test(NAME Unicode COMMAND UnicodeTestExe)

#target_include_directories(TIBERIANDAWN PUBLIC platformlib)
#target_compile_options(TIBERIANDAWN PUBLIC -w)
