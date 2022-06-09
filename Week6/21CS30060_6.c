/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 6
*/

// Including the header files
#include <stdio.h>

// A recursive function to calculate factorial of an integer x
int factorial(int x){
    if(x==0) return 1;
    return x*factorial(x-1);
}

// A recursive function to calculate pds value (sum of factorial of digits of k) of an integer k
int pds(int k){
    if(k==0) return 0;
    return factorial(k%10) + pds(k/10);
}

// A function to check if a number k is a pds number
int is_pds(int k){
    return k==pds(k);
}

// A recursive function to calculate lab value (sum of divisors of n other than n itself) of an integer k
// d here is a number incrementing till initial value of k, this is to track the divisor of k.
int lab(int k, int d) {
    if (k <= 1) return 0;
    if (d >= k) return 0;

    if (k%d == 0) {
        return d + lab(k, d+1);
    }
    return lab(k, d + 1);
}

// A function to check if a number k is a lab number
int is_lab(int k){
    return k==lab(k,1);
}

// A recursive function to print all the pds numbers between 1 to n
void all_pds(int n){
    if(n<1) return;
    all_pds(n-1);
    if(is_pds(n)) printf("%d\n",n);
}

// A recursive function to print all the lab numbers between 1 to n
void all_lab(int n){
    if(n<1) return;
    all_lab(n-1);
    if(is_lab(n)) printf("%d\n",n);
}

// A recursive function to print a n number of starts in a row
void bow_row(int x){
    if(x==0){
        printf("\n");
        return;
    }
    printf("*");
    bow_row(x-1);
}

// A recursive function to print a bow pattern for a number n
void bow(int n){
    if(n==1){
        printf("*\n");
        return;
    }
    bow_row(n);
    bow(n-1);
    bow_row(n);
}


// The main function
int main(){
    // Declaring variables of required type
    int n;

    // Taking user input for integer n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Printing all the PDS numbers in between 1 and n
    printf("\nThe PDS Numbers between 1 and %d are:\n",n);
    all_pds(n);

    // Printing all the LAB numbers in between 1 and n
    printf("The LAB Numbers between 1 and %d are:\n",n);
    all_lab(n);

    // If n is both pds number and lab number, we print its bow pattern
    if(is_pds(n) && is_lab(n)){
        bow(n);
    }
    
    return 0;
}