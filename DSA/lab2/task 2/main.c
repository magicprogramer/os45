#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[10];
    int grade;
    int first;
    int last;
};
//last place in array of students will hold the location of
//first student and last which is the location where i can add a new student
struct Student arr[1001];
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
int enqueue(struct Student st)
{
    int last = arr[1000].last, first = arr[1000].first, ret = 0;
    if (last < 1000)
    {
        ret = 1;
        arr[last] = st;
        last ++;
    }
    arr[1000].last = last;
    return ret;
}
struct Student dequeue()
{
    int last = arr[1000].last, first = arr[1000].first, ret = 0;
    struct Student st;
    st.id = -1;
    if (first < last)
    {
        ret = 1;
        st = arr[first];
        first ++;
    }
    else
    {
        first = last = 1;
    }
    arr[1000].first = first;
    arr[1000].last = last;
    return st;


}
void PrintMenu()
{
    printf("choose an option \n");
    printf("1. enque\n");
    printf("2. dequeue\n");
    printf("3. exit\n");
}
int main()
{
    int exit = 0;
    arr[1000].first = 1;
    arr[1000].last = 1;
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
            enqueue(st);
            break;
        case 2:
            st = dequeue();
            if (st.id == -1)
            {
                printf("the queue is empty\n");
            }
            else
            {
                printf("removed ! \n");
                print(st);
            }
            break;
        case 3:
            exit = 1;
            break;
        default :
            printf("invalid option \n");
        }
    }
}
