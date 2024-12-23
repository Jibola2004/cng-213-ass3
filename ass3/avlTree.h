#ifndef ASS3_AVLTREE_H
#define ASS3_AVLTREE_H


#define FALSE 0
#define TRUE 1

typedef struct Node *AVLTree;
typedef struct patient *Patient;

struct date {
    int day;
    int month;
    int year;
};

struct patient {
    char name[20];
    char surname[20];
    struct date birthday;
    float bmi;
    float patient_height;
    float patient_weight;
};

struct Node{
    int patientNumber;
    AVLTree left;
    AVLTree right;
    int height;
    float bmi;
    Patient* patientDetails;
};


AVLTree CreateTree(void);
AVLTree MakeEmptyTree(AVLTree);
AVLTree InsertElement( Patient , AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
void DisplayTree(AVLTree);
//void DisplayTreeStructure(AVLTree, int);
int AVLTreeHeight(AVLTree);
int Max(int, int);
Patient newPatients(char* name,char* surname,struct date birthday,float patient_height,float patient_weight,float bmi);
Patient youngestPatient(AVLTree t) ;


#endif //ASS3_AVLTREE_H
