#include "iostream"
#include "fstream"
using namespace std;
int main()
{
    ofstream outf("test.txt");
   
    if (!outf)
    {
        cerr << ("File Creation Filed") << endl;
        exit(0);
    }
    cout << "OK" << endl;
    outf << "Hello World" << endl;
    outf << "Hello World" << endl;
    //outf.open ("test.txt");
    outf.close();

    return 0;
}