#include<stdio.h>
 
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

int main()
{
    node *root;
    int choose;
    printf("enter your choose: ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        printf("cteate new node\n");

        break;
    
    default:
        printf("please enter valid number \n");
        break;
    }

    return 0;
}