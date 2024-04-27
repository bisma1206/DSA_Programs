#include "iostream"
#include "string"
using namespace std;
template <class T>
class Stack
{
private:
    // data members
    T *data;
    int top;
    const int MAX_SIZE;

public:
    Stack(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
    {
        // constructor
        data = new T[MAX_SIZE];
        top = -1;
    }
    // Destructor
    ~Stack()
    {
        delete[] data;
    }
    // stack operation
    void push(const T newitem)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack is full." << endl;
        }
        else
        {
            top = top + 1;
            *(data + top) = newitem;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack overflow" << endl;
        }
        else
        {
            top--;
        }
    }
    void clear()
    {
        top = -1;
    }
    // stack accessor
    T getTop() const
    {
        if (!isEmpty())
        {
            return data[top];
        }
        else
        {
            cout << "stack is empty" << endl;
        }
    }
    bool isEmpty() const
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull() const
    {
        if (top == MAX_SIZE - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void showStructure() const
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << "output is:" << data[i] << endl;
            }
        }
    }
};
int main()
{
    Stack<float> B;
    Stack<float> B1;
    B.push(5.0);
    B.push(6.5);
    B.showStructure();

    B.push(-3.0);
    B.push(-8.0);
    B.showStructure();

    cout << "After pop" << endl;
    B.pop();
    B.pop();
    B.showStructure();

    return 0;
}