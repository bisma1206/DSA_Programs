#include "iostream"
#include "fstream"
using namespace std;
int main()
{
    ofstream outf("student.txt");

    if (!outf)
    {
        cerr << ("File Creation Filed") << endl;
    }
    int RollNo;
    string FirstName;
    string LastName;
    float Marks;
    cout << "Enter your Roll no:" << endl;
    cin >> RollNo;
    cout << "Enter your First Name:" << endl;
    cin >> FirstName;
    cout << "Enter your Last Name:" << endl;
    cin >> LastName;
    cout << "Enter your Marks:" << endl;
    cin >> Marks;
    while (int(RollNo) != -999)
    {
         outf << RollNo << " " << FirstName << " " << LastName << " " << Marks << " " << endl;
        cout << "Enter your Roll no:" << endl;
        cin >> RollNo;
        if(RollNo==-999)
        break;
        cout << "Enter your First Name:" << endl;
        cin >> FirstName;
        cout << "Enter your Last Name:" << endl;
        cin >> LastName;
        cout << "Enter your Marks:" << endl;
        cin >> Marks;

       
    }
    outf.close();

    return 0;
}