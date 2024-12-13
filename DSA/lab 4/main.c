#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node * left;
struct Node * right;
};
struct Node *root;
int insert(int data)
{
    int ret = 0;
    struct Node *ptr;
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    if (node)
    {
        node->left = node->right = NULL;
        node->data = data;
        ret = 1;
        if (!root)
        {
            root = node;
        }
        else
        {
            ptr = root;
            while(ptr->left || ptr->right)
            {
                if (ptr->data < data)
                {
                    ptr = ptr->right;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            if (ptr->data < data)
            {
                ptr->right = node;
            }
            else
            {
                ptr->left = node;
            }
        }

    }
    return ret;
}
void inorder(struct Node * ptr)
{
    if (ptr)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}
void postorder(struct Node *ptr)
{
    if (ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d\n", ptr->data);
    }
}
void preorder(struct Node *ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void printMenu()
{
    printf("choose an option \n");
    printf("1. add a node \n");
    printf("2. in order traverse\n");
    printf("3. post order traverse\n");
    printf("4. pre order traverse\n");
    printf("5. exit \n");
    printf("---------------------------\n");
}
int main()
{
    int exit = 0;
    while(!exit)
    {
        printMenu();
        int c, data;
        scanf("%d", &c);
        switch(c)
        {
        case 1:
            scanf("%d", &data);
            if (insert(data))
            {
                printf("inserted ! \n");
            }
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            postorder(root);
            printf("\n");
            break;
        case 4:
            preorder(root);
            printf("\n");
            break;
        case 5:
            exit = 1;
            break;
        default :
            printf("invalid option \n");

        }
    }
    return 0;
}
