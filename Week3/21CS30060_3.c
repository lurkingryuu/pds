/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 3
*/

// Including the header files
#include <stdio.h>
#include <math.h>

// The main function
int main(){
    // Declaring variables of suitable types
    int n, i, j, k, x, factorial_sum, factorial, factor_sum, digit;

    // 1. Taking the user input for the number n
    printf("Enter the number n: ");
    scanf("%d", &n);

    // 2. Checking the PDS numbers, and printing them
    printf("The PDS numbers between 1 and %d are: \n",n);
    for (i = 1; i <=n; i++)
    {
        x = i;
        // factorial_sum is used to keep track of the sum of the factorial of each digit of the number
        factorial_sum=0;
        while(x%10>0){
            digit = x%10;

            // factorial variable stores the value of the factorial of the current digit
            factorial=1;
            for (j = 0; j <= digit; j++){
                if(j==1 || j==0) continue;
                factorial*=j;
            }
            factorial_sum+=factorial;

            /* Factorial calculation using a math library function, the above for loop and the 
             incrementing factorial_sum can be commented out and the below line can be tried. */
            // factorial_sum+=tgamma(digit+1);

            x/=10;
        }
        if(factorial_sum==i) printf("%d\n",i);
    }
    printf("\n");
    
    // 3. Checking the LAB numbers and printing them
    printf("The LAB numbers between 1 and %d are: \n",n);
    for (i = 1; i <=n; i++)
    {
        // factor_sum is used to keep track of the sum of the factors of the number, excluding itself
        factor_sum=1;

        /* Checking if the current number is a perfect square, 
         so as to avoid repetition of it's square root in it's factors */
        if ((int)sqrt(i)*(int)sqrt(i) == i) factor_sum+=i;

        for ( j = 2; j*j < i; j++)
        {
            if (i%j==0) factor_sum+=(j + i/j);
        }
        if(factor_sum==i) printf("%d\n",i);
        
    }
    printf("\n");

    // 4. If n is both a PDS number and a LAB number, print the bow pattern
    // if(factorial_sum==n && factor_sum==n)
    {
        for ( j = 1; j <= 2*n-1; j++)
        {
            if(j<n+1){
                for ( k = 1; k <= n-j+1; k++)
                {
                    printf("*");
                }
                printf("\n"); 
            }
            else {for ( k = j; k >= n; k--)
            {
                printf("*");
            }
            printf("\n"); }
        }
    }
    /* We do not need to calculate the factor_sum and factorial_sum fot n as in the above condition, 
    they were the last updated variables in both the loops, whose iterations were calculating 
    the respective values of factorial_sum and factor_sum */

    return 0;
}