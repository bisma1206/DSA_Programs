// TASK 02
#include "iostream"
#include "fstream"
#include "cstdio"
#include "string"
using namespace std;
class Student
{

    int id;
    float marks;

    friend istream &operator>>(istream &in, Student &obj);
    friend ostream &operator<<(ostream &print, const Student &obj);

public:
    Student(int id = 0, float marks = 0.0f)
    {
        this->id = id;
        this->marks = marks;
    }
    void addStudent(ofstream *outf)
    {
        outf->write(reinterpret_cast<char *>(this), sizeof(Student));
    }
    static void displayAllStudent(ifstream *outf)
    {
        Student temp;
        outf->read(reinterpret_cast<char *>(&temp), sizeof(temp));
        while (!outf->eof())
        {
            cout << temp;
            outf->read(reinterpret_cast<char *>(&temp), sizeof(temp));
        }
    }
    bool findStudent(ifstream *outf)
    {
        Student temp;
        while (!outf->eof())
        {
            outf->read(reinterpret_cast<char *>(&temp), sizeof(temp));
            if (this->id == temp.id && this->marks == temp.marks)
            {
                return true;
            }
            return false;
        }
    }
};

istream &operator>>(istream &in, Student &obj)
{
    cout << "Enter your ID:" << endl;
    cin >> obj.id;
    cout << "Enter your Marks:" << endl;
    cin >> obj.marks;
    return in;
}
ostream &operator<<(ostream &print, const Student &obj)
{
    cout << "ID:" << obj.id << endl;
    cout << "Marks:" << obj.marks << endl;
    return print;
}

int main()
{
    Student a1(1, 2), a2(9, 8), a3(5, 7), temp;
    ofstream outf("test.dat", ios::binary);
    if (!outf)
    {
        cerr << "FILE IS NOT OPENED" << endl;
        exit(0);
    }
    cout << "File created" << endl;
    a1.addStudent(&outf);
    a2.addStudent(&outf);
    a3.addStudent(&outf);
    outf.close();
    ifstream inf("test.dat", ios::binary);
    if (!inf)
    {
        cerr << "FILE IS NOT OPENED" << endl;
        exit(0);
    }
    cout << "File created" << endl;
    cout << "Found Data/not-found data " << temp.findStudent(&inf) << endl;
    Student::displayAllStudent(&inf);
    inf.close();
    ifstream inf1("test.dat", ios::binary);
    if (!inf1)
    {
        cerr << "file is open" << endl;
        exit(0);
    }
    if(a3.findStudent(&inf))
    {
        cout<<"true";
    }
    cout << "File created" << endl;
    Student::displayAllStudent(&inf);
    inf.close();

    return 0;
}