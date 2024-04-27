#include "iostream"
#include "string"
using namespace std;
template <class T>
class Queue
{
private:
    // data members
    T *data;
    int front;
    int rear;
    const int MAX_SIZE;

public:
    
        Queue(const int MAX_SIZE = 5) : MAX_SIZE(MAX_SIZE)
        {
            data = new T[MAX_SIZE];
            front = -1;
            rear = -1;
        }
        ~Queue()
        {
            delete[] data;
        }
        void enQueue(const T newItem)
        {
            if ((rear + 1) % MAX_SIZE == front)
            {
                cout << "stack is full" << endl;
            }
            else
            {
                if (front == -1)
                {
                    front = 0;
                }

                rear = (rear + 1) % MAX_SIZE;

                data[rear] = newItem;
            }
        }
        void deQueue()
        {
            if (front == -1)
            {
                cout << "stack is empty" << endl;
            }
            else
            {
                if (front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front = (front + 1) % MAX_SIZE;
                }
            }
        }
        void clear()
        {
            front = -1;
            rear = -1;
        }
        T getFront() const
        {
            return data[front];
        }
        T getRear() const
        {
            return data[rear];
        }
        bool isEmpty() const
        {
            if (front == -1 && rear == -1)
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
            if ((rear + 1) % MAX_SIZE == front)
            {
                return true;
            }
        }
        void showStructure() const
        {
            if (front == -1 && rear == -1)
            {
                cout << "empty Queue" << endl;
            }
            else
            {
                for (int i = front; i <= rear; i++)
                    cout << "output is:"<< data[i] << endl;
            }
        }
    
};
int main()
{
    Queue<float> B;
    B.enQueue(5.0);
    B.enQueue(6.5);
    B.showStructure();

    B.enQueue(-3.0);
    B.enQueue(-8.0);
    B.showStructure();

    cout << "After deQueue" << endl;
    B.deQueue();
    B.deQueue();
    B.showStructure();

    return 0;
}