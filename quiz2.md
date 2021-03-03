### Jonathan Pham
### NID: 
### Quiz 2 "quiz2.md"
### COP 3223C Section 0V06, Spring 2021

# Quiz 2
    You need a variable that stores the number of successful attempts for some operations to share across multiple functions.

    For this purpose, you collected definitions of all of them in one file, and created external variable attempts_no as below.

    Another function, which must have access to this variable is main() located in another file of your project.

    What did you do wrong, and how to fix the problem? Please provide a detailed explanation and a change in the code that would fix the problem.

    #include <stdlib.h>

    #include <string.h>

    extern int attempts_no = 0;   // External Variable storing the number of successful attempts of doing things in the functions below

    ...

    void CheckCompositionOperation(...)

    {

       ...

       if(...)

       attempts_no++;

       ...

    }

    void CheckDistributionOperation(...)

    {

       ...

       if(...)

           attempts_no++;

       ...

    }

This below is the problem.

    extern int attempts_no = 0;  

When assigning a value to an external variable such as 0 and having it correlate with main() then attempts_no should be classified globally in order to work. 

In order to correct this we would use:

    int attempts_no=0;

Now within our main function file we need to state:

    extern int attempts_no

This now imports our variable value 

