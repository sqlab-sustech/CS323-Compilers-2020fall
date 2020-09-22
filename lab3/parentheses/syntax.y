%{
    #include"lex.yy.c"
    void yyerror(const char *s){}
    int result;
%}
%token LP RP LB RB LC RC
%%
String: %empty {}
%%

int validParentheses(char *expr){
    yy_scan_string(expr);
    yyparse();
    return result;
}
