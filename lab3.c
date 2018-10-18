#include <stdio.h>
#include <math.h>

float expr1(float a, float n)
{
 float x;
 x = (pow(-1, n)*pow(1+a,2*n))/n;
 return x;
} 

float expr2(float a)
{
 float x = log(1/(2+2*a+pow(a,2)));
 return x;
}

int main(void)
{
 float a = -2;
 float b = -0.1;
 float n = 40;
 float e = 0.0001;
 float k=(b-a)/10;
 for(float x = a; x <= b; x += k)
 {
  float SN = 0;
  for(int count = 1; count <= n; count++)
  {
   SN += expr1(x,count);
  }
  float SE = 0;
  int count1 = 1;
  while(fabs(expr1(x,count1))>=e)
  {
   SE += expr1(x,count1);
   count1++;
  }
  
  float y = expr2(x);
  printf("X=%f, SN=%f, SE=%f, Y=%f\n",x, SN, SE, y);
 }
}
