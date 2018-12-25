 #include<stdio.h>
 #include<math.h>
 #define lenth(x1,y1,x2,y2) \
 (sqrt(pow(x2-x1,2)+pow(y2-y1,2)))
 
 float square(int array[3][2]) {
 	int i,s; float s1;
	s=((array[0][0]*array[1][1]+array[1][0]*array[2][1]+array[2][0]*array[0][1])-((array[0][1]*array[1][0])+(array[1][1]*array[2][0])+(array[2][1]*array[0][0])));
	s1=(float)s/2;
	if(s1<0) {s1 = -s1;}
	return s1;
 }
 
 float squaren(int n,int first,...) {
 	int* p=&first; int array[n][2],i=0,s=0,n1=n; float s1;
 	while(n1!=0) {
 		array[i][0]=*p;p+=2;
 		array[i][1]=*p;p+=2;i++;n1--;
	}
 	for(i=0;i<n;i++) {
 		if(i==n-1) {s+=(array[i][0]*array[0][1]);}
 		else {s+=(array[i][0]*array[i+1][1]);}
	}
	for(i=0;i<n;i++) {
 		if(i==n-1) {s-=array[i][1]*array[0][0];}
 		else {s-=array[i][1]*array[i+1][0];}
	}
 	s1=(float)s/2;
 	if(s1<0) {s1 = -s1;}
 	return s1;
 }
 
 int main(void) {
 	int i,n,len; float s;
 	printf("How many points is there?\n");
 	scanf("%d",&n);
 	int array[n][2];
 	for(i=0;i<n;i++) {
 		printf("Type %d point coordinates: ",i);
 		scanf("%i%i",&array[i][0],&array[i][1]);
	}
 	printf("Your list:\n");
 	for(i=0;i<n;i++) {
 		printf("%i) %i %i\n",i+1,array[i][0],array[i][1]);
	}
	if(n>=3) { s=square(array); printf("Area of the first 3 points is: %.1f\n",s); }
	if(n>=5) { 
		s=squaren(5,array[0][0],array[0][1],array[1][0],array[1][1],array[2][0],array[2][1],array[3][0],array[3][1],array[4][0],array[4][1]);
		printf("Area of pentagon is: %.1f\n",s);
	}
	if(n>=6) {
		s=squaren(6,array[0][0],array[0][1],array[1][0],array[1][1],array[2][0],array[2][1],array[3][0],array[3][1],array[4][0],array[4][1],array[5][0],array[5][1]);
		printf("Area of sextagon is: %.1f\n",s);
	}
	len=lenth(array[0][0],array[0][1],array[1][0],array[1][1]);
	printf("Example lenth = %i",len);
	return 0;
 }
