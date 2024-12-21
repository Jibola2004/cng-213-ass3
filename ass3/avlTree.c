#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avlTree.h"
//
//int main()
//{
//    AVLTree myTree, pos;
//    int exit, val, height;
//    char command;
//    myTree = CreateTree();
//
//    exit = FALSE;
//    while (!exit)
//    {
//        fflush(stdin);
//        printf("\nEnter command \n"
//               "i) initialize \n"
//               "n) new element \n"
//               " d)  element \n "
//               "l) leave count \n"
//               " c) count nodes \n"
//               " f) find element \n"
//               " h) height of tree \n"
//               "m) min element \n"
//               "M) max element \n"
//               " p) print tree structure \n"
//               " e) exit: ");
//        scanf("%c", &command);
//        fflush(stdin);
//
//        switch (command)
//        {
//            case 'i':
//                myTree = MakeEmptyTree(myTree);
//                break;
//            case 'n':
//                printf("enter value: ");
//                scanf("%d", &val);
//                myTree = InsertElement(val, myTree);
//                DisplayTree(myTree);
//                break;
//            case 'p':
//                DisplayTreeStructure(myTree, 0);
//                break;
//            case 'e':
//                exit = TRUE;
//                break;
//            default:
//                printf("command not recognized\n");
//                break;
//        }
//    }
//    printf("\n");
//    system("PAUSE");
//    return 0;
//}

AVLTree CreateTree(void)
{
    return NULL;
}

AVLTree MakeEmptyTree(AVLTree t)
{
    if (t != NULL)
    {
        MakeEmptyTree(t->left);
        MakeEmptyTree(t->right);
        free(t);
    }
    return NULL;
}

AVLTree InsertElement(AVLTree newNode, AVLTree t)
{

    if (t == NULL)
    {
        t = (struct patient*) malloc(sizeof(struct patient));
        if (t == NULL) {
            printf("Out of memory space!!!\n");
            return NULL;
        }

        t->birthday = (struct date*) malloc(sizeof(struct date));  // Allocate memory for birthday
        if (t->birthday == NULL) {
            printf("Out of memory space for birthday!!!\n");
            free(t);
            return NULL;
        }

        else
        {
            strcpy(t->name,newNode->name);
            strcpy(t->surname,newNode->surname);
            t->bmi=newNode->bmi;
            t->birthday->year=newNode->birthday->year;
            t->birthday->day=newNode->birthday->day;
            t->birthday->month=newNode->birthday->month;
            t->patient_height=newNode->patient_height;
            t->patient_weight=newNode->patient_weight;
            t->height = 0;
            t->left = t->right = NULL;
        }
    }
    else if ( newNode->bmi <  t->bmi)
    {
        t->left = InsertElement(newNode, t->left);

        if (AVLTreeHeight(t->left) - AVLTreeHeight(t->right) == 2)
            if (newNode->bmi <  t->left->bmi)
                t = SingleRotateWithLeft(t);
            else
                t = DoubleRotateWithLeft(t);
    }
    else if (newNode->bmi > t->bmi)
    {
        t->right = InsertElement(newNode, t->right);
        if (AVLTreeHeight(t->right) - AVLTreeHeight(t->left) == 2)
            if (newNode->bmi  > t->right->bmi)
                t = SingleRotateWithRight(t);
            else
                t = DoubleRotateWithRight(t);
    }
    else if(newNode->bmi == t->bmi){


    }
    /* else val is in the tree already ... do nothing */
    t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;

    return t;
}

void DisplayTree(AVLTree t)
{
    if (t != NULL)
    {

        DisplayTree(t->left);
        printf("%.2f\n", t->bmi);
        DisplayTree(t->right);
    }
}

void DisplayTreeStructure(AVLTree t, int depth)
{
    int i;

    if (t != NULL)
    {
        DisplayTreeStructure(t->right, depth + 1);

        for (i = 0; i < depth; i++)
            printf("     ");
        printf("%.2f\n", t->bmi);

        DisplayTreeStructure(t->left, depth + 1);
    }
}

int AVLTreeHeight(AVLTree t)
{
    if (t == NULL)
        return -1;
    else
        return t->height;
}

AVLTree SingleRotateWithLeft(AVLTree k2)
{
    AVLTree k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    // Update heights
    k2->height = Max(AVLTreeHeight(k2->left), AVLTreeHeight(k2->right)) + 1;
    k1->height = Max(AVLTreeHeight(k1->left), AVLTreeHeight(k1->right)) + 1;

    return k1;
}


AVLTree SingleRotateWithRight(AVLTree k1)
{
    AVLTree k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    // Update heights
    k1->height = Max(AVLTreeHeight(k1->left), AVLTreeHeight(k1->right)) + 1;
    k2->height = Max(AVLTreeHeight(k2->left), AVLTreeHeight(k2->right)) + 1;

    return k2;
}


AVLTree DoubleRotateWithLeft(AVLTree k3)
{
    // First rotate left on the left child
    k3->left = SingleRotateWithRight(k3->left);

    // Then rotate right on the current node
    return SingleRotateWithLeft(k3);
}


AVLTree DoubleRotateWithRight(AVLTree k3)
{
    // First rotate right on the right child
    k3->right = SingleRotateWithLeft(k3->right);

    // Then rotate left on the current node
    return SingleRotateWithRight(k3);
}


int Max(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}
