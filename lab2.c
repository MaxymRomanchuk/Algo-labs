#include <stdio.h>
#include <math.h>

float func(int n) /*function for calculation of expression*/
{
  int s;
  float e, x;
  s = sqrt(n); /*squaring of cycle variable*/
  e = expf(1); /*getting an exponent number*/
  x = pow(e,-s);/*powering exponent number*/
  return x;
} 
int main(void) /*function for summing results with all variables*/
{
  float a = 1; 
  int n;
  for(n=1;n<10;n++) /*summing results with all variables*/
  {
     a = a + func(n); 
  }
  printf("Result of summing is %.22f\n", a); /*showing of result (with all characters after comma)*/
  return 0;
}
