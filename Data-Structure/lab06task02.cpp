                    //task 02
#include "iostream"
using namespace std;

int findKthSmallest(int A[], int n, int k) 
{
    if (k <= n && k > 0)
    {
        int maximum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maximum = i;
            for (int j = maximum + 1; j < n; j++)
            {
                if (A[maximum] < A[j])
                    maximum = j;
            }
            if (maximum != i)
                swap(A[maximum], A[i]);

        }
        int index = n - k;
        return A[index];

    }
}

int main() 
{
    int A[] = { 11, 3, 10, 7, 6, 4, 2 };
    int N = 2;
    int K = 1;

    int r = findKthSmallest(A, N, K);

    cout <<"Result is:"<< r<<endl;

    return 0;
}