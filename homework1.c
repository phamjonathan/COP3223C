// Jonathan Pham
// NID: 
// Homework 1 "homework1.c"
// COP 3223C Section 0V06, Spring 2021

#include <stdio.h>

// We are creating a function `SumOfDigits` this stores the sum 
unsigned int SumOfDigits(unsigned int n)
{
// Initializing that the sum equals to 0
unsigned int sum=0;
// Loop to add sums of numbers
while(n>0)
{
// n%10 gives the last digit of n, which is then added to the sum
sum = sum + (n%10);
  
// This eliminates the last digit
n=n/10;
}
  
return sum;
}

void PrintDivisors(unsigned int n)
{
// This is classifiying numbers and integers from 1 to n
printf("\nDivisors of %u:",n);
for(unsigned int i=1;i<=n;i++)
{
// % gives remainder. If remainder is 0, then that number is a divsior of n
if(n%i==0)
{
printf("%u,",i);
}
}
}

unsigned long GetBinomialCoefficient(unsigned int n, unsigned int m)
{
unsigned long result, numerator=1, denominator=1;
  
// Calculation of Numerator
for(unsigned int i=n;i>m;i--)
{
numerator = numerator * i;
}
  
// Calculation of Denominator
for(unsigned int i=n-m;i>=1;i--)
{
denominator = denominator * i;
}
  
result = numerator/denominator;
  
return result;
  
}

int main()
{
unsigned int sum;
unsigned long coefficient;
  
// We are making a call action for SumOfDigits
sum = SumOfDigits(17239);
printf("Sum of Digits: %u",sum);
  
// We are making a call action for PrintDivisors
PrintDivisors(3150);
  
// We are making a call action for GetBinomialCoefficient
coefficient = GetBinomialCoefficient(5,2);
printf("\nBinomial Coefficient: %lu",coefficient);
  
   return 0;
}