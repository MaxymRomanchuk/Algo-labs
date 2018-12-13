#include <stdio.h>
#include <ctype.h>

int main(void) {
	char string[256];
	int i,j,start=0,finish,number,counter;
	gets(string);
	if(string==NULL) {
		return 1;
	}
	for(i=0;;i++) {
		if(isdigit(string[i])) {
			counter++;
		}
		if(isspace(string[i+1])&&counter==1) {
			finish=i;
			for(j=start;j<=finish;j++) {
				printf("%c",string[j]);
			}
			printf(",");
			start = i+1;
			while(isspace(string[start])) {
				start++;
			}
			counter=0;
		}
		else if(isspace(string[i+1])) {
			start = i+1;
			while(isspace(string[start])) {
				start++;
			}
			counter=0;
		}
		if(&string[i]==".") {
			break;
		}
	} 
	return 0;
}
