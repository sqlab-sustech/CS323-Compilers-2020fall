%{
    #include"syntax.tab.h"
%}
%option noyywrap
%%

"{" { return LC; }
"}" { return RC; }
"[" { return LB; }
"]" { return RB; }
":" { return COLON; }
"," { return COMMA; }
"true" { return TRUE; }
"false" { return FALSE; }
"null" { return VNULL; }
\"[a-zA-Z]+\" { return STRING; }
[1-9][0-9]+ { return NUMBER; }
[ \n\r\t] {}
. { printf("lexical error: %s\n", yytext); }
