%{
	#include<bits/stdc++.h>
	int numOfInt=0,numOfFloat=0;
%}

%%
[0-9]+"."[0-9]+ {ECHO;std::cout<<" : Float Number"<<std::endl;numOfFloat++;}
[0-9]+ {ECHO;std::cout<<" : Integer Number"<<std::endl;numOfInt++;}
%%

int yywrap(){
	return 1;
}

int main(){

	std::cout<<"Enter Numbers : ";
	yylex();
	std::cout<<"Total count of Float Numbers : "<<numOfFloat<<std::endl;
	std::cout<<"Total count of Integer Numbers : "<<numOfInt<<std::endl;
	return 0;
}
