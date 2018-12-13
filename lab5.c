#include <stdio.h>

int getsize(void) {
	int size;
	printf("Type size of array (size*size): ");
	scanf("%i",&size);
	return size;
}

int do_everything_else(int size) {
	int arr[size][size], i, j, max_value=0, amount=0;
	for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
			printf("Array [%i][%i] = ",i,j);
			scanf("%i",&arr[i][j]);
		}
	}
	for(i=0;i<size;i++) {
		if(arr[i][i]>max_value) {
			max_value = arr[i][i];
		}
	}
	for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
			if(i!=j && arr[i][j]>max_value) {
				amount++;
			}
		}
	}
	for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
			printf("%i ",arr[i][j]);
		}
		printf(" \n");
	}
	return amount;
}

int main(void)
{
	int size,result;
	size = getsize();
	result = do_everything_else(size);
	printf("Amount of numbers in the array, greater than those fron main diagonal is: %i", result);
	
}
