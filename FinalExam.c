// Jonathan Pham
// NID:
// Final Exam "FinalExam.c"
// COP 3223C Section 0V06, Spring 2021

// A. Conceptual Problems

/* 1. (10 points) What is wrong with the following C function’s code that intends to return the concatenation
of two strings? Choose the single best answer from the choices below. */

#include <string.h>
#include <stdio.h>
// Assuming s1 and s2 are not NULL and valid C strings,
// returns the concatenation of s1 and s2.
// Returns NULL if there are errors.
char *concat(char *s1, char *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        return NULL;
    }
    size_t sz1 = strlen(s1);
    size_t sz2 = strlen(s2);
    if (sz1 + sz2 > 512)
    {
        return NULL;
    }
    char ret[513];
    strcpy(ret, s1);
    strncat(ret, s2, 512 - sz1);
    return ret;
}

/*
A. The call to strncat does not put a null character at the end of the concatenated string in
ret.
B. The return statement returns a pointer to local storage, leading to a dangling pointer. The code
should use malloc to allocate space on the heap.
C. There is potentially not enough space in the array ret to hold the null character at the end.
D. The code is written with return statements on the same line as the if tests, which is bad style.
E. None of the above, the code works correctly
*/

/* Answer: B */

/* 2. (10 points) What is wrong with the following program that has a function swap and intends to use it to
exchange the values stored in two variables? Choose the single best answer from the choices below. */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
// swap the values in variables v1 and v2
void swap(int v1, int v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
int main()
{
    int v1 = 5;
    int v2 = 7;
    swap(v1, v2);
    // the condition in the following assert should be true!
    assert(v1 == 7 && v2 == 5);
    return EXIT_SUCCESS;
}

/*
A. The swap function does not change the values of the variables in main, to do that one would
need to pass pointers to those variables.
B. The testing for swap is not very comprehensive, as only one call is tested.
C. The return value from swap is ignored, so if there are errors, the main function cannot report
them.
D. The main function does not print anything, so one cannot tell if the code works correctly or
not.
E. None of the above, the code works correctly.
*/

/* Answer: A */

// B. Coding Problems

/*
5. (40 points) In C, without using the library functions strcspn or strpbrk, define the function
int FindFirstCharFrom(char* str, char *sought);
The function FindFirstCharFrom takes pointers to two C strings as arguments, str and sought.
It returns the first index, i, into str such that str[i] is a character found in sought. The function
returns -1 if there is no character in str that is one of the characters in sought or if str is the NULL
pointer.
Tests for this problem appear below (in Figure 1).
*/

#include <stdio.h>

int FindFirstCharFrom(char *str, char *sought)
{

    if (str == NULL || sought == NULL)
        return -1;

    int A[256] = {0};

    while (*sought != '\0')
    {
        A[*sought] = 1;
        sought++;
    }
    int i = 0, index = -1;

    while (str[i] != '\0')
    {
        if (A[str[i]] == 1)
        {
            index = i;
            break;
        }
        i++;
    }

    return index;
}

int main()
{
    char str[20];
    scanf("%[^\n]%*c", str);
    char sought[] = " \t\n";
    printf("%d", FindFirstCharFrom(str, sought));
    return 0;
}

/* 
Solution: 
Input = ok 
Output = -1 
*/

/* 
6. (40 points) This is a question about writing two functions, car_equal and FindFirst. These
should have the types specified in the following code from the car.h header file: 
*/

#include <stdbool.h>
#include <stdio.h>
#define COLOR_LEN 29
#define MAKER_LEN 49
#define MODEL_LEN 99
// structure of a car
// invariant: color, maker, and model are proper C strings
typedef struct automobile
{
    unsigned short model_year;
    char color[COLOR_LEN + 1];
    char maker[MAKER_LEN + 1];
    char model[MODEL_LEN + 1];
} car;
_Bool car_equal(car *c1, car *auto2);
int FindFirst(car *autos[], unsigned int autos_no, car *query);

/* The function car_equal takes two pointers to cars (i.e., to struct automobile records) and
returns true just when the two have the same color, maker, and model; that is the function returns true
when the strings that describe this information have the same characters. If there is a difference or if one
of the arguments if NULL, then the function returns false.

The function FindFirst takes an array of pointers to cars, autos, an unsigned int, autos_no, that
tells how many elements are in autos, and a pointer to a car, query. Your code can assume that
query is not NULL. A call to FindFirst should return the least legal index, i, into autos such that
car_equal(autos[i], query) is true. The call returns -1 if there is no such element of autos
that is equal to query.

Your code can use two functions that we provide in Figure 3 on the following page,

car* car_create(char* color, char* maker, char* model);
void car_print(FILE* fp, car* c);

so you do not need to write code for those.

Tests for this problem depend on an array, which we also call autos. Suppose this array is of size 5
and initialized as follows.

autos[0] = car_create("blue", "ford", "pinto");
autos[1] = car_create("white", "chevy", "chevette");
autos[2] = car_create("brown", "Volvo", "boxy");
autos[3] = car_create("red", "Porsche", "911");
autos[4] = car_create("white", "chevy", "chevette");

With that initialization of the array autos, the FindFirst function works as shown in Figure 2.
The code for the two provided functions, car_create and car_print, is given in Figure 3 on the
next page. The car_create function returns a pointer to a newly allocated struct automobile
which is initialized with the given arguments. The car_print function prints a string representation
of the car on the given file, fp. You do not need to write code for these functions and can use them in
your solution */

#include <stdbool.h>
#include <stdio.h>

#define COLOR_LEN 29
#define MAKER_LEN 49
#define MODEL_LEN 99

typedef struct automobile
{
    unsigned short model_year;
    char color[COLOR_LEN + 1];
    char maker[MAKER_LEN + 1];
    char model[MODEL_LEN + 1];
} car;

bool car_equal(car *c1, car *auto2);

int FindFirst(car *autos[], unsigned int autos_no, car *query);

bool car_equal(car *c1, car *auto2)
{
    if (c1->color == NULL || c1->maker == NULL || c1->model == NULL ||
        auto2->color == NULL || auto2->maker == NULL || auto2->model == NULL)
    {
        return false;
    }

    if (strcmp(c1->color, auto2->color) != 0 ||
        strcmp(c1->model, auto2->model) != 0 ||
        strcmp(c1->maker, auto2->maker) != 0)
    {
        return false;
    }

    return true;
}

int FindFirst(car *autos[], unsigned int autos_no, car *query)
{
    for (int i = 0; i < autos_no; i++)
    {
        if (car_equal(autos[i], query) == true)
            return i;
    }
    return -1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_copy(char *dest, char *source, size_t len)
{
    strncpy(dest, source, len);
    dest[len] = '\0';
}

extern car *car_create(char *color, char *maker, char *model)
{
    car *ret = (car *)malloc(sizeof(car));
    if (ret == NULL)
    {
        fprintf(stderr, "Could not allocate space for a car!\n");
        exit(EXIT_FAILURE);
    }
    string_copy(ret->color, color, COLOR_LEN);
    string_copy(ret->maker, maker, MAKER_LEN);
    string_copy(ret->model, model, MODEL_LEN);

    return ret;
}

void car_print(FILE *fp, car *c)
{
    fprintf(fp, "car_create(\"%s\", \"%s\", \"%s\")\n",
            c->color, c->maker, c->model);
}

int main()
{
    car *autos[5];

    autos[0] = car_create("blue", "ford", "pinto");
    autos[1] = car_create("white", "chevy", "chevette");
    autos[2] = car_create("brown", "Volvo", "boxy");
    autos[3] = car_create("red", "Porsche", "911");
    autos[4] = car_create("white", "chevy", "chevette");

    printf("%d\n", FindFirst(autos, 5, car_create("white", "chevy", "chevette")));
    printf("%d\n", FindFirst(autos, 5, car_create("brown", "Volvo", "boxy")));
    printf("%d\n", FindFirst(autos, 5, car_create("blue", "Tesla", "Model S")));
    printf("%d\n", FindFirst(autos, 5, car_create("red", "Porsche", "X")));
    printf("%d\n", FindFirst(autos, 5, car_create("blue", "ford", "pinto")));

    return 0;
}

/* 
Solution:
1
2
-1
-1
0
*/