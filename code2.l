%{
	#include<bits/stdc++.h>
	int lc=0,sc=0,tc=0,ch=0,c=0,wc=0;
%}

%%
\n {lc++;}
([ ])+ {sc++;}
\t {tc++;}
. {ch++;c++;}
[a-zA-Z0-9]+ {wc++;c=c+yyleng;}

%%

int yywrap(){return 1;}
int main(){
	yylex();
	std::cout<<"Lines Count is : "<<lc<<std::endl;
	std::cout<<"Spaces Count is : "<<sc<<std::endl;
	std::cout<<"Tabs Count is : "<<tc<<std::endl;
	std::cout<<"Characters Count is : "<<c<<std::endl;
	std::cout<<"Words Count is : "<<wc+ch<<std::endl;
	return 0;
}
