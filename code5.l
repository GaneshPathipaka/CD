%{
	#include<bits/stdc++.h>
%}

%%
\/\/(.*) {std::cout<<"It is a single line command"<<yytext<<std::endl;}
\/\*(.*\n)*.*\*\/ {std::cout<<"It is a Multiple line command"<<yytext<<std::endl;}
%%

int yywrap(){
	return 1;
}

int main(){
	yyin=fopen("input5.c++","r");
	yyout=fopen("out.c++","w");
	yylex();
	return 0;
}
