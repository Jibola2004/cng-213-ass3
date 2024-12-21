#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avlTree.h"
void loadPatients(int argc,char* argv[],AVLTree myTree);

int main(int argc,char* argv[])
{
    AVLTree myTree, pos;
    int exit, val, height;
    char command;
    myTree = CreateTree();

    exit = FALSE;
    while (!exit)
    {
        fflush(stdin);
        printf("\nEnter command \n"
               "a) initialize tree \n"
               "b) load patient into tree \n"
               "c)  element \n "
               "d) leave count \n"
               " e) count nodes \n"
               " f) find element \n"
               " g) height of tree \n"
               "h) min element \n"
               "i) max element \n"
               " j) print tree structure \n"
               " k)  exit \n"
               " : ");
        scanf("%c", &command);
        fflush(stdin);

        switch (command)
        {
            case 'a':
                myTree = MakeEmptyTree(myTree);
                break;
            case 'b':
                  loadPatients(argc,argv,myTree);
//                printf("enter value: ");
//                scanf("%d", &val);
//                myTree = InsertElement(val, myTree);
                DisplayTree(myTree);
                break;
            case 'c':
                DisplayTreeStructure(myTree, 0);
                break;
            case 'k':
                exit = TRUE;
                break;
            default:
                printf("command not recognized\n");
                break;
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

void loadPatients(int argc, char* argv[], AVLTree t) {
    char fileName[20];
    char title[1000];

    // Get the file name from arguments or prompt the user
    if(argc > 1) {
        strcpy(fileName, argv[1]);
    } else {
        printf("File name not entered\nEnter file name: ");
        scanf("%s", fileName);
    }

    // Open file and check if it succeeded
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return; // Return if the file cannot be opened
    }

    // Skip the first line (title/header)
    fgets(title, sizeof(title), file);
    printf("%s",title);
    // Read patient data line by line
    while (1) {
        struct patient* newNode = (struct patient*) malloc(sizeof(struct patient));
        if (newNode == NULL) {
            printf("Out of memory!\n");
            fclose(file);
            exit(1); // Exit if memory allocation fails
        }

        // Allocate memory for the patient's birthday
        newNode->birthday = (struct date*) malloc(sizeof(struct date));
        if (newNode->birthday == NULL) {
            printf("Out of memory!\n");
            free(newNode);
            fclose(file);
            exit(1); // Exit if memory allocation fails
        }

        // Read the patient data from the file
        if (fscanf(file, "%20[^;];%20[^;];%d/%d/%d;%f;%f;%f\n",
                   newNode->name, newNode->surname,
                   &newNode->birthday->day, &newNode->birthday->month,
                   &newNode->birthday->year, &newNode->patient_height,
                   &newNode->patient_weight, &newNode->bmi) != 8) {
            DisplayTree(t);

            printf("\nDone loading patients\n");
            free(newNode->birthday);
            free(newNode);
            break; // Exit if reading fails (end of file)
        }

        // Initialize left and right pointers for the AVL node
        newNode->left = newNode->right = NULL;

        // Insert the new patient data into the tree
        t = InsertElement(newNode, t);
    }

    fclose(file); // Close the file after reading
}
