#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    int x;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));

    printf("enter data: ");
    scanf("%d", &x);

    if (x == -1)
    {
        return 0;
    }

    newnode->data = x;

    printf("enter the left node of %d\n", x);
    newnode->left = create();

    printf("enter the right node of %d\n", x);
    newnode->right = create();

    return newnode;
}

void preorder(node *thisroot)
{
    if (thisroot == 0)
    {
        return;
    }
    printf("%d ", thisroot->data);
    preorder(thisroot->left);
    preorder(thisroot->right);
}

void inorder(node *thisroot)
{
    if (thisroot == 0)
    {
        return;
    }
    inorder(thisroot->left);
    printf("%d ", thisroot->data);
    inorder(thisroot->right);
}

void postorder(node *thisroot)
{
    if (thisroot == 0)
    {
        return;
    }
    postorder(thisroot->left);
    postorder(thisroot->right);
    printf("%d ", thisroot->data);
}

int treeSum(node *root)
{
    int leftsum, rightsum;
    if (root == NULL)
    {
        return;
    }

    leftsum = treeSum(root->left);
    rightsum = treeSum(root->right);
    return root->data + leftsum + rightsum;
}

node *searchingBST(node *root, int key)
{
    //method: 1
    //itrerative method
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return NULL;

    //method: 2
    //recursive method
    // if (root == NULL)
    // {
    //     return NULL;
    // }
    // if (root->data == key)
    // {
    //     return root;
    // }
    // else if (key > root->data)
    // {
    //     return searchingBST(root->right, key);
    // }
    // else
    // {
    //     return searchingBST(root->left, key);
    // }
}

void insertingBST(node *root, int key)
{
    node *prev;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            return;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    node *new = (node *)malloc(sizeof(node));
    new->data = key;
    new->left = NULL;
    new->right = NULL;
    if (key > prev->data)
    {
        prev->right = new;
    }
    else
    {
        prev->left = new;
    }
}

node *minvalue(node *root)
{
    node *prev;
    while (root != NULL)
    {
        prev = root;
        root = root->left;
    }
    return prev;
}

node *deletenode(node *root, int key)
{
    node *temp;
    if (root == NULL)
    {
        return root;
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else
    {
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            temp = minvalue(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

int maxheight(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = maxheight(root->left);
        int rheight = maxheight(root->right);
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

int main()
{
    node *root;
    node *n;
    node *min;
    int exit = 1;
    int key;
    while (exit)
    {
        int choose;

        printf("\n\nchoose one:- \n");
        printf("1. create new binary tree\n");
        printf("2. preorder traversal\n");
        printf("3. inorder traversal\n");
        printf("4. postorder traversal\n");
        printf("5. find sum of the tree\n");
        printf("6. searching element in BST\n");
        printf("7. insert element in BST\n");
        printf("8. delete element in BST\n");
        printf("9. min value of BST\n");
        printf("10. max height of BST\n");
        printf("11. exit\n\n");

        printf("choose: ");
        scanf("%d", &choose);

        switch (choose)
        {
        case 1:
            printf("\n\n***creating a new binary tree***\n");
            root = create();
            break;

        case 2:
            printf("\n\n***preorder binary tree traversal***\n");
            preorder(root);
            break;

        case 3:
            printf("\n\n***inorder binary tree traversal***\n");
            inorder(root);
            break;

        case 4:
            printf("\n\n***postorder binary tree traversal***\n");
            postorder(root);
            break;

        case 5:
            printf("\n\nthe sum of all nodes is %d\n", treeSum(root));
            break;

        case 6:
            printf("\n\nenter element you want to search: ");
            scanf("%d", &key);
            printf("\nSearching result.........\n");
            n = searchingBST(root, key);
            if (n != NULL)
            {
                printf("Found element: %d", n->data);
            }
            else
            {
                printf("element not found...");
            }

            break;

        case 7:
            printf("\n\nenter element you want to insert: ");
            scanf("%d", &key);
            insertingBST(root, key);
            break;

        case 8:
            printf("\n\nenter element you want to delete: ");
            scanf("%d", &key);
            deletenode(root, key);
            break;

        case 9:
            min = minvalue(root->right);
            printf("%d ", min->data);
            break;

        case 10:
            printf("\n\nthe max height of BST is: %d", maxheight(root));
            break;

        case 11:
            exit = 0;
            break;

        default:
            printf("please enter the valid number..\n\n");
            break;
        }
    }

    return 0;
}