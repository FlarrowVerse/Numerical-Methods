#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
    return (x*x - 4*x - 7);
}

double fDash(double x) {
    return (2*x - 4);
}

double getRoot(double acc) {
    double x0 = 0, x1 = x0, x1_old = x0+1;

    while(f(x0)*f(x0+1) > 0) {
        x0++;
    }

    int n = 0;
    printf("---------------------------------------------------------------------------------------------\n");
    printf("Iter. \t\t x0(Previous) \t\t x1(Next x) \t\t x1(Older) \n");
    printf("---------------------------------------------------------------------------------------------\n");
    //printf("The root lies near %lf\n\n", x0);
    while(fabs(x1 - x1_old) > acc) {
        x1_old = x1;
        x1 = x0 - (f(x0) / fDash(x0));
        n++;
        printf("%d \t\t %lf \t\t %lf \t\t %lf \n", n, x0, x1, x1_old);
        x0 = x1;
    }
    printf("---------------------------------------------------------------------------------------------\n");
    return x1;
}

int main() {
    int acc;
    printf("Enter the required accuracy: ");
    scanf("%d", &acc);
    double root = getRoot(pow(10, -acc));
    printf("Root of the equation is: %.4lf\n", root);

    return 0;
}