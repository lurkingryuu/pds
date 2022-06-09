/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 2B
*/

// Including the header file which contains the I/O functionality
#include <stdio.h>

// The main function
int main(){
    // variable declaration of necessary types.
    int n, roll_number, i;
    char room;

    // Taking the input for number of students.
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // The for loop to repeat the process of alloting rooms to n students. 
    for (i=0; i<n; i++) {
        // Reading the roll number from user.
        printf("Enter the Roll number of student %d: ", i+1);
        scanf("%d", &roll_number);

        // Checking the last digit of the roll number and assigning the room.
        switch (roll_number%10)
        {
        case 0:
        case 1:
            room = 'E';
            break;
        case 2:
        case 3:
            room = 'D';
            break;
        case 4:
        case 5:
            room = 'T';
            break;
        case 6:
        case 7:
            room = 'C';
            break;
        case 8:
        case 9:
            room = 'P';
            break;
        }

        // Printing the assignment of room to the student.
        printf("The student with Roll No. %d has been assigned %cRoom.\n", roll_number, room);
    }


    return 0;
}