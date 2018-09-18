#include <stdio.h>
#include <math.h>

int main(void)
{
  { /*Exercise 1: Calculation of the same formula with different types of variables.
      Part 1: float type calculation.*/
   float pt1, pt2, n;
   float b = 1000.0;
   float a = 0.0001;
   float ab4 = pow(a - b,4);
   float a4 = pow(a,4), a3 = pow(a,3), a2 = pow(a,2);
   float b4 = pow(b,4), b3 = pow(b,3), b2 = pow(b,2);
   pt1 = (ab4 - (a4 - 4*a3*b + 6*a2*b2));
   pt2 = (b4 - 4*a*b3);
   n = pt1 / pt2;
   printf("1)float=%f\n", n);
  }

  { /*Part 2: double type calculation.*/
   double p1, p2, m;
   double b = 1000.0;
   double a = 0.0001; 
   float ab4 = pow(a - b,4);
   double a4 = pow(a,4), a3 = pow(a,3), a2 = pow(a,2);
   double b4 = pow(b,4), b3 = pow(b,3), b2 = pow(b,2);
   p1 = (ab4 - (a4 - 4*a3*b + 6*a2*b2));
   p2 = (b4 - 4*a*b3); 
   m = p1 / p2;
   printf("2)double=%.51f\n", m);
  }

  { /*Exercise 2: Operators.Decrements and Increments. Comparing operators.*/
   int m, n, r1, r2, r3, z;
   /*Step 1: Reading arguments*/
   printf("Please, write first number(n):"); 
   scanf("%i", &n);
   printf("Ok, write another one(m):");
   scanf("%i", &m);
   /*Step 2: Calculation*/
   r1 = n++*m;   
   n--;
   r2 = n++<m;
   z = m;
   r3 = m-- >z;
   printf("2.1) n++*m=%i\n",r1);
   /*Step 3: Showing results (2.2 and 2.3 are boolean expressions, so they can only be true(1) or false(0))*/
   if(r2 == 1) 
    {
     if(r3 == 1)
     {
	 printf("2.2) n++<m=true\n");
	 printf("2.3) m-->m=true\n");
     }
     else
     {
     printf("2.2) n++<m=true\n");
	 printf("2.3) m-->m=false\n");
	 }
    }
   else if(r3 == 1)
    {
    printf("2.2) n++<m=false\n");
    printf("2.3) m-->m=true\n");
    }
   else
    {
    printf("2.2) n++<m=false\n");
    printf("2.3) m-->m=false\n");
    }
  }
}
