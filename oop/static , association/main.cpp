#include <iostream>
#include <string.h>
using namespace std;
class Employee{
private:
    int id;
    char *name;
    static string company_name;
    static int counter;
public:
    Employee()
    {
        counter ++;
        this->id = -1;
        name = new char[20];
        strcpy(name, "");
    }
    Employee(int id)
    {
        counter ++;
        this->id = id;
        this->name = new char[20];
        strcpy(this->name, "");
    }
    Employee(char * name)
    {
        counter ++;
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
        this->id = -1;
    }
    Employee(int id, char * name)
    {
        counter ++;
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
        this->id = id;
    }
    int getid()
    {
        return id;
    }
    char* getName()
    {
        return name;
    }
    void setId(int id)
    {

        this->id = id;
    }
    void setName(char * name)
    {
        delete(this->name);
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
    Employee (Employee const &e)
    {
        this->name = new char[strlen(e.name)];
        this->id = e.id;
        strcpy(this->name, e.name);
    }
    static int getCounter()
    {
        return counter;
    }
    static string getCompany()
    {
        return company_name;
    }
    ~Employee()
    {
        delete(name);
        counter ++;
       // cout<<"deleted"<<endl;
    }
};
int Employee::counter = 0;
string Employee::company_name = "ITI";
Employee fill()
{
    char name[15];
    int id;
    cout<<"enter id :";
    cin>>id;
    cout<<"enter name : ";
    cin>>name;
    Employee st;
    st.setId(id);
    st.setName(name);
    return st;

}

void printEmp(Employee &e)
{
    cout<<"employee id : "<<e.getid()<<" employee Name : "<<e.getName()<<" company name : "<<Employee::getCompany()<<endl;
}
int main()
{
    Employee e1[5] = {Employee(1), Employee(2, "Ahmed"), Employee("ezzat")};
    cout<<"number of employees is : "<<Employee::getCounter()<<endl;
    for (int i = 0; i < Employee::getCounter(); i ++)
    {
        printEmp(e1[i]);
    }
    return 0;
}
