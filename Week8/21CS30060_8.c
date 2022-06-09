/*
Name: Yelisetty Karthikeya S M
Roll No.: 21CS30060
Assignment: 8
*/

// Including the header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Structure for the Dictionary Node
typedef struct entry {
    char var[40]; // Stores the string var of maximum length 40
    int value; // Stores an integer value
}dictnode;


// Structure for the DICTIONARY
typedef struct {
    int numentry ; // Stores the current number of entries in the dictionary
    int dsize; // The size of the dictionary[] array which defines the maximum number of entries that can be stored in the dictionary
    dictnode * dictionary; // The array which stores the dictionary entries
}DICT;


// Function prototypes
DICT * createdict(int dictsize);
dictnode makeentry ( char var[], int val);
void add1entry(dictnode newentry, DICT * pdictionary);
void printentry(DICT * pdictionary, char var[]);
void delentry (DICT * pdictionary, char var[]);
void printdict (DICT * pdictionary);


// The main function
int main(){
    // Declaring the variables
    char command[10];
    DICT * dictionary;
    int size;

    printf("Enter the maximum number of entries to be stored in the dictionary: ");
    scanf("%d",&size);

    // Creating the dictionary of size n
    dictionary = createdict(size);


    // Reading the commands input by the user
    while (1)
    {
        // Reading the command
        scanf("%s", command);

        // Checking if the command is "add"
        if (strcmp(command, "add") == 0)
        {
            char var[40];
            int val;
            scanf(" %s", var);
            scanf("%d", &val);
            // Adding the entry to the dictionary
            add1entry(makeentry(var, val), dictionary);
        }

        // Checking if the command is "find"
        else if (strcmp(command, "find") == 0)
        {
            char var[40];
            scanf("%s", var);
            // Printing the entry if it is found
            printentry(dictionary, var);
        }

        // Checking if the command is "delete"
        else if (strcmp(command, "del") == 0)
        {
            char var[40];
            scanf("%s", var);
            // Deleting the entry from the dictionary
            delentry(dictionary, var);
        }

        // Checking if the command is "print"
        else if (strcmp(command, "print") == 0)
        {
            // Printing the dictionary
            printdict(dictionary);
        }

        // Checking if the command is "quit"
        else if (strcmp(command, "quit") == 0)
        {
            // Exiting the loop
            break;
        }

        // If No command matches, print error message
        else{
            printf("\tInvalid command\n");
        }
    }

    // Freeing the memory allocated to the dictionary pointer of DICT structure
    free (dictionary->dictionary);

    // Quiting the user interface
    printf("\tBye\n");

    return 0;
}


// Function to create a new dictionary
DICT * createdict(int dictsize){
    DICT *d = (DICT *)malloc(sizeof(DICT));
    d->numentry = 0;
    d->dsize = dictsize;
    d->dictionary = (dictnode *)malloc(sizeof(dictnode)*dictsize);
    return d;
}


// Function to create a new dictnode
dictnode makeentry ( char var[], int val){
    dictnode e;
    strcpy(e.var, var);
    e.value = val;
    return e;
}


// Function to insert an entry in the dictionary
void add1entry(dictnode newentry, DICT * pdictionary){
    int i;
    // Checking if the dictionary is full
    if (pdictionary->numentry == pdictionary->dsize)
    {
        printf("\tDictionary is full\n");
        return;
    }
    // Checking if the entry is already present in the dictionary
    for(i=0; i<pdictionary->numentry; i++){
        if(strcmp(pdictionary->dictionary[i].var, newentry.var) == 0){
            pdictionary->dictionary[i].value = newentry.value;
            return;
        }
    }
    // Inserting the entry in the dictionary
    pdictionary->dictionary[(pdictionary->numentry)++] = newentry;
}


// Prints an entry in the dictionary having the same var as the input variable
void printentry(DICT * pdictionary, char var[]){
    int i, flag=1;
    for(i=0; i<pdictionary->numentry; i++){
        if(strcmp(pdictionary->dictionary[i].var, var) == 0){
            printf("\t%s %d\n", pdictionary->dictionary[i].var, pdictionary->dictionary[i].value);
            flag = 0;
        }
    }
    // If the variable is not found in the dictionary, print the error message
    if(flag){
        printf("\t%s not found\n", var);
    }
}


// Deletes the entry from the dictionary having the same var as the input variable
void delentry (DICT * pdictionary, char var[]){
    int i, flag=1;
    // Checking if the dictionary is empty
    if(pdictionary->numentry == 0){
        printf("\tDictionary is empty\n");
        return;
    }
    // Checking if the entry is present in the dictionary and deleting if found
    for(i=0; i<pdictionary->numentry; i++){
        if(strcmp(pdictionary->dictionary[i].var, var) == 0){
            pdictionary->dictionary[i] = pdictionary->dictionary[--(pdictionary->numentry)];
        }
    }
    // If the variable is not found in the dictionary, print the error message
    if(flag){
        printf("\t%s not found\n", var);
    }
}


// Prints the dictionary
void printdict (DICT * pdictionary){
    int i;
    // Checking if the dictionary is empty
    if(pdictionary->numentry == 0){
        printf("\tDictionary is empty\n");
        return;
    }
    // Printing the dictionary
    for(i=0; i<pdictionary->numentry; i++){
        printf("\t%s %d\n", pdictionary->dictionary[i].var, pdictionary->dictionary[i].value);
    }
}