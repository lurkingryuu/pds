/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 4B
*/

// Including the header files
#include <stdio.h>
#include <stdlib.h>

// The main function
int main(){
    // Declaring variables of respective types
    char S[100], Q[100];
    int i, flag;

    // This is a count array, which keeps track of the number of times a letter is repeated in the string S
    // 'a' corresponds to index 0, 'b' to 1, and so on...
    int C[26];

    // Taking the input from the user for string S
    printf("Enter the sring S: ");
    scanf("%[^\n]s",S);

    // Prompting for Queries until Query is "end"
    while (1){
        // Initialising the count array to all zeroes
        for (i = 0; i < 26; i++)
                C[i]=0;

        // Adding to the count each time a character appears in the string S, to it's count in it's respective index
        for (i = 0; S[i]!='\0'; i++)
                C[S[i]-'a']++;
        
        // Prompting the user for input of Query
        printf("Enter the Query Q: ");
        scanf ("%s", Q);

        // Exit the program if the entered Query is "end"
        if(Q[0]=='e' && Q[1]=='n' && Q[2]=='d' && Q[3]=='\0') break;

        // Checking if all the characters present int the Query Q are present in S
        flag=0;
        for (i = 0; Q[i]!='\0'; i++){
            if(C[Q[i]-'a']>0) C[Q[i]-'a']--;
            else {
                flag=1;
                break;
            }
        }

        // If every character in Q, including it's multiplicity is present in S, 
        // Then Q can be formed from S, else, Q cannot be formed from S  
        if(flag)
            printf("Q cannot be formed from S.\n");
        else
            printf("Q can be formed from S.\n");
    }

    return 0;
}