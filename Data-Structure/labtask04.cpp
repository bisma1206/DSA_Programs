#include "iostream"
#include "fstream"
using namespace std;
int main()
{
    ifstream in("input.txt");
    ofstream outf("output1.txt");

    if(!in || !outf)
    {
        cerr<<"File creation is Failed"<<endl;

    }
    int value[11];
    int i=0;
    int maxi=0;
    int min=0;
    while(in>>value[0]>>value[1]>>value[2]>>value[3]>>value[4]>>value[5]>>value[6]>>value[7]>>value[8]>>value[9]>>value[10])
    {
       for(int i=0;i<11;i++)
       {
        cout<<value[i]<<" ";
        if(i!=0 && value[i]>maxi)
        {
            min=maxi;
            maxi=value[i];

        }
      else if(maxi<min)
      {
       min=maxi;
      }
        if(i==10)
        {
            cout<<"high"<<maxi<<endl;
            cout<<"low"<<min<<endl;
            
            maxi=0;
            min=0;
            cout<<endl;
        }
       }
        
    }

    in.close();
    return 0;
}