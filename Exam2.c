// Jonathan Pham
// NID: 
// Exam 2 "Exam2.c"
// COP 3223C Section 0V06, Spring 2021

/* Coding Problems: */
/* 
Coding Problem 1: Use recursion to efficiently evaluate the binomial coefficients:

(𝑛𝑚)=𝑛!𝑚!(𝑛−𝑚)!

As you already noticed, factorials are huge, and if you try to use the formula above, you will get numerical overflow very soon.
There is a better way – a smart formula, which solves the overflow problem:

(𝑛𝑚)=(𝑛−1𝑚)+(𝑛−1𝑚−1).

Develop a recursive function, which computes the binomial coefficients using this formula.

Function’s signature:

unsigned long long int GetBinomialCoeff (unsigned short n, unsigned short m);

Testing Suggestion: Test your function for a real lottery numbers – find the number of possible combinations of picking 5 numbers in a set of 36 (that means n = 36, m = 5).
*/

#include<stdio.h>

unsigned long long int GetBinomialCoeff(unsigned int n , unsigned int m){
   if (m == 0 || m == n) return 1;

return GetBinomialCoeff(n - 1, m - 1) + GetBinomialCoeff(n - 1, m);
}

int main(){
   int n = 49;
   int m = 6;
  
   printf("(10 , 2) : %llu",GetBinomialCoeff(10,2));
   return 0;
}

/* Coding Problem 2: Having an array of non-zero integers, rearrange it to follow the following principle:

Positive integers come first, then negative integers.

In other words, there must be no negative integer followed by a positive one.
The actual order of positive and negative elements in the array is not important. You simply need to put all negative elements first.
IMPORTANT: Your algorithm should not go through the array more than twice.
In fact, a good algorithm would go through the array only once. Think how to make it and get 10 bonus points.
Hint: Swap elements of the array when needed.
NOTE: Reverse Sorting the array will not satisfy the requirements of the problem. This is because the best sorting algorithm (when only comparisons are allowed) performs order 𝑛⋅lg𝑛 operations on the array of 𝑛 elements. This is more than the problem asks you about. And a good algorithm for this problem is easier than sorting algorithms.

Function’s signature:

void PutPositivesFirst(int* arr, unsigned long long int elements_no);

Example:
Input: {-2, 37, 235, -10, 19, -27, 1000}
One of many possible outputs: {37, 235, 19, 1000, -2, -10, -27}.
Another possible output: {1000, 235, 19, 37, -10, -27, -2}
Positive elements come first…

WARNING: Please be careful with boundary cases:

Your array might have only one element;
All elements of the array might be positive (or all negative).
*/

#include <stdio.h>

void PutNegativeFirst(int* arr, unsigned long long int elements_no)
{

   for(unsigned long long int i=0;

/*
Coding Problem 4:In this problem, you need to write a complete program.

Write a program, which allows a user to get n-th Fibonacci number by first preparing an array of first 100 Fibonacci numbers as an external array variable, and then offering the user to enter a number n between 1 and 100 to get the n-th Fibonacci number.
The user should see the following Menu:

Welcome to FIBONACCI NUMBERS Calculator!
Please enter a number N between 1 and 100 to get N-th Fibonacci Number.
Enter 0 to exit the program.

When the user enters N, you simply print Fib[N-1] using the previously filled in array of Fibonacci numbers stored as the external array Fib[] of type unsigned long long int. Then, the Menu is shown again for the next user's input.

When user enters 0, the program terminates.

When user enters a number outside of the range 1...100, the program must show an error message and return to the Menu again.
Recall that the first and second Fibonacci numbers are equal to 1, and then every consecutive Fibonacci number satisfies the relation:

𝐹𝑛=𝐹𝑛−1+𝐹𝑛−2.

WARNING: This formula looks like a recursive relation, and it certainly is. But if you try to use it recursively “on-the-fly” to calculate say 90-th Fibonacci number, it will run very slowly. One way to make this algorithm fast is to use a pre-computed array of those numbers. It is useful, when such calls are often. There is also a clever formula, which uses matrix multiplication technique, and gives 𝐹𝑛 very quickly. But if there are repeated calls for those numbers in a program, then an external array is probably the best solution. This problem is about how to construct and use such an array.
*/

#include<stdio.h>

int main()

{

int N, a=0, b=1, c, i;

int x[100];

x[0] = a;

x[1] = b;

for(i=2;i<=100;i++)

{

      c = a+b;

      x[i] = c;

      a = b;

      b = c;

}

printf("Welcome to FIBONACCI numbers calculator!");

printf("\n Please enter a number N between 1 and 100 to get N-th Fibonacci number");

printf("\n Enter 0 to exit the program");

scanf("%d",&N);

printf("%d",x[N]);

}

/*
Computational Problem 1: Consider the following code:

for (i = 0; i < 1000; i++)
{
   n = n / 2 + i;
   if (n % 3 == 0)
       break;
}

What are values of n and i when the loop terminates if before the loop, n was equal to 17?

Please provide detailed explanations by showing the values of n and i for every iteration of the loop.

Please give detailed explanations in the form:
Iteration 1:
Before the iteration: n = 17, i = 0;
After the iteration: n = 8, i = 1;
Iteration 2:
Before the iteration: n = 8, i = 1;
After the iteration: n = ___, i = ___;
…
*/

/*
Iteration 1:
Before the iteration: n = 17, i = 0;
After the iteration: n = 8, i = 1;

Iteration 2:
Before the iteration: n = 8, i = 1;
After the iteration: n = 5, i = 2;

Iteration 3;
Before the iteration: n = 5, i = 2;
After the iteration: n = 3, i = 3;

Iteration 4:
Before the iteration: n = 4, i = 3;
After the iteration: n = 5, i = 4;

Iteration 5:
Before the iteration: n = 5, i = 4;
After the iteration: n = 6, i = 4;

If the iteration becomes divisible by 3 hence the rule
if n( % 3 == 0) 
then it becomes 0 and it breaks

n = n / 2 + i;
n = 5 / 2 + 4 // C doesn't read decimals
n = 2 + 4 
n = 6

n = n / 2 + i;
n = 6 / 2 + 4;
n = 3 + 4; // After it reads 3 it breaks



*/

/*
Computational Problem 2: Consider the following code:

switch (n % 10)
{
   case 1: x = n;
              break;
   case 3: x = n;
              y = 10;
   case 5: x = n * 2;
              break;
   default: x = 0;
              y = 0;
              break;
}

What will be values of x and y equal to after exiting this switch operator if right before the switch, values of x and y were both equal to -35, and n was one of these:
*/

/*
n before switch
21 

12

15

25

17

173

0
x after switch
21

0

30

50

0

346

0

y after switch
-35

0

-35

-35

0

10

0

*/

/*
Computational Problem 4: Your colleague needs a function that converts a sorted array of integers to reverse sorted, and vice versa. The function has to work with arrays of arbitrary length, and make conversion in-place, that is without a creation of a new array. This is the code your colleague tried to implement:

void ReverseSortingOrder(int arr[])

{

   size_t i = 0, arr_len = sizeof(arr) / sizeof(int);

   int buf = 0;

   for (i = 0; i < arr_len; i++)

   {

       buf = arr[i];

       arr[i] = arr[len-1-i];

       arr[len-1-i] = buf;

   }

}

However, this code failed a series of test cases.

What is wrong with this code? Please explain what is wrong, why it is wrong, and how to fix the code.
*/

/*
1. sizeof(arr)/sizeof(int) cannot be used to calculate an array size 

2. arr_len isn't declared
