#include <stdio.h>
#include <stdlib.h>

void sort(int array[],int lenth) {
	int i, pointer, tmp;
	do {
		pointer=0;
		for(i=1;i<lenth;i++) {
			if(array[i-1]>array[i]) {
				tmp=array[i];
				array[i]=array[i-1];
				array[i-1]=tmp;
				pointer++;
			}
		}
	} while(pointer!=0);
}

typedef struct node {
	int val;
	struct node* next;
} node_a;

void array_show(int array[],int k,int lenth) {
	int i;
	printf("{ ");
	for(i=k;i<lenth;i++) {
		printf("%i ",array[i]);
	}
	for(i=0;i<k;i++) {
		printf("%i ",array[i]);
	}
	printf("}\n");
}
void print_list(node_a * head,int k) {
	int i;
    node_a * current = head;
    for(i=0;i<k;i++) {
    	current = current->next;
	}
    while (current != NULL) {
    	if((current->val)%2==0) {
    		current = current->next;
		}
		else {
        	printf("%d ", current->val);
        	current = current->next;
    	}
    }
    current=head;
    for(i=0;i<k;i++) {
    	if((current->val)%2==0) {
    		current = current->next;
		}
		else {
    		printf("%d ", current->val);
        	current = current->next;
    	}
	}
}


void push(node_a * head, int val) {
    node_a * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node_a));
    current->next->val = val;
    current->next->next = NULL;
}

int main(void) {
	int lenth,i,k,len;
	printf("Type lenth of list: ");
	scanf("%i",&lenth);
	int arr[lenth];
	for(i=0;i<lenth;i++) {
		printf("List #%i: ", i);
		scanf("%i",&arr[i]);
	}
	printf("Type k value: ");
	scanf("%i",&k);
	if(k>lenth) {
		return 0;
	}
	printf("Your list from K element is:\n");
	array_show(arr,k,lenth);
	sort(arr,lenth);
	
	node_a * head = NULL;
    head   = malloc(sizeof(node_a));
	
    head->val = arr[0];
    head->next = NULL;
    for(i=1;i<lenth;i++) {
   		push(head,arr[i]);
	}
	printf("Sorted linked list is:\n{ ");
	print_list(head,k);
	printf("}");
}
