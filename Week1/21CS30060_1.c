/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 1
*/

// Including the header file which contains the I/O functionality
#include <stdio.h>

// Including the math library
#include <math.h>

// The main function
int main(){

    // Initializing variables of respective data types.
    int a, b, z;
    char s, t;
    double y;

    // 1. Taking the input from the user for the first 2 digits in the roll number and storing in variable a.
    printf("Enter the first 2 digits of your roll number: ");
    scanf("%d", &a);
    
    // 2. Taking the user input for the next 2 characters and storing in variables s, t.
    printf("Enter the next 2 characters of your roll number (space seperated): ");
    scanf(" %c %c", &s, &t);

    // 3. Taking the user input for the last 5 digits in a roll number and storing it in variable b.
    printf("Enter the last 5 digits of your roll number: ");
    scanf("%d", &b);

    // 4. Printing values of variables a, s, t, b, in a specific format.
    printf("Hello %d%c%c%d\n", a, s, t, b);

    // 5. Computing the expression
    y = 1.234*pow(10, 5) + 7.5*pow(10, -3) + b; // use of pow function to calculate the 10^5, 10^-3 parts.

    // 6. Printing the value of variable y.
    printf("y = %lf\n", y);

    // 7.  Computing the expression and storing it in a variable z.
    z = a++ + --b + b--;

    // 8. Printing the values of variables a, b and z after the computation.
    printf("a=%d, b=%d, z=%d\n", a, b, z);

    // End of the program.
    return 0;
}
