#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avlTree.h"
void loadPatients(int argc,char* argv[],AVLTree myTree);
Patient youngestPatient(AVLTree t) ;

int main(int argc,char* argv[])
{
    AVLTree myTree, pos;
    Patient youngest =NULL;
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
//
                break;
            case 'c':
                 youngest = youngestPatient(myTree);  // Correct usage
                if (youngest != NULL) {
                    printf("Youngest Patient: %s %s\n", youngest->name, youngest->surname);
                } else {
                    printf("No patients found.\n");
                }
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
        char name[20];
        char surname[20];
        struct date birthday;
        float patient_height;
        float patient_weight;
        float bmi;

        // Read the patient data from the file
        if (fscanf(file, "%20[^;];%20[^;];%d/%d/%d;%f;%f;%f\n",
                   name, surname,
                   &birthday.day, &birthday.month,
                   &birthday.year, &patient_height,
                   &patient_weight, &bmi) != 8) {
            DisplayTree(t);

            printf("\nDone loading patients\n");

            break;
        }


       Patient newDetails = newPatients(name,surname, birthday,patient_height,patient_weight,bmi);


        t = InsertElement(newDetails, t);
    }

    fclose(file); // Close the file after reading
}

 //int dateInDays(struct date birthday){
  //  return birthday.day +(birthday.month * 30) + (birthday.year * 365);
//}


//
//Patient youngestPatient(AVLTree t) {
//    if (t == NULL) {
//        return NULL; // If the tree is empty, return NULL
//    }
//
//    Patient youngest = NULL;
//    int minDays = INT_MAX;  // Initialize to a large number so any valid date will update this
//
//    // Traverse the left subtree
//    Patient leftYoungest = youngestPatient(t->left);
//    if (leftYoungest != NULL) {
//        int leftDays = dateInDays(leftYoungest->birthday);
//        if (leftDays < minDays) {
//            minDays = leftDays;
//            youngest = leftYoungest;
//        }
//    }
//
//    // Check the patients in the current node
//    for (int i = 0; i < t->patientNumber; ++i) {
//        int patientDays = dateInDays(t->patientDetails[i]->birthday);
//        if (patientDays < minDays) {
//            minDays = patientDays;
//            youngest = t->patientDetails[i];
//        }
//    }
//
//    // Traverse the right subtree
//    Patient rightYoungest = youngestPatient(t->right);
//    if (rightYoungest != NULL) {
//        int rightDays = dateInDays(rightYoungest->birthday);
//        if (rightDays < minDays) {
//            minDays = rightDays;
//            youngest = rightYoungest;
//        }
//    }
//
//    return youngest; // Return the youngest patient found
//}
