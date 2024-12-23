#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avlTree.h"



Patient newPatients(char* name,char* surname,struct date birthday,float patient_height,float patient_weight,float bmi){
    Patient details=(Patient) malloc(sizeof(struct patient));
    if(!details){
        printf("memory allocation failed \n");
        return NULL;
    }
    strcpy(details->name,name);
    strcpy(details->surname,surname);
    details->birthday.year=birthday.year;
    details->birthday.day=birthday.day;
    details->birthday.month=birthday.month;
    details->patient_height=patient_height;
    details->patient_weight=patient_weight;
    details->bmi = bmi;


    return details;
}


int dateInDays(struct date birthday){
    return birthday.day +(birthday.month * 30) + (birthday.year * 365);
}



Patient youngestPatient(AVLTree t) {
    if (t == NULL) {
        return NULL; // If the tree is empty, return NULL
    }

    Patient youngest = NULL;
    int minDays = INT_MAX;  // Initialize to a large number so any valid date will update this

    // Traverse the left subtree
    Patient leftYoungest = youngestPatient(t->left);
    if (leftYoungest != NULL) {
        int leftDays = dateInDays(leftYoungest->birthday);
        if (leftDays < minDays) {
            minDays = leftDays;
            youngest = leftYoungest;
        }
    }

    // Check the patients in the current node
    for (int i = 0; i < t->patientNumber; ++i) {
        int patientDays = dateInDays(t->patientDetails[i]->birthday);
        if (patientDays < minDays) {
            minDays = patientDays;
            youngest = t->patientDetails[i];
        }
    }

    // Traverse the right subtree
    Patient rightYoungest = youngestPatient(t->right);
    if (rightYoungest != NULL) {
        int rightDays = dateInDays(rightYoungest->birthday);
        if (rightDays < minDays) {
            minDays = rightDays;
            youngest = rightYoungest;
        }
    }

    return youngest; // Return the youngest patient found
}
