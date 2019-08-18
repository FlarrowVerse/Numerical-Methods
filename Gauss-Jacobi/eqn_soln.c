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

void inputEqn(double e[], int n, int iter) {
    printf("Equation No. %d::\n", iter);
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter coefficient for x(%d): ", (i+1));
        scanf("%lf", &e[i]);
    }
    
    printf("Enter constant for eqaution: ");
    scanf("%lf", &e[n]);
}

void displaySystem(int row, int col, double sys[][col]) {
    int i,j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%lf*x(%d) ", sys[i][j], j+1);
            if(j == col-1) printf("= ");
            else printf("+ ");
        }
        printf("%d, %d\n", i,j);
        printf("%lf\n", sys[i][j]);
    }

}

void inputSystem(int row, int col, double sys[][col]) {
    printf("System of Linear Equations::\n\n");
    int i, j;
    for(i = 0; i < row; i++) {
        inputEqn(sys[i], col, i+1);
    }

    displaySystem(row, col, sys);
}

int main() {
    int acc;
    printf("Enter the required accuracy: ");
    scanf("%d", &acc);
    /**double root = getRoot(pow(10, -acc));
    printf("Root of the equation is: %.4lf\n", root);*/
    double sys[3][4];
    inputSystem(3,3,sys);

    return 0;
}