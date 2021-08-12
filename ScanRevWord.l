%{
#include <stdio.h>
int n=0;
%}

%%
int|double|if|else { printf("Reserved word");}

[a-zA-z]+[a-zA-z_]* { printf("identifier");}

%%

int main()
{
     yylex();
}
int yywrap()
{
     return 1;
}
