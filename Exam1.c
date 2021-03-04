// Jonathan Pham
// NID: 
// Exam 1 "Exam1.c"
// COP 3223C Section 0V06, Spring 2021

/* Coding Problems: */

/* 
3. Write a function that takes `non-negative integer numbers` and checks if one
of them is a (positive integer) power of the other one. It returns 1 if it is, and 0 otherwise.

Example: 2 and 8: 8 = 2^3, and the function returns 1
3 and 10: none of them is a power to another one, and the function returns 0;

49 and 7: 49 = 7^2, and the function returns 1.

0 and 25: Function returns 0.

0 and 0: Function returns 1.

    _Bool IsPowerOf(unsigned int x, unsigned int y); 

Please refer to README.md for a screenshot of the output
*/

#include <stdio.h>
#include <stdbool.h>

bool IsPowerOf(unsigned int x, unsigned int y);

int main() {
    printf("%d\n", IsPowerOf(2, 8));
    printf("%d\n", IsPowerOf(3, 10));
    printf("%d\n", IsPowerOf(49, 7));
    printf("%d\n", IsPowerOf(0, 25));
    printf("%d\n", IsPowerOf(0, 0));
    return 0;
}

bool IsPowerOf(unsigned int x, unsigned int y) {
    if (x > y) {
        unsigned int temp = x;
        x = y;
        y = temp;
    }
    if (x == 0) {
        return y == 0;
    } else if (y == 1) {
        return true;
    } else {
        unsigned int p = 1;
        while (p < y) {
            p *= x;
        }
        return p == y;
    }
}

/* 
4. Write a function that prints out the solution of a linear equation
ax + b = 0
Parameters 'a' and 'b' are parameters (of type double) of the function. 
The output should be in a form like this one:

The solution is x = 235.17.

Please keep in mind that depending on the actual parameters 'a' and 'b', the equation might have no solution, or infinitely many solutions.
You have to provide adequate output for any possible set of the parameters supplied to the function.
The function does not return a value, but prints out the solution, instead. This is the function's declaration:

void SolveLinearEquation(double a, double b); 

Please refer to README.md for a screenshot of the output
*/

#include <stdio.h>
void SolveLinearEquation(double a,double b);
int main()
{
   double a, b;
    printf("Enter a and b: ");
    scanf("%lf%lf", &a, &b);
SolveLinearEquation(a,b);
  

    return 0;
}

void SolveLinearEquation(double a,double b)
{
    if(a == 0) {
        if(b == 0) {
            printf("Infinite Solutions\n");
        } else {
            printf("No solution\n");
        }


    } else {
        printf("Result: x = %.2f\n", -b/a); 
    }

}

/* Computational Problems: */

/*
5. In your own words, describe what the following function does, and `find a serious error` in its code.
Please explain.
*/
Void ClimsyFunction(unsigned int n)
{
    unsigned int i = 0; 
    double arr[n];
    for (i = 0; i < n; i++)
    {
        if ( i % 2 == 0 )
            arr[i] = 0;
        else
            arr[i] = 1/i;
        printf("Element with index %d is: %.10f", i, arr[i]);
    }
}
/* 
The function above creates a double array of size `n` passed as a parameter to the function
It loops in order to fill the array of elements with values.

i = 0 so 0 % 2 == 0 condition is true
i = 1 so 0 % 2 == 0 condition is false

The error is
is arr[i] = 1/i
To correct this it could be 
arr[i] = (double)/i; or arr[i] = 1.0/i

By doing a double-precision floating point division format it helps print
the array value with decimals.
*/

/*
6. In the following code:
*/

int x = 25, y = 7;

double res = 10.29 + x/y;

/*
6.1. What is the actual value of res after all? Please explain.
When you're doing integer division in C the operator rounds down
we have to specifically state the integer as a double to get the decimal if not we
are left with this output:
= 10.29 + 25/7
= 10.29 + 3
= 13.29 

6.2. What has to be true (mathematical) value of res?
It has to be true by following the PEMDAS rule.
Plugging in X & Y into the equation to get the following:
= 10.29 + 25/7
= 10.29 + 3.571428571 (I used a TI-84 calculator)
= 13.86142857

6.3. How to change the code to make res storing the actual mathematically correct (of course,
reasonably approximated) value?
 
The two things I can think of is if we want it to print with a well rounded number to a certain decimal point
We can do C round() function it'll return the nearest integer value of the float/double 
".1 to .5" would return integer lesser value
".6 to .9" would return integer greater value
OR 
after we explicitly casted an integer as a double. 
= a/(double)b;
*/