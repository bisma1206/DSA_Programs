#include "iostream"
#include "fstream"
#include "string"
using namespace std;
int ArrayToFile(string name, int *array, int size)
{
    ofstream outf(name, ios::binary);
    if (!outf)
    {
        cout << "FILE IS NOT OPENED" << endl;
        exit(0);
    }
    else
    {
        outf.write(reinterpret_cast<char *>(array), size);
    }
    outf.close();
}

int FileToArray(string name, int *array, int size)
{
    ifstream in(name, ios::binary);
    if (!in)
    {
        cout << "FILE IS NOT OPENED" << endl;
        exit(0);
    }
    else
    {
        in.read(reinterpret_cast<char *>(array), size);
    }
    in.close();
}
int main()
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // ArrayToFile("f.dat", array, 10);
    FileToArray("f.dat", array, 10);
    // for (int i = 0 ; i < 10 ; i++)
    // {
    //     cout<<array[i]<<endl;
    // }
    cout.write(reinterpret_cast<char *>(array), 10);

    return 0;
} 