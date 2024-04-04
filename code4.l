%{
	#include<bits/stdc++.h>
	int length;
	void fun(int length);
%}

%%
[a-zA-Z0-9]+ {length=yyleng;fun(length);}
%%

void fun(int length){
	if(yytext[0]=='A'){
		if(length==3){
			std::cout<<yytext<<" is word with length 3"<<std::endl;
		}
		else{
			std::cout<<"Word is not of  length 3"<<std::endl;
		}
	}
	else{
		std::cout<<"Word is not starting with A"<<std::endl;
	}
}

int yywrap(){
	return 1;
}
int main(){
	std::cout<<"Enter Words : "<<std::endl;
	yylex();
	return 0;
}
