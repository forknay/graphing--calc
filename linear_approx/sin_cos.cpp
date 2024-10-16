#include <stdio.h>
#include <math.h>
float sin_approx(float x, float x_scalar, int degree);
int factorial(int nb);

int main(){
    //printf("%d\n", factorial(7));
    printf("%lf\n", sin_approx(1.3, 1, 13));
    return 0;
}

float sin_approx(float x, float x_scalar, int degree){
    /* Approximates sin function with x-transform by a scalar. Returns value at desired x, centered at 0*/

    int i;
    double increment;
    double value = 0;
    double scaled_x = x * x_scalar;
    double power_term;
    double factorial_term;
    double MAX_DOUBLE = 2000000000;
    int magn_reducer = 1000;
    
    for (i = 0; i <= degree; i++){ //Adds degrees of precision until inputted degree or until precision limit
        power_term = roundf(pow(scaled_x, 2 * i + 1) * 10000) / 10000;
        factorial_term = factorial(2 * i + 1);
        printf("(%lf, %lf ; %d )\n", power_term, factorial_term, 2*i +1);
        increment = (pow(-1, i) * power_term) / factorial_term
            ; // Increment series calculation
        printf("%f\n", increment);
        
        if (factorial_term > MAX_DOUBLE or power_term > MAX_DOUBLE){ //Check for precision
            break;
        } else {
            value += increment;
            printf("%f\n\n", value);
        } 
    }
    return value;
}

int factorial(int nb){
    /* Returns the factorial of an integer */
    if (nb > 0){
        return nb * factorial(nb - 1);
    }
    else {
        return 1;
    }
}