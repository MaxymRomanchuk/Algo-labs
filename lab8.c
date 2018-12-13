#include <stdio.h>
#include <string.h>

typedef struct{
	char lastname[20];
	char firstname[20];
	char fathername[20];
    char phonenumber[20];
    int group;
    int mainmarks[3];
}Student;
	
void show_my_file(int size,Student array[size]){
	FILE *f;
	int i=0;
	f = fopen("fignya.txt","r");
	while(!feof(f)&&i<size) {
 		fread(&array[i], sizeof(Student),1,f);
		i++;
	}
	printf("Results list:\n");
	for(i=0;i<size;i++) {
		printf("%i) %s %s %s \nPhone number: %s  Group: %i\n Marks: %i, %i, %i.\n",i+1,array[i].lastname,array[i].firstname,array[i].fathername,array[i].phonenumber,array[i].group,array[i].mainmarks[0],array[i].mainmarks[1],array[i].mainmarks[2]);
	}
	fclose(f);
}
	
int read_my_file(int Groupsize,Student autist){
	int i, j;
	FILE *f;
	f = fopen("fignya.txt","w");
	if (f == NULL) {
    	fprintf(stderr, "\nError open file\n"); 
       	return 1; 
    } 
   	for(i = 0; i < Groupsize;i++){
   		printf("Enter lastname of %d student:", i+1);
   		scanf("%s", &autist.lastname);
   		printf("Enter firstname of %d student:", i+1);
		scanf("%s", &autist.firstname);
   		printf("Enter fathername of %d student:", i+1);
   		scanf("%s", &autist.fathername);
   		printf("Enter phonenumber of %d student:", i+1);
   		scanf("%s", &autist.phonenumber);
    	printf("Enter group of %d student:", i+1);
   		scanf("%d", &autist.group);
   		printf("Enter mainmarks of %d student:\n", i+1);
   		for(j = 0; j < 3; j++){
   			printf("Enter %d mark:",j+1);
			scanf("%d", &autist.mainmarks[j]);
		}
		fwrite(&autist, sizeof(Student),1, f);
		if(fwrite != 0) 
       		printf("Student data saved successfully !\n");
   		else {
       	printf("error writing file !\n"); 
       	return 1;
       	}
       	
	}
   	fclose (f);
   	return 0;
}

int addition_and_rewrite(int size, Student array[size],char lastname[20],int group, int average) {
	FILE *f;
	int i=0,breakpoint=-1, newsize=0;
	f = fopen("fignya.txt","w");
	while(!feof(f)&&i<size) {
 		fread(&array[i], sizeof(Student),1,f);
		i++;
	}
	for(i=0;i<size;i++) {
		if(array[i].group==group) {
			printf("Matching data, extra student deleted (1 option)! \n");
			continue;
		}
		else if((array[i].mainmarks[0] + array[i].mainmarks[1] + array[i].mainmarks[2]) < (3*average)) {
			printf("Matching data, extra student deleted! (2 option) %i + %i + %i / 3 < %i\n",array[i].mainmarks[0],array[i].mainmarks[1],array[i].mainmarks[2],average);
			continue;
		}
		fwrite(&array[i], sizeof(Student),1, f);
		newsize++;
		if(fwrite == 0)
			return 1;
		if(strcmp(array[i].lastname,lastname)==0) {
			breakpoint=i;
			break;
		}
	}
	if(breakpoint!=-1) {
   		printf("Enter firstname of added student:");
		scanf("%s", &array[size].firstname);
  		printf("Enter fathername of added student:");
		scanf("%s", &array[size].fathername);
  		printf("Enter phonenumber of added student:");
 		scanf("%s", &array[size].phonenumber);
   		printf("Enter group of added student:");
   		scanf("%d", &array[size].group);
		printf("Enter mainmarks of added student:\n");
   		for(i = 0; i < 3; i++){
			printf("Enter %d mark:",i+1);
			scanf("%d", &array[size].mainmarks[i]);
		}
		fwrite(&array[size], sizeof(Student),1,f);
		newsize++;
		for(i=breakpoint+1;i<size;i++) {
			if(array[i].group==group) {
				printf("Matching data, extra student deleted (1 option)! \n");
				continue;
			}
			else if((array[i].mainmarks[0] + array[i].mainmarks[1] + array[i].mainmarks[2]) < (3*average)) {
				printf("Matching data, extra student deleted! (2 option) %i + %i + %i / 3 < %i\n",array[i].mainmarks[0],array[i].mainmarks[1],array[i].mainmarks[2],average);
				continue;
			}
			fwrite(&array[i], sizeof(Student),1,f);
			newsize++;
		}
	}
	fclose(f);
	return newsize;
}

int main(void) {
	int size,group,average,modsize;
	char lastname[20];
	printf("Type amount of students: ");
	scanf("%i",&size);
	Student array[size+1];
	Student autist;
	read_my_file(size,autist);
	show_my_file(size,array);
	printf("Type unwanted group number: ");
	scanf("%i",&group);
	printf("Type unwanted average mark: ");
	scanf("%i",&average);
	
	printf("Type the lastname of student, after which to add a new student: ");
	scanf("%s",&lastname);
	strcpy(array[size].lastname,lastname);
	modsize=addition_and_rewrite(size,array,lastname,group,average);
	show_my_file(modsize,array);
}

