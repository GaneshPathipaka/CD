%{
	#include<bits/stdc++.h>
	int vow_count=0;
	int const_count=0;
%}

%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%

int yywrap(){return 1;}

int main(){
	std::cout<<"Enter the string : "<<std::endl;
	yylex();
	std::cout<<"no of vowels : "<<vow_count<<std::endl;
	std::cout<<"no of consonants : "<<const_count;

	return 0;
}

/*
ganesh@sampu:~/Desktop/CDLAB$ flex code1.l
ganesh@sampu:~/Desktop/CDLAB$ g++ lex.yy.c -lfl
ganesh@sampu:~/Desktop/CDLAB$ ./a.out 
Enter the string : 
ganesh
no of vowels : 2
no of consonants : 4
*/
