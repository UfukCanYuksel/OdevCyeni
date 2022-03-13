#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 9999

/*
int harfKontrol(y){
	int i=0;
	if ((y-'0')>= 65 && (y-'0')<=90 ||(y-'0')>= 97 && (y-'0')<=122){
		i++;
	}
	return i;
}
int sayiKontrol(y){
	int i=0;
	if((y-'0')>= 48 && (y-'0')<=57){
		i++;
	}
	return i;
}
*/
void boslukKontrol(char x[],char* y){
	int i=0,j=0;
	for(i=0;x[i] != '\0';i++){
		if(x[i] != ' ' && x[i] != '\n' && x[i] != '\f' && x[i] != '\t' && x[i] != '\v' && x[i] != '\r'){
			y[j]=x[i];
			j++;
		}
	}
}
void tokenizer(char y[]){
	int boyut=strlen(y);
	char w[MAX];
	int k=0,l=0;
	while(y[k] != '\0'){
		if(isdigit (y[k])&&isdigit (y[k+1])){
			w[l]=y[k];
			l++;
		}else if(isalpha (y[k])&&isalpha (y[k+1])){
			w[l]=y[k];
			l++;
		}else if(y[k]=='('||y[k]==')'||y[k]=='{'||y[k]=='}' 
		||y[k]=='['||y[k]==']'){
			w[l]=y[k];
			w[l+1]=',';
			l=l+2;
		}else if(isalpha (y[k])||isdigit (y[k])){ 
			w[l]=y[k];
			w[l+1]=',';
			l=l+2;
		}else if(y[k]==y[k+1]){ 
			w[l]=y[k];
			l++;
		}else if(y[k+1]!='='){ 
			w[l]=y[k];
			w[l+1]=',';
			l=l+2;
		}else{
			w[l]=y[k];
			l++;
		}
		    k++;
		} 
		printf("%s",w);
		
	}

int main(){
	char x[MAX];
	char y[MAX];
	char f[MAX];
	char ad[MAX];
	char kaynak[MAX];
	int i,j=0;
	printf("Dosya adini giriniz : ");
	scanf("%s",ad);
	FILE *dosya=fopen(("%s",ad),"r");
	while(fgets(kaynak,MAX,dosya)){
		strcat(x,kaynak);
	}
	printf("Dosyanin ilk hali :\n");
	printf("%s\n",x);	
	boslukKontrol(x,y);
	printf("Tokenizer hali :\n");
	tokenizer(y);
	return 0;
}
