// lab 09
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    friend class StudentList;

private:
    int id;
    string name;
    float cgpa;
    Student *next;

public:
    Student(int id, string name, float cgpa, Student *next) : id(id), name(name), cgpa(cgpa), next(next)
    {

    }

    void studentDetails() const
    {
        cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
    }
};

class StudentList
{
private:
    Student *head;
    Student *cursor;

public:
    StudentList() : head(NULL), cursor(NULL)
    {

    }
    ~StudentList()
    {
        while (head)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
            
        }
    }

    void insert(const Student &newStd)
    {
        Student *newNode = new Student(newStd.id, newStd.name, newStd.cgpa, NULL);
        if (head==NULL)
        {
            head = newNode;
            cursor = head;
        }
        else
        {
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = newNode;
        }
    }

    void remove(int id)
    {
        Student *curr = head;
        Student *pre = NULL;

        while (curr && curr->id != id)
        {
            pre = curr;
            curr = curr->next;
        }

        if (curr)
        {
            if (pre)
            {
                pre->next = curr->next;
            }
            else
            {
                head = curr->next;
            }

            if (cursor == curr)
            {
                cursor = curr->next;
            }

            delete curr;
        }
    }

    void search(float cgpa) const
    {
        Student *curr = head;
       // bool found = false;

        while (curr)
        {
            if (curr->cgpa == cgpa)
            {
                curr->studentDetails();
                // found = true;
            }
            curr = curr->next;
        }

        // if (!found)
        {
            cout << "No student found with CGPA: " << cgpa << endl;
        }
    }
    void replace(const Student& newStd)
    {
        Student* curr=head;
        // bool found=false;
        while(curr!=NULL)
        {
            if(curr->id==newStd.id)
            {
                *curr=newStd;
                cursor=curr;
                // found=true;
            }
            curr=curr->next;
        }
        // if(!found)
        // {
        //     insert(newStd);
        // }
    }
    bool isEmpty()const
    {
        return head==NULL;
    }
    void gotoBeginning()
    {
        cursor=head;
    }
    void gotoEnd()
    {
        while(cursor!=NULL && cursor->next!=NULL)
        {
            cursor=cursor->next;
        }
    }
    bool gotoNext()
    {
        if(cursor!=NULL && cursor->next!=NULL)
        {
            cursor=cursor->next;
            return true;
        }
        return false;
    }
    bool gotoPrior()
    {
        if(cursor!=NULL && cursor != head)
        {
            Student* temp=head;
            while(temp->next!=cursor)
            {
                temp=temp->next;
            }
            cursor=temp;
            return true;
        }
        return false;
    }
    Student getCursor()
    {
        if(cursor!=nullptr)
        {
            return *cursor;
        }
    }

    void showStructure() const
    {
        if (!head)
        {
            cout << "Empty list" << endl;
            return;
        }
        else
        {
        Student *curr = head;
        while (curr)
        {
            curr->studentDetails();
            curr = curr->next;
        }
        }
        
    }
};

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cerr << "Error opening input file." << endl;
        exit(0);
    }

    StudentList studentList;
    int id;
    string name;
    float cgpa;

    while (inputFile >> id)
    {
        inputFile.ignore();
        getline(inputFile, name);
        inputFile >> cgpa;
        inputFile.ignore();

        Student newStudent(id, name, cgpa, nullptr);
        studentList.insert(newStudent);

        string blankLine;
        getline(inputFile, blankLine);
    }

    inputFile.close();

    
    studentList.showStructure();
    // studentList.search(3.59);

    return 0;
}
