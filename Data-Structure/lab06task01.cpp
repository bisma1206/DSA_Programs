                        //Task 01
#include "iostream"
using namespace std;
int intersection1(int A[], int B[], int C[], int n)
{
    int count=0;
    int i=0;
    int j=0;
    while(i<n&&j<n)
    {
        if(A[i]==B[j])
        {
            C[count++]=A[i];
            i++;
            j++;
        }
        else if (A[i]<B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        
    }
    return count;
}
   
   int intersection2(int A[], int B[], int C[], int n)
{
    int count=0;
    int i=0;
    int j=0;
    while(i<n&&j<n)
    {
        if(A[i]<B[j])
        {
            i++;
        
        }
        else if (A[i]>B[j])
        {
            j++;
        }
        else
        {
            C[count++]=A[i];
            i++;
            j++;
        }
        
    }
    return count;
}
int main()
{
    int A[]={4,7,9,3,6};
    int B[]={1,2,5,10,9};
    int C[8];
    cout<<"Intersection is:"<<intersection1<<endl;
    cout<<"Sorted array Intersection is :"<<intersection2<<endl;

    return 0;
}
   