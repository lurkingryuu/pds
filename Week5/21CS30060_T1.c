/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: T1
*/

// Including the header files
#include <stdio.h>
#include <string.h>
#include <math.h>

// The main function
int main(){
    // Declaring variables of respective type.
    int l1,l2, count=0, i, j, flag1,flag2,flag3,flag4, hamming, min_hamming;
    char old[100], new[100], c, spl[]="!@#$%^&*+=-_.,?`~"; 
    // The spl string above declared is a custom string which contains all the characters,
    // that are considered to be a special character by the program.

    printf("Enter the Existing Password: ");
    scanf("%[^\n]s", &old);
    
    // Storing the length of the old password using strlen function present in string.h library
    l1=strlen(old);


    // Printing the Requirements so that the user could be aware of them.
    printf("\nThe requirements for the new password are:\n");
    printf("(a) It must have at least 1 vowel.\n");
    printf("(b) It must have at least 1 digit between 0-9.\n");
    printf("(c) It must have at least 1 special character(%s).\n", spl);
    printf("(d) The Hamming distance of Old Password and New Password must be at least (sum of lengths of each of them)/3.\n");

    // Taking the user input for the new password 1st time.
    printf("\nEnter the new Password: ");

    // The loop to check if the requirements are satisfied.
    while(1){
        count=0;flag1=0;flag2=0;flag3=0;flag4=0;hamming=0;
        scanf("%s", &new);
        l2 = strlen(new);

        for ( i = 0; new[i]!='\0'; i++)
        {
            // Checking for the 1st requirement
            if(flag1==0){
                switch (new[i])
                {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    flag1=1;
                    count++;
                }
            }

            // Checking for the 2nd requirement
            if(flag2==0){
                if(new[i]>='0' && new[i]<='9') {
                    flag2=1;
                    count++;
                }
            }
            
            // Checking for the 3rd requirement
            if(flag3==0){
                for (j = 0; spl[j]!='\0'; j++)
                {
                    if (new[i]==spl[j]){
                        flag3=1;
                        count++;
                        break;
                    }
                }
            }

        }

        // Determining the min hamming distance required
        min_hamming = (int)ceil((l1+l2)/3.0);

        // Calculating the hamming distance.
        hamming = (l2>l1)? (l2-l1) : (l1-l2);
        for ( i = 0; new[i]!='\0'; i++){
            if(old[i]=='\0')
                break;

            if(old[i]!=new[i]) hamming++;
        }

        // Checking for the 4th requirement
        if(hamming>=min_hamming) {
            flag4=1;
            count++;
        }

        if(count<4){
            printf("The password that you entered does not qyalify as a new password due to the violation of the  following requirement(s):\n");
            if(!flag1) printf("(a) It must have at least 1 vowel.\n");
            if(!flag2) printf("(b) It must have at least 1 digit between 0-9.\n");
            if(!flag3) printf("(c) It must have at least 1 special character(%s).\n", spl);
            if(!flag4) printf("(d) The Hamming distance of Old and New Passwords must be at least: %d, but it was: %d.\n", min_hamming, hamming);
        }
        else break;

        printf("\nPlease Enter a new password Again: ");
    }

    printf("The New Password satisfies all the requirements.\n");
    printf("Password Changed Successfully!");

    return 0;
}