/*
* Program to add numbers inputed through the console
* SoftSys 2020
* Richard Gao
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 5
#define NUMSIZE 10

int stringToInt(char *s, int *num);
int sum(int *a, int size);

int main()
{
    int nums[NUMSIZE];
    char inputBuffer[BUFFERSIZE];
    int count = 0;
    printf("Enter number: ");
    while (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
        // Check if int array is full
        if (count >= NUMSIZE) {
            printf("Number array is full. Please enter EOF character: ");
            continue;
        }

        // Check if user enters someting that exeeds the length of input buffer
        // B/c fgets will include the \n char. If the character length of 
        // the input string - 1 is not \n, then we have exceeded the limit of fgets
        if (inputBuffer[strlen(inputBuffer) - 1] != '\n') {
            printf("Input exceeds length of the input buffer. Please try again: ");

            // Flush the leftover characters in the fgets input buffer
            char c;
            while((c = getchar()) != '\n');
            continue;
        }

        // Convert inputBuffer to proper int
        int num;
        int result = stringToInt(inputBuffer, &num);
        if (result == -1) {
            printf("Can't convert string to integer. Please try again: ");
            continue;
        }

        // Store int into an array
        nums[count] = num;
        count++;

        printf("Enter number: ");
    }
    printf("\n");

    int s = sum(nums, count);
    printf("Total sum is %d", s);
    
    return 0;
}

/* Converts string to int
   
   s: pointer to first element in string to convert
   num: pointer to the integer that we will store result in
*/
int stringToInt(char *s, int *num){
    char *end;
    long lnum = strtol(s, &end, 10);
    if (end == s) {
        return -1;
    }
    *num = (int) lnum;
    return 0;
}   

/* Sums up the elements in an array
   
   a: pointer to first element in int array
   size: size of the array
*/
int sum(int *a, int size) {
    // Add up the numbers in the array
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum;
}