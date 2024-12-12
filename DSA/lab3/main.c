#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[10];
    int grade;
};
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
struct Student st[100];
struct Student temp[100];
int size;
void merge(int l, int m, int u)
{
    int i = l, i2 = l, i3 = m + 1;
    while(i2 <= m && i3 <= u)
    {
        if (st[i2].id <= st[i3].id)
        {
            temp[i] = st[i2];
            i2 ++;
        }
        else
        {
            temp[i] = st[i3];
            i3 ++;
        }
        i ++;
    }
    while(i2 <= m)
    {
        temp[i] = st[i2];
        i2 ++;
        i ++;
    }
    while(i3 <= u)
    {
        temp[i] = st[i3];
        i3 ++;
        i ++;
    }
    for (i = l; i <= u; i ++)
    {
        st[i] = temp[i];
    }


}
void mergesort(int l, int u)
{
    if (l < u)
    {
        int m = (l + u) / 2;
        mergesort(l, m);
        mergesort(m + 1, u);
        merge(l, m, u);
    }
}
struct Student search(int id)
{
    int first = 0, last = size - 1;
    struct Student found;
    found.id = -1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (st[mid].id == id)
        {
            found = st[mid];
            break;
        }
        else
        {
            if (st[mid].id < id)
            {
                first = mid + 1;
            }
            else
            {
                last = mid - 1;
            }
        }

    }
    return found;
};
void bubble_sort()
{
    for (int i = 0; i < size - 1 - i; i ++)
    {
        for (int j = 0; j < size - 1; j ++)
        {
            if (st[j].id > st[j + 1].id)
            {
                struct Student temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }
}
int main()
{
    printf("enter size of the array\n");
    scanf("%d", &size);
    int i = 0;
    for (i = 0; i < size; i ++)
    {
        st[i] = fill();
    }
    printf("before sorting\n");
    for (i = 0; i < size; i ++)
    {
        print(st[i]);
    }
    printf("after sorting by bubble sort \n");
    bubble_sort();
    for (int i = 0; i < size; i ++)
    {
        print(st[i]);
    }
    printf("\n");
    mergesort(0, size - 1);
    printf("after sorting by merge sort \n");
    for (int i = 0; i < size; i ++)
    {
        print(st[i]);
    }
    int cont = 1;
    while(cont)
    {
        int id;
        printf("search for an id\n");
        scanf("%d", &id);
        struct Student found = search(id);
        if (found.id != -1)
        {
            printf("found !\n");
            print(found);
        }
        else
        {
            printf("not found \n");
        }
    }
    return 0;
}
