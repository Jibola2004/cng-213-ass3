#ifndef ASS3_AVLTREE_H
#define ASS3_AVLTREE_H


#define FALSE 0
#define TRUE 1

typedef struct patient *AVLTree;

struct date {
    int day;
    int month;
    int year;
};

struct patient {
    char name[20];
    char surname[20];
    struct date* birthday;
    float bmi;
    float patient_height;
    float patient_weight;
    AVLTree left;
    AVLTree right;
    int height;


};

AVLTree CreateTree(void);
AVLTree MakeEmptyTree(AVLTree);
AVLTree InsertElement(AVLTree , AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
void DisplayTree(AVLTree);
void DisplayTreeStructure(AVLTree, int);
int AVLTreeHeight(AVLTree);
int Max(int, int);



#endif //ASS3_AVLTREE_H
