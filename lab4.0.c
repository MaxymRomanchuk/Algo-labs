#include <stdio.h>

int getk(int a)
{
	int k;
	do
	{
	printf("Input k =");
	scanf("%i",&k);
    }
    while(k>a && k<0);
    return k;
}
int arrshow(int arr[],int k, int a)
{
	int i;
	printf("Array is {");
    for(i = k;i<a;i++)
    {
    	if(arr[i]==1337)
    		continue;
    	else
    		printf("%i,",arr[i]);
	}
	for(i = 0;i<k;i++)
	{
		if(arr[i]==1337)
    		continue;
    	else
    		printf("%i,",arr[i]);
	}
	printf("}\n");
	return k;
}
int sort(int arr[], int a)
{
	int i;
	int pointer;
	int var;
	for(;;)
	{
		pointer = 0;
		for(i = a-1; i>0; i--)
		{
			if(arr[i]%2==0)
			{
				arr[i]=1337;
		    }
			if(arr[i]<arr[i-1])
			{
				var = arr[i - 1];
				arr[i-1] = arr[i];
				arr[i]=var;
				pointer++;
			}
		}
		if(pointer==0)
			break;
	}
	return a;
}
int main(void)
{
	int a;
	printf("How much element in this array?\n");
	scanf("%i",&a);
	int array[a];
	int i;
	for(i = 0; i<a; i++)
	{
		printf("Input array[%i]=", i);
		scanf("%i",&array[i]);
	}
	int k;
	k = getk(a);
	k = arrshow(array,k,a);
	a = sort(array,a);
	k = arrshow(array,k,a);
	return 0;
}
