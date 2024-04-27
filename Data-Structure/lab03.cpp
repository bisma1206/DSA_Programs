#include "iostream"
#include "string"
using namespace std;
struct Point3D
{
    float x, y, z;
};
class PointList
{
private:
    Point3D *array;
    int maxSize;
    int curSize;
    int cursor;

public:
    // constructor
    PointList(int maxsize)
    {
        this->maxSize = maxSize;
        this->curSize = 0;
        this->cursor = -1;
        array = new Point3D[maxSize];
    }
    // Destructor
    ~PointList()
    {
        delete[] array;
    }
    // isEmpty
    bool isEmpty() const
    {
        return curSize == 0;
    }
    // isFull
    bool isFull() const
    {
        return curSize == maxSize;
    }
    // insert
    void insert(Point3D newPoint)
    {
        if (!isFull())
        {
            if (isEmpty())
            {
                cursor = 0;
            }
            else
            {
                cursor = curSize;
            }
            array[cursor] = newPoint;
            curSize++;
        }
    }
    // showstructure
    void showStructure() const
    {
        if (isEmpty())
        {
            cout << "Empty List.." << endl;
        }
        else
        {
            for (int i = 0; i < curSize; i++)
            {
                cout << "point: " << array[i].x << array[i].y << array[i].z << endl;
            }
        }
    }
    // getcursor
    Point3D getCursor() const
    {
        if (!isEmpty())
        {
            return array[cursor];
        }
        else
        {
            cout << "ERROR LIST IS EMPTY." << endl;
            return Point3D{-1, -1, -1};
        }
    }
    // goto beginning
    void gotoBeginning()
    {
        if (!isEmpty())
        {
            cursor = 0;
        }
    }
    // goto end
    void gotoEnd()
    {
        if (!isEmpty())
        {
            cursor = curSize - 1;
        }
    }
    // goto Next
    bool gotoNext()
    {
        if (cursor < curSize - 1)
        {
            cursor++;
            return true;
        }
        else
        {
            return false;
        }
    }
    // goto prior
    bool gotoPrior()
    {
        if (cursor > 0)
        {
            cursor--;
            return true;
        }
        else
        {
            return false;
        }
    }
    // clear
    void clear()
    {
        curSize = 0;
        cursor = -1;
    }
    // replace
    bool replace(Point3D newPoint)
    {
        if (cursor >= 0 && cursor < curSize)
        {
            array[cursor] = newPoint;
            return true;
        }
        else
        {
            return false;
        }
    }
    // remove
    void remove()
    {
        if (!isEmpty())
        {
            for (int i = cursor; i < curSize - 1; i++)
            {
                array[i] = array[i + 1];
            }
            curSize--;
            if (curSize == 0)
            {
                cursor = -1;
            }
            else if (cursor == curSize)
            {
                cursor = 0;
            }
        }
    }
};
int main()
{
    PointList l(7);
    Point3D p = {3.0, 4.0, 5.0};
    Point3D p1 = {6.0, 7.0, 8.0};
    Point3D p3 = {16.0, 17.0, 18.0};
   
    l.insert(p);
    l.insert(p1);
    l.insert(p3);
  
    cout << "LIST CONTENTS:" << endl;
    l.showStructure();
    cout << "position of cursor: ";
    Point3D cursorPoint = l.getCursor();
    cout << cursorPoint.x << "," << cursorPoint.y << "," << cursorPoint.z << endl;
    // l.gotoBeginning();
    // cout << "cursor position after moving:" << endl;
    // Point3D cursorpoint = l.getCursor();
    // cout << cursorPoint.x << "," << cursorPoint.y << "," << cursorPoint.z << endl;
    //  l.gotoNext();
    // {
    //     if (l.gotoNext())
    //     {
    //         cout << "cursor move to the next point" << endl;
    //     }
    //     else
    //     {
    //         cout << "cursor at the end" << endl;
    //     }
    //     l.showStructure();
    // }
    // l.gotoEnd();
    // cout << "after moving:" << endl;
    // cursorPoint = l.getCursor();
    // cout << cursorPoint.x << "," << cursorPoint.y << "," << cursorPoint.z << endl;
    // l.showStructure();
    // l.gotoPrior();
    // {
    //     if(l.gotoPrior())
    //     {
    //         cout<<"move previous point"<<endl;

    //     }
    //     else
    //     {
    //         cout<<"cursor at the start"<<endl;
    //     }
    //     l.showStructure();
    // }
  
   
    // if(l.replace(p3)){
    //     cout<<"successfully replaced"<<endl;
    // }
    // else
    // {
    //     cout<<"failed to replace"<<endl;
    
    // }
    // l.showStructure();

    // l.remove();
    // cout<<"list removed"<<endl;
    // l.showStructure();
    // l.clear();
    // cout<<"list is empty"<<endl;
    // l.showStructure();

    return 0;
}