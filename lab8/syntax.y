%{
    #include <stdbool.h>
    #include"lex.yy.c"
    void yyerror(const char*);

    bool is_valid = true;  // use this value
%}

%token LC RC LB RB COLON COMMA
%token STRING NUMBER
%token TRUE FALSE VNULL
%%

Json:
      Value
    ;
Value:
      Object
    | Array
    | STRING
    | NUMBER
    | TRUE
    | FALSE
    | VNULL
    ;
Object:
      LC RC
    | LC Members RC
    ;
Members:
      Member
    | Member COMMA Members
    ;
Member:
      STRING COLON Value
    ;
Array:
      LB RB
    | LB Values RB
    ;
Values:
      Value
    | Value COMMA Values
    ;
%%


int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    if(is_valid) {
        printf("%d\n", is_valid);
    }
    return 0;
}
