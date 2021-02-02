// Jonathan Pham
// NID: 
// Homework 1 "homework1.c"
// COP 3223C Section 0V06, Spring 2021

#include <stdio.h>

// We are creating a function `SumOfDigits` this stores the sum 
unsigned int SumOfDigits(unsigned int n)
{
    // Initializing that the sum equals to 0
    unsigned int sum = 0;

    // Loop to add sums of numbers
    while ( n > 0 )
{
        // n%10 gives the last digit of n, which is then added to the sum
        sum = sum + (n%10);
    
        // This eliminates the last digit
        n = n / 10;
}
return sum;
}

void PrintDivisors(unsigned int n)

