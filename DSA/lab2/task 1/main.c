#include <stdio.h>
#include <stdlib.h>
struct Student {
int id;
char name[10];
int grade;
};
struct Node {
struct Student student;
struct Node * next;
};
struct Node *head;
struct Node *tail;
struct Student fill()
{
    int id;
    char name[10];
    int grade;
    printf("enter student id\n");
    scanf("%d", &id);
    printf("enter student name\n");
    scanf("%s", name);
    printf("enter student grade\n");
    scanf("%d", &grade);
    struct Student st;
    st.id = id;
    st.grade = grade;
    strcpy(st.name, name);
    return st;
};
void print(struct Student st)
{
    printf("Student name : %s ", st.name);
    printf("Student id: %d ", st.id);
    printf("Student grade : %d\n", st.grade);
    printf("-----------------------------------------------\n");
}
struct Node * CreateNode(struct Student st)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node ));
    if (ptr)
    {
        ptr->student = st;
        ptr->next = NULL;
    }
    return ptr;
};
int push(struct Student st)
{
    int ret = 0;
    struct Node * node = CreateNode(st);
    if (node)
    {
        ret = 1;
        if (head)
        {
            node->next = head;
            head = node;
        }
        else
        {
            head = node;
        }
    }
    return ret;
}
struct Student pop()
{
    int ret = 0;
    struct Student st;
    st.id = -1;
    if (head)
    {
        ret = 1;
        struct Node *current = head;
        head = head->next;
        st = current->student;
        free(current);
    }
    return st;
}
void PrintMenu()
{
    printf("Choose an Option : \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Exit\n");
}
int main()
{
    int exit = 0;
    while(!exit)
    {
        PrintMenu();
        int c;
        struct Student st;
        scanf("%d", &c);
        switch(c)
        {
        case 1:
            st = fill();
            push(st);
            break;
        case 2:
            st = pop();
            if (st.id == -1)
            {
                printf("the stack is empty\n");
            }
            else
            {
                printf("removed ! \n");
                print(st);
            }
        case 3:
            exit = 1;
            break;
        default :
            printf("invalid option \n");
        }
    }
}
