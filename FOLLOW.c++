#include<bits/stdc++.h>
using namespace std;

int n,m=0,p,i=0,j=0;
char a[10][10],followResult[10];

void FOLLOW(char c);
void FIRST(char c);


void FOLLOW(char c){
	if(a[0][0]==c){
		followResult[m++]='$';
	}
	for(i=0;i<n;i++){
		for(j=2;j<strlen(a[i]);j++){
			if(a[i][j]==c){
				if(a[i][j+1]!='\0'){
					FIRST(a[i][j+1]);
				}
				if(a[i][j+1]=='\0' &&c!=a[i][0]){
					FOLLOW(a[i][0]);
				}
			}
		}
	}
}

void FIRST(char c){
	int k;
	if(!(isupper(c))){
		followResult[m++]=c;
	}
	for(k=0;k<n;k++){
		if(a[k][0]==c){
			if(a[k][2]=='$'){
				FOLLOW(a[k][0]);
			}
			else if(islower(a[k][2])){
				followResult[m++]=a[k][2];
			}
			else{
				FIRST(a[k][2]);
			}
		}
	}
}


int main(){

	int i;
	char choice;
	char c,ch;
	cout<<"Enter the no of productions: ";
	cin>>n;

	for(i=0;i<n;i++){
		cout<<"Enter product : "<<i+1<<endl;
		cin>>a[i];
	}
	
	do{
		m=0;
		cout<<"Find FOLLOW of  : ";
		cin>>c;
		FOLLOW(c);
		cout<<"Follow of ("<<c<<") is "<<"{ ";
		for(i=0;i<m;i++){
			cout<<followResult[i]<<" ";
		}
		cout<<"}"<<endl;
		cout<<"Want to continue enter 'y' ? ";
		cin>>choice;
	}
	while(choice=='y' or choice=='Y');
	
	return 0;
}


/*
ganesh@sampu:~/Desktop/CDLAB$ g++ FOLLOW.c++ 
ganesh@sampu:~/Desktop/CDLAB$ ./a.out 
Enter the no of productions: 8
Enter product : 1
E-TM
Enter product : 2
M-+TM
Enter product : 3
M-$
Enter product : 4
T-FS
Enter product : 5
S-*FS
Enter product : 6
S-$
Enter product : 7
F-(E)
Enter product : 8
F-i
Find FOLLOW of  : E
Follow of (E) is { $ ) }
Want to continue enter 'y' ? Y
Find FOLLOW of  : M
Follow of (M) is { $ ) }
Want to continue enter 'y' ? Y
Find FOLLOW of  : T
Follow of (T) is { + $ ) }
Want to continue enter 'y' ? Y
Find FOLLOW of  : S
Follow of (S) is { + $ ) }
Want to continue enter 'y' ? Y
Find FOLLOW of  : F
Follow of (F) is { * + $ ) }
Want to continue enter 'y' ? N

*/
