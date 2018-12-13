#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int read_line(FILE *file,char string[255]) {
	int lenth,j;
	for(j=0;j<255;j++) {
		if(string[j]=='\n' || string[j]=='\0') {
			lenth=j;
			break;
		}
		else if(j==254) {
			return 1;
		}
	}
	return lenth;
}

int write_pairs(FILE *f1, FILE *f2,char string[255],int lenth, int index[2]) {
	int j,k,m,l;
	int indexer=0,as=0;
	int start=0,start1;
	int finish,finish1;
	int amount=0;
	char compareable[20],compared[20];
	for(j=0;j<lenth;j++) {
		if(!isalpha(string[j]) && (j-start)>1) {
			finish=j;
			indexer++;
			for(k=start,l=0;k<finish;k++,l++){
				compareable[l]=string[k];
				if(compareable[l]=='a'|| compareable[l]=='A') {
					as++;
				}
			}
			start=finish;
			do{
				start++;
			} while(!isalpha(string[start]) && start<lenth);
			if(start==lenth) {
				break;
			}
			if(as>index[1]) {
				index[0]=indexer;
				index[1]=as;
			}
			as=0;
			start1=start;
			for(m=start1;m<lenth;m++) {
				if(!isalpha(string[m]) && (m-start1)>1) {
					finish1=m;
					for(k=start1,l=0;k<finish1;k++,l++){
						compared[l]=string[k];
					}
					if(strcmp(compareable,compared)==0) {
						amount++;
					}
					memset(&compared[0],0,sizeof(compared));
					start1=finish1;
					do{
						start1++;
					} while(!isalpha(string[start1]) && start1<lenth);
					if(start1==lenth) {
						break;
					}
				}			
			}
			memset(&compareable[0],0,sizeof(compareable));
		}
		memset(&compareable[0],0,sizeof(compareable));
	}
	if(amount>0 && amount<3) {
			fputs(string,f2);
			amount=0;
	}
	return 0;
}

int main(void) {
	int lenth,index[2]={0,0},true_index=0;
	char string[255];
	FILE *f1, *f2;
	f1 = fopen("fignya.txt","r");
	f2 = fopen("fignya_result.txt","w");
	while(fgets(string,255,f1)!=NULL){
		lenth=read_line(f1,string);
		write_pairs(f1,f2,string,lenth,index);
		if(index>true_index) { true_index=index;}
	}
	printf("File rewritten successfully!!\nIndex of the word with the biggest amount of A`s: %i",index[0]-1);
	fclose(f1);
	fclose(f2);
}
