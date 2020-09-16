# header begin
cmake_minimum_required(VERSION 3.16.6)
project(CS323_Compilers_lab02_wc LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lfl")
# only works in terminal
FIND_PACKAGE(FLEX REQUIRED)
SET(FlexOutput ./lex.yy.c)
IF (FLEX_FOUND)
    MESSAGE(${FLEX_EXECUTABLE})
    ADD_CUSTOM_COMMAND(
            OUTPUT ${FlexOutput}
            COMMAND ${FLEX_EXECUTABLE}
            --outfile=${FlexOutput}
            ${CMAKE_SOURCE_DIR}/lex.l
    )
ENDIF ()
add_executable(wc.out ${FlexOutput})