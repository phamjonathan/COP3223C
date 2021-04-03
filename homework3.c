// Jonathan Pham
// NID: 
// Homework 3 "homework3.c"
// COP 3223C Section 0V06, Spring 2021

#include<stdio.h>
#include<string.h>

unsigned long long CountWords(char *text){

    unsigned long long word_count = 0;

    for(int i = 0; i < strlen(text); i++){
        
        // First character checker if symbol then increase
        if(i == 0 && !(text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == ';' || text[i] == '!' || text[i] == '?'))
            word_count++;

        // Delimiter checker
        if(text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == ';' || text[i] == '!' || text[i] == '?'){

            // Next character checker if symbol then increase
             if(i < strlen(text) - 1 && !(text[i + 1] == ' ' || text[i + 1] == ',' || text[i + 1] == '.' || text[i + 1] == ':' || text[i + 1] == ';' || text[i + 1] == '!' || text[i + 1] == '?')){
                word_count++;
            }
            
        }
    }
    
    return word_count;
}

long long fix_sorted_array(double arr[], size_t arr_size){

    long long outlier_pos = -1;

    // Outlier checker
    for(int i = 0; i < arr_size; i++){

        // Outlier checking if the next element is 'greater' then next
        if(i < arr_size - 1 && arr[i] > arr[i + 1]){
            outlier_pos = i;
            double temp = arr[i];
            // Consolidating rearrangement
            int new_pos = arr_size - 1;
            for(int j = i + 1; j < arr_size - 1; j++){

                // Rearrangement
                if(arr[j] < arr[j + 1]){
                    new_pos = j;
                }
            }

            // Shifting i by 1 place
            for(int k = i + 1; k < new_pos; k++){
                arr[k - 1] = arr[k];
            } 

            // Rearrangement
            arr[new_pos] = temp;
        }
    }

    return outlier_pos;
}


void main(void){

    char text1[] = "This   is a test  text!!!";
    char text2[] = ": ; ???";

    printf("\nText: %s\t\tword_count: ", text1);
    printf("%llu\n", CountWords(text1));
    printf("Text: %s\t\tword_count: ", text2);
    printf("%llu\n", CountWords(text2));

    printf("\nThe array is: ");
    double arr[] = {-17, -5, -5, -2, 1, 17, 289, 17, 17, 395};

    // Original Array & Sorting
    for(int i  = 0; i < 10; i++)
        printf("%.2lf ", arr[i]);

    printf("\nPosition of outlier: %lld\n", fix_sorted_array(arr, 10));
    printf("Array after sorting: ");

    // Assorted Array
    for(int i  = 0; i < 10; i++)
        printf("%.2lf ", arr[i]);
    printf("\n");

    
}