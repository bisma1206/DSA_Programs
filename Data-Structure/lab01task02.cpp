#include "iostream"
#include "fstream"
#include "string"
using namespace std;
int main()
{
    ifstream in("student.txt");
    string str;
    getline(in, str);
    while (getline(in, str))
    {
        cout << str << endl;
    }
    in.close();
    return 0;
}