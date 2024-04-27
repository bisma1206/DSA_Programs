#include "iostream"
using namespace std;
class Matrix
// Private data memebers
{
    int *data;
    int rows;
    int col;

public:
    // constructor
    Matrix(int R, int C)
    {
        rows = R;
        col = C;
        data = new int[rows * col];
       for(int i =0; i<rows*col; i++)
       {
        data[i]=0;
       }
    }
    // Destructor
    ~Matrix()
    {
        delete[] data;
    }
    // int get(int i, int j)
    int get(int i, int j) const
    {
        if (i >= 0 && i < rows && j >= 0 && j < col)
        {
            return data[i * col + j];
        }
        else
        {
            cout << "Index out of bound" << endl;
            return -1; // indicating error
        }
    }
    // void set function
    void set(int i, int j, int v)
    {
        if (i >= 0 && i < rows && j >= 0 && j < col)
        {
            data[i * col + j]=v;
        }
        else
        {
            cout << "Index out of bound" << endl;
        }
    }

    //Print matrix in 2-d Form
    void print()const
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<"2D form is:"<<data[i*col+j]<<"\t"<<endl;
            }

        }
    }
    //void transpose
    void transpose()
    {
       int j=0;
       for(int i=0; i<rows; i++)
       {
        for(int j=0; j<col; j++)
        {
            cout<<"Transpose is:"<<data[i*col+j]<<"\t"<<endl;
        }
       }
    }
    //void subprint Matrix
    void printSubMatrix(int r1, int r2, int c1, int c2)
    {
        for(int i=r1;i<r2;i++)
        {
            for(int j=c1;j<=c2;j++)
            {
                if(i>=0 && i<rows && j>=0 && j<col)
                {
                    cout<<" "<<data[i * col + j]<<endl;
                }
                else
                {
                    cout<<"ERROR"<<endl;
                }
            }

        }


    }
    //void makeempty
    void makeEmpty(int n)
    {
        if(n<=rows && n<=col)
        {
             for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                data[i*col+j]=0;
                
            }

        }
        else
        {
            cout<<"error"<<endl;
        }
    }
    //adding matrix
    void addMatrix(Matrix First,Matrix Second)
    {
        if(First.rows==rows && First.col==col && Second.rows==rows && Second.col==col)
         for(int i=0;i<rows;i++)
            {
                for(int j=0;j<col;j++)
                {
                     data[i*col+j]=First.data[i*col+j]+Second.data[i*col+j];
                }
                
            }
            else
            {
                cout<<"Error"<<endl;
            }

    }
};
int main()
{
    Matrix m(3,3);
    m.set(1,0,0);
    m.set(0,1,0);
    m.set(0,0,1);
    m.set(2,0,1);
    m.set(2,2,9);
    m.set(2,0,7);
    cout<<"Matrix:"<<endl;
    m.print();
    m.transpose();
    m.print();
    m.addMatrix(m,m);
    cout<<"Addition:"<<endl;
    m.print();
    return 0;
}
