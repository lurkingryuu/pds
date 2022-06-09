/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 4A
*/

// Including the header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The main function
int main(){
    // This is a seed for random number function
    srand(time(0));

    // Declaring variables of respective types
    int A[100], n, i, j, total_sum, part1_sum, part2_sum, split_index, min_diff, a,b;

    // Taking the user input for the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Populating array with random numbers in the range [-100,100]
    for ( i = 0; i < n; i++)
        A[i] = rand()%201 -100;

    // Summing up all the elemnts and storing it in total_sum
    total_sum=0;
    for ( i = 0; i < n; i++){
        total_sum += A[i];
    }


    // Tracking the index of the split position
    /*
    The loop is exited when the left split sum is more than right split sum, 
    the split index will be the index of the previous iteration
    The part1_sum is initialized with A[0] so as to prevent the split_index to be -1 in some edge case
    */
    min_diff=10001;
    part1_sum=A[0];
    part2_sum=total_sum-A[0];
    split_index=0;
    for (i = 1; i < n; i++)
    {
        part1_sum += A[i];
        part2_sum -= A[i];

        if (abs(part1_sum-part2_sum)<min_diff){
            split_index=i;
            min_diff=abs(part1_sum-part2_sum);
        }
    }


    // Finding the Two closest elements 
    /*
    Here the min difference is initialized to be 100-(-100), 
    and it is updated if the current difference is less than it, 
    and the numbers are also stored in respective variables
    */
    min_diff=201;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(i==j) continue;
            if(abs(A[i]-A[j])<min_diff){
                a=A[i];
                b=A[j];
                min_diff=abs(a-b);
            }
        }
    }


    // Printing the split position, sum of the first part and the second part and the closest pair in the array A
    printf("Array split position is %d\n",split_index);
    printf("The sums of the left and right subarrays are %d and %d, respectively.\n",part1_sum,part2_sum);
    printf("One closest pair is %d and %d",a,b);
   
    return 0;
}