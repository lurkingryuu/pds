/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 2C
*/

// Including required header files.
#include <stdio.h>
#include <math.h>

// The main function
int main(){
    // declaring variables.
    int a, b, i, count=0, j, is_prime;

    // Reading the user input for the integers a and b.
    printf("Enter a and b(space seperated): ");
    scanf("%d%d", &a, &b);

    // Looping through each integer between a and b, including both a,b.
    for (i=a; i<=b; i++) {
        // Edge case of 1 not being a prime.
        if (i<=1) 
            continue;
                
        // is_prime variable is a flag to keep track of the integer being prime. 
        is_prime=1;
        
        // nested for loop for checking the integer is prime or not.
        for (j=2; j<=sqrt(i); j++) {
            if (i%j == 0) {
                is_prime=0;
                break;
            }
        }

        // if the integer is prime, incrementing the count, and printing the prime integers..
        if (is_prime){
            count++;
            printf("%d\n",i);
        }
    }

    // Printing the total number of primes.
    printf("The total number of primes between %d and %d is %d\n",a, b, count);

    return 0;
}