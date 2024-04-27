#include "iostream"
#include "fstream"
using namespace std;
int main()
{
    ifstream in("input.txt");
    if(!in)
    {
        cerr<<"File creation is Failed"<<endl;

    }
    int value[11];
    int i=0;
    int maxi=0;
    while(in>>value[0]>>value[1]>>value[2]>>value[3]>>value[4]>>value[5]>>value[6]>>value[7]>>value[8]>>value[9]>>value[10])
    {
       for(int i=0;i<11;i++)
       {
        cout<<value[i]<<" ";
        if(i!=0 && value[i]>maxi)
        {
            maxi=value[i];

        }
        if(i==10)
        {
            cout<<maxi;
            maxi=0;
            cout<<endl;
        }
       }
        
    }

    in.close();
    return 0;
}