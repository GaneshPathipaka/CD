#include<bits/stdc++.h>
using namespace std;

int numOfProductions;
char productionSet[10][10];

void addToResultSet(char Result[],char val){
	int k;
	for(k=0;Result[k]!='\0';k++){
		if(Result[k]==val){
			return;
		}
	}
	Result[k]=val;
	Result[k+1]='\0';
}

void FIRST(char* Result,char c){
	int i,j,k;
	char subResult[20];
	int foundEpsilon;
	subResult[0]='\0';
	Result[0]='\0';
	
	if(!(isupper(c))){
		addToResultSet(Result,c);
		return;
	}
	
	for(i=0;i<numOfProductions;i++){
		if(productionSet[i][0]==c){
			if(productionSet[i][2]=='$'){
				addToResultSet(Result,'$');
			}
			else{
				j=2;
				while(productionSet[i][j]!='\0'){
					foundEpsilon=0;
					FIRST(subResult,productionSet[i][j]);
					for(k=0;subResult[k]!='\0';k++){
						addToResultSet(Result,subResult[k]);
					}
					for(k=0;subResult[k]!='\0';k++){
						if(subResult[k]=='$'){
							foundEpsilon=1;
							break;
						}
					}
					if(!foundEpsilon){
						break;
					}
					j++;
				}	
			}
		}
	}
	return;
}

int main(){
	int i;
	char choice;
	char c;
	char result[20];
	
	cout<<"How Many number of productions ? :"<<endl;
	cin>>numOfProductions;
	
	for(int i=0;i<numOfProductions;i++){
		cout<<"Enter productions Number "<<i+1<<" : "<<endl;
		cin>>productionSet[i];
	}
	
	do{
		cout<<"Find the FIRST of : ";
		cin>>c;
		FIRST(result,c);
		cout<<" FIRST("<<c<<")"<<"= { ";
		for(i=0;result[i]!='\0';i++){
			cout<<result[i]<<" ";
		}
		cout<<"}"<<endl;
		cout<<"Enter 'y' to continue : ";
		cin>>choice;
		cout<<endl;
	}
	while(choice=='y' || choice=='Y');
	
	return 0;
}


/*
ganesh@sampu:~/Desktop/CDLAB$ g++ FIRST.c++ 
ganesh@sampu:~/Desktop/CDLAB$ ./a.out 
How Many number of productions ? :
9
Enter productions Number 1 : 
S-aBDh
Enter productions Number 2 : 
B-cC
Enter productions Number 3 : 
C-bc
Enter productions Number 4 : 
C-$
Enter productions Number 5 : 
D-EF
Enter productions Number 6 : 
E-g
Enter productions Number 7 : 
E-$
Enter productions Number 8 : 
F-f
Enter productions Number 9 : 
F-$
Find the FIRST of : S
 FIRST(S)= { a }
Enter 'y' to continue : y

Find the FIRST of : b
 FIRST(b)= { b }
Enter 'y' to continue : Y

Find the FIRST of : B
 FIRST(B)= { c }
Enter 'y' to continue : Y

Find the FIRST of : C
 FIRST(C)= { b $ }
Enter 'y' to continue : Y

Find the FIRST of : D
 FIRST(D)= { g $ f }
Enter 'y' to continue : Y

Find the FIRST of : E
 FIRST(E)= { g $ }
Enter 'y' to continue : Y

Find the FIRST of : F
 FIRST(F)= { f $ }
Enter 'y' to continue : N

ganesh@sampu:~/Desktop/CDLAB$ 


*/
