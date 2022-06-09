/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 5
*/

// Including the header files
#include <stdio.h>
#include <math.h>


// print the contents of an integer array x containing n elements
void printarray(int x[], int n) {
    for (int i=0; i<n; i++)
        printf ("%d ", x[i]);
    printf ("\n") ;
}

// This function returns 1 if x is a prime integer and 0 otherwise.
int isprime(int x) {
    int i, is_prime=1;

    // Taking care of edge cases like 1 is not a prime, and primes should be non-zero positives
    if(x<=1) is_prime=0;
    else {
        // The loop runs till i=square root of x, as after that, 
        // the factors will be x/f of some previously determined factor f.
        for (i=2; i<=sqrt(x); i++) {
            if (x%i == 0) {
                is_prime=0;
                break;
            }
        }
    }
    // is_prime will be 1 if x is prime else it will be 0.
    return is_prime;
}

// This function returns 1 if x can be written as the sum of two primes numbers, and 0 otherwise.
int sumoftwoprimes(int x) {
    // The smallest number which can be sum of two primes is 4=2+2, as 2 is the smallest prime.
    if(x<4) return 0;

    // The loop runs till i=x/2, as after that, i and x-i will repeat.
    for (int i = 2; i <= x/2; i++)
    {
        if(isprime(i) && isprime(x-i)) return 1;
    }
    return 0;
}

// This function fills array x with the numbers in the range [a,b] which can be written as the sum of 2 prime numbers.
int arraysum2p(int a, int b, int x[], int size) {
    // This variable keeps track of the number of elements entered in the array x.
    int k=0;
    // Making sure that a<b, by swapping them if a>b.
    if(a>b){
        a=a+b;
        b=a-b;
        a=a-b;
    }

    // Checking for the numbers in the inclusive range of [a,b] which are sum of two primes and adding them to the array.
    for (int i = a; i <= b; i++)
    {
        // Here the sumoftwoprimes function will be called to check if i is sum of 2 primes or not.
        if(sumoftwoprimes(i)) x[k++]=i;
        // Exiting the loop if the array is full even before all such elements are stored.
        if(k>size) return size;
    }
    // Returning the number of such numbers entered into the array x.
    return k;
    
}

// The main function
int main() {
    // Declaring variables of the respective types.
    int a, b, n;
    int X[100];

    // Taking input from the user for a,b.
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);

    // Invoking arraysum2p sunction with the required parameters and storing the size of array X in n.
    n = arraysum2p(a, b, X, 100);

    // Quitting the program if there are no such elements in between a and b.
    if(n==0) {
        printf("There are no numbers in between %d and %d (Both inclusive), which can be expressed as sum of two primes numbers.\n",a,b);
        return -1;
    }

    // Printing the Array X.
    printarray (X, n) ;

    return 0;
}