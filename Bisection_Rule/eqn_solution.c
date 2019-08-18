#include <stdio.h>
#include <math.h>

double getFX(double x) {
    return (pow(x, x) +2*x -6);
}

double getInterval() {
    double a = 0;
    while(getFX(a)*getFX(a+1) > 0) {
        a++;
    }
    return a;
}

double printRow(int iter, double a, double b, double fa, double fb, double x, double fx, double fx_old) {
    printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t   %lf\n", iter,a,b,fa,fb,x,fx,fx_old);    
}

double getRoot(double e) {
    double a = getInterval(), b = a+1;
    int iter = 0;
    double fa, fb, x, fx = 0.000, fx_old;

    while(fabs(b-a) > e) {
        iter++;
        fa = getFX(a); fb = getFX(b); x = (a+b)/2; fx = getFX(x);
        printRow(iter, a, b, fa, fb, x, fx, fx_old);
        
        if(fx == 0 || fabs(fx-fx_old) < e) {
            printf("Returning the value: %lf", x);
            return x;
        }
        else if(fx > 0) b = x;
        else a = x;
        fx_old = fx;
    }
    return x;

}

int main() {

    double e;
    int acc;
    printf("Enter required accuracy: ");
    scanf("%d", &acc);
    e =pow(10,-acc); 
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("n \t a \t\t b \t\t f(a) \t\t f(b) \t\t x \t\t f(x) \t\t   f(x_old)\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    double root = getRoot(e);
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("Root of the Equation is: %.3lf\n", root);

    return 0;

}
