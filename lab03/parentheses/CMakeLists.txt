# header begin
cmake_minimum_required(VERSION 3.16.6)
project(CS323_Compilers_lab03_parentheses LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lfl -ly -fPIC")
FIND_PACKAGE(FLEX REQUIRED)
FIND_PACKAGE(BISON REQUIRED)
FLEX_TARGET(lexer
    lex.l ${CMAKE_SOURCE_DIR}/lex.yy.c)
BISON_TARGET(parser
    syntax.y ${CMAKE_SOURCE_DIR}/syntax.tab.c)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)


ADD_LIBRARY(useless
     SHARED
     ${CMAKE_SOURCE_DIR}/lex.yy.c
     )

ADD_LIBRARY(paren
     SHARED
     ${CMAKE_SOURCE_DIR}/syntax.tab.c)

ADD_LIBRARY(useless2
     SHARED
     ${CMAKE_SOURCE_DIR}/syntax.tab.c
)
TARGET_LINK_LIBRARIES(useless2 useless)