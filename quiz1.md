### Jonathan Pham
### NID: 
### Quiz 1 "quiz1.md"
### COP 3223C Section 0V06, Spring 2021

# Quiz 1
    Your colleague developed a function, which is supposed to reverse an array of integers, e.g., {1, 5, -10, 7, 23} => {23, 7, -10, 5, 1}.

    Test cases show that the function does not work correctly. Please look at the following code and identify all the troubles.

    Please specify which part(s) of the code will not work and explain why not.
---

    void ReverseArray(int arr[], size_t elements_no)

    {

      size_t i = 0;

       int x = 0;

       for (i = 0; i <= elements_no; i++)

      {

           x = arr[i];

           arr[i] = arr[elements_no - i];

           arr[elements_no - i] = x;
    
       }

    }
---
    main.c:1:30: error: unknown type name ‘size_t’
     void ReverseArray(int arr[], size_t elements_no)
                              ^~~~~~

When ran this is the message shown in the console.

Knowing as an implication, size_t is a type guaranteed to hold any array index. 
The naming convention is personally confusing for me ex: 
elements_no could be elements_size 

    for (i = 0; i <= elements_no; i++)
    The iteration is wrong it should be
    for(i=0; i<elements_no/2; i++)
---
    arr[i] = arr[elements_no - i];
    arr[elements_no - i] = x;

    This is wrong as it has to have a decrement in order for the array index to work
    it should be

    arr[i] = arr[elements_no -1 - i];
    arr[elements_no -1 - i] = x;
