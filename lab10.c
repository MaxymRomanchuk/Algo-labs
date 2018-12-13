#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int n,k,i;
	printf("Enter amount of strings: ");
	scanf("%d", &n);
	char **arr;
	char buffer[255];
	arr=(char**)malloc(n*sizeof(char*));
	if(arr==NULL) {
		printf("Error when array creating!");
		return 1;
	}
	for(i=0; i<=n; i++) {
		fgets(buffer, 256, stdin);
		if(buffer[strlen(buffer)-1]=='\n') {
			buffer[strlen(buffer)-1]='\0'; 
		}
		arr[i]=(char*)malloc(strlen(buffer)*sizeof(char));
		strcpy(arr[i], buffer);
	}
	printf("\n");
	for (i = 1; i <= n; i++) {
		printf("Your string #%d is: %s", i, arr[i]);
		printf("\n");
	}
	printf("Type K:");
	scanf("%i",&k);
	printf("\nStrings after program execution:\n");
	for(i=k; i<=n; i++) {
		printf("%s\n", arr[i]);
	}
	return 0;
}
