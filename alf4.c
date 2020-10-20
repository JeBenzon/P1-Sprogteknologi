#include <stdio.h> 
#include <math.h>

void solveQuadraticEquation (double a, double b, double c);
double diskriminanten (double a, double b, double c); 
double rod1 (double a, double b, double z);
double rod2 (double a, double b, double z);

int main (void)
{
    double a; 
    double b; 
    double c; 

    printf("angiv a, b og c"); 
    scanf("%lf %lf %lf", &a, &b, &c); 

    while (a != 0 && b != 0 && c != 0)
    {
        if ( a != 0)
      solveQuadraticEquation (a, b, c); 
        else 
      printf("a må ikke være 0\n"); 

      printf("angiv a, b og c"); 
      scanf("%lf %lf %lf", &a, &b, &c); 

    }

    return 0;

}

void solveQuadraticEquation(double a, double b, double c)
{
    double d; 
    d = diskriminanten (a, b, c); 

    if (d < 0)
      printf("der er ingen rødder\n"); 
    else if (d == 0)
      printf("der er kun et rod\n", rod1(a, b, c)); 
    else 
      printf("der er to rødder\n", rod1(a, b, c), rod2(a, b, c));

}

double diskriminanten (double a, double b, double c)
{
    return b * b - 4 * a* c;

}

double rod1 (double a, double b, double z)
{
    return (-b + sqrt (z))/(2*a);
}

double rod2 (double a, double b, double z)
{
    return (-b - sqrt(z)/(2*a));

}


//Dette er en kommentar
