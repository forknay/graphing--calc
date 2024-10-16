#include <stdio.h>
#include <math.h>
// FUNCTIONS
float sin_approx(float x, float fxn_scalar, float x_scalar, int degree);
float cos_approx(float x, float fxn_scalar, float x_scalar, int degree);
int factorial(int nb);
bool is_even(int nb);

// CONSTANTS
const double PI = 3.14159;


int main(){
    int p;
    for (p = -10; p < 10;p++){
        printf("%lf\n", cos_approx(p, 3, 5, 13));
    }
        return 0;
}

float sin_approx(float x, float fxn_scalar, float x_scalar, int degree){
    /* Approximates sin function with x-transform by a scalar. Returns value at desired x, centered at 0*/

    int i;
    double increment;
    double value = 0;
    double power_term;
    double factorial_term;
    double MAX_DOUBLE = 2000000000;
    int magn_reducer = 1000;
    //operations to simplify x
    double scaled_x = (x * x_scalar) - (floor((x * x_scalar) / (2*PI)) * (2*PI)); // Removes extra revolutions from the fxn
    int nb_halves; //nbs of half revolution
    if (nb_halves = floor(scaled_x / PI)){ //If in positive y-interval, leave as is. If in negative interval (ie: pi-2pi), reverse sign of x
        scaled_x -= PI;
        scaled_x = -scaled_x;
    }
    //printf("%lf\n", floor((x * x_scalar / (2*PI))));

    for (i = 0; i <= degree; i++){ //Adds degrees of precision until inputted degree or until precision limit
        power_term = roundf(pow(scaled_x, 2 * i + 1) * 10000) / 10000;
        factorial_term = factorial(2 * i + 1);
        //printf("(%lf, %lf ; %d )\n", power_term, factorial_term, 2*i +1);
        increment = (pow(-1, i) * power_term) / factorial_term
            ; // Increment series calculation
        //printf("%f\n", increment);
        
        if (factorial_term > MAX_DOUBLE or power_term > MAX_DOUBLE){ //Check for precision
            break;
        } else {
            value += increment;
            //printf("%f\n\n", value);
        } 
    }
    return fxn_scalar * value;
}

float cos_approx(float x, float fxn_scalar, float x_scalar, int degree){
    /* Uses sin approx to approx cos*/
    return sin_approx(x + (PI/(2*x_scalar)), fxn_scalar, x_scalar, degree);
}

int factorial(int nb){ //works
    /* Returns the factorial of an integer */
    if (nb > 0){
        return nb * factorial(nb - 1);
    }
    else {
        return 1;
    }
}

bool is_even(int nb){ //works
    /* Returns 1 if the nb is even*/
    int remainder;
    if (remainder = nb - floor(nb / 2) * 2){
        return false;
    } else {
        return true;
    }
}
