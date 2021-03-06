// Jonathan Pham
// NID: 
// Homework 2 "homework2.c"
// COP 3223C Section 0V06, Spring 2021

#include <stdio.h>
#include <stdlib.h>
_Bool IsDecimalInteger(char str[]){
        // Declaring our traverse for our loop
        int i=0;
        // Setting a rule if it begins with a negative sign, it bypasses 
        if(str[0]=='-'){
                i++;
        }
        // Setting a rule if it doesn't end with an integer we return 0
        if(str[0]=='\0')
                return 0;
        // Setting a check condition to see if there is a integer
        while(str[i]!='\0'){
                if(str[i]<'0'||str[i]>'9'){
                        return 0;
                }
                i++;
        }
        return 1;
}

char GetSortingOrder(double arr[], size_t arr_size){
        if(arr_size==0)
                return -1;
        if(arr_size==1)
                return 3;
        // Classifying our 3 cases constant, sorted, and reverse sorted. Now we must validate.
        int is_constant=1;
        int is_sorted=1;
        int is_reverse_sorted=1;
        // Loop array case scenario 
        for(int i=1;i<arr_size;i++){
                // Checking if it's a constant array
                // If it is a constant array then all elements must be equal
                if(is_constant && arr[i]!=arr[i-1]){
                        is_constant=0;
                }
                // Checking if it's a sorted array then dont check
                // If it is a sorted array then all elements must be greater than or equal to their preceding element
                if(is_sorted && arr[i]<arr[i-1]){
                        is_sorted=0;
                }
                // Checking if it's a reverse sorted
                // If it is a reverse sorted array then all elements must be less than or equal to their preceding element
                if(is_reverse_sorted && arr[i]>arr[i-1]){
                        is_reverse_sorted=0;
                }
                // Checking if it satisfies one of the above clauses 
                if(!is_constant && !is_sorted && !is_reverse_sorted)
                        break;
        }
        if(is_constant){
                return 3;
        }else if(is_sorted){
                return 1;
        }else if(is_reverse_sorted){
                return 2;
        }else{
                return 0;
        }
}

void RemoveExtraSpaces(char txt[]){
        int i, x;
        for(i=x=0; txt[i]; i++)
        // If the preceding character is not a space or next then add next character
    if(txt[i] != ' ' || (i > 0 && txt[i-1] != ' '))
      txt[x++] = txt[i];
        
        if(x-1>0&&txt[x-1]==' '){
                txt[x-1]='\0';
        }else{
                txt[x] = '\0';
        }
}
int main()
{
        // IsDecimalInteger function 
        printf("IsDecimalInteger(\"100000\") = %d\n", IsDecimalInteger("100000"));
        printf("IsDecimalInteger(\" -1000\") = %d\n", IsDecimalInteger(" -1000"));
        printf("IsDecimalInteger(\"-1000\") = %d\n", IsDecimalInteger("-1000"));
        printf("IsDecimalInteger(\"10g10\") = %d\n", IsDecimalInteger("25g17"));
        printf("IsDecimalInteger(\"100-50\") = %d\n", IsDecimalInteger("100-50"));
        printf("IsDecimalInteger(\"\") = %d\n", IsDecimalInteger(""));
        printf("IsDecimalInteger(\"10000\") = %d\n", IsDecimalInteger("100"));
        printf("IsDecimalInteger(\"100.5\") = %d\n\n", IsDecimalInteger("100.5"));

        // GetSortingOrder function 
        double arr1 [] = {-100, -10, -10, -1, 1, 10, 10, 100, 1000};
        printf("GetSortingOrder({-100, -10, -10, -1, 1, 10, 10, 100, 1000}, 3) = %d\n", GetSortingOrder(arr1, 3));
        double arr2 [] = {365, 364, 363, 362, 361, 360, -1, -2, -3};
        printf("GetSortingOrder({365, 364, 363, 362, 361, 360, -1, -2, -3}, 3) = %d\n", GetSortingOrder(arr2, 3));
        double arr3 [] = {25, 25, 25, 25, 25,};
        printf("GetSortingOrder({25, 25, 25, 25, 25}, 5) = %d\n", GetSortingOrder(arr3, 5));
        double arr4 [] = {-17, -5, 10, 2, -19, 23};
        printf("GetSortingOrder({-50, -100, 0, 50, 100, 150}, 6) = %d\n", GetSortingOrder(arr4, 6));
        double arr5 [] = {};
        printf("GetSortingOrder({}, 0) = %d\n\n", GetSortingOrder(arr5, 0));

        // RemoveExtraSpaces function 
        char str1[] =  "   Hi,   my name is Jonathan Pham  !  ";
        RemoveExtraSpaces(str1);
        printf("RemoveExtraSpaces(\"   Hi,   my name is Jonathan Pham  !  \") = \"%s\"\n", str1);
        
        char str2[] =  "";
        RemoveExtraSpaces(str2);
        printf("RemoveExtraSpaces(\"\") = \"%s\"\n", str2);
        
        char str3[] =  "  ";
        RemoveExtraSpaces(str3);
        printf("RemoveExtraSpaces(\"  \") = \"%s\"\n", str3);
}