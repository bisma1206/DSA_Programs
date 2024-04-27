                        // LAB-10
#include "iostream"
#include "fstream"
#include "string"

using namespace std;
class Book
{
    friend class BookList;

private:
    int id;
    string title;
    float price;
    Book *next;
    Book *prev;

public:
    Book(int id, string title, float price, Book *next = NULL, Book *prev = NULL)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->next = next;
        this->prev = prev;
    }
    void BookDetails()
    {
        cout << "id : " << id << endl;
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
    }
};

class BookList
{
private:
    Book *head;
    Book *cursor;
    Book *last;

public:
    BookList()
    {
        head = NULL;
        cursor = NULL;
        last = NULL;
    }
    void insert(const Book &newItem)
    {
        Book *temp = new Book(newItem);
        if (head == NULL)
        {
            head = temp;
            cursor = head;
            last = head;
        }
        else
        {
            Book *cur = head;
            if (cursor == last)
            {
                last->next = temp;
                temp->prev = last;
                last = temp;
            }
            else
            {
                temp->next = cursor->next;
                temp->prev = cursor;
                cursor->next = temp;
                temp->next->prev = temp;
            }
            cursor = temp;
        }
    }

    void search(string title)
    {
        bool value = false;
        if (head == NULL)
        {
            cout << "List is empty\n";
        }
        else if (head->title == title)
        {
            head->BookDetails();
        }
        else
        {
            Book *temp = head;
            while (temp->next != NULL)
            {
                if (temp->title == title)
                {
                    value = true;
                    temp->BookDetails();
                    break;
                }
                temp = temp->next;
            }
            if (value == false)
            {
                cout << "Title not found\n";
            }
        }
    }
    void replace(const Book &newItem)
    {
        if (cursor != NULL)
        {
            cursor->id = newItem.id;
            cursor->title = newItem.title;
            cursor->price = newItem.price;
        }
    }
    void remove()
    {
        if (cursor == NULL)
        {
            return;
        }
        Book *temp = cursor;
        if (cursor == head)
        {
            head = cursor->next;
            cursor = cursor->next;
            if (cursor != NULL)
            {
                cursor->prev = NULL;
            }
            else
            {
                cursor->prev->next = cursor->next;
                if (cursor != last)
                {
                    cursor->next->prev = cursor->prev;
                }
                else
                {
                    last = cursor->prev;
                    cursor = cursor->prev;
                }
            }
        }
        delete temp;
    }
    bool isEmpty() const
    {
        return head == NULL;
    }
    void gotoBegining()
    {
        cursor = head;
    }
    void gotoend()
    {
        cursor = last;
    }
    bool gotoNext()
    {
        if (cursor != NULL && cursor->next != NULL)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    Book getCursor()
    {
        return *cursor;
    }
    void showStructureForward()
    {
        Book *cur = head;
        if (head == NULL)
        {
            cout << "List is empty\n";
        }
        else
        {
            do
            {
                cur->BookDetails();
                cur = cur->next;
            } while (cur->next != NULL);
        }
    }
    void showStructureReverse()
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
        }
        else
        {
            Book *cur = last;
            do
            {
                cur->BookDetails();
                cur = cur->prev;

            } while (cur->prev != NULL);
        }
    }
    ~BookList()
    {
        Book *temp = head;
        while (temp != NULL)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};
int main()
{
    BookList obj;
    int id;
    string title;
    float price;
    ifstream imf("input.txt");
    if (!imf)
    {
        cout << "File didn't open\n";
    }
    else
    {
        while (imf >> id)
        {
            imf.ignore();
            getline(imf, title);
            imf >> price;

            Book b1(id, title, price);

            obj.insert(b1);

            imf.ignore();
        }
    }

        cout << "Forward\n\n";
    obj.showStructureForward();
    cout << "Reverse\n\n";
    obj.showStructureReverse();

    cout << "\n\nSearhcing\n\n";
    obj.search("C++");
    obj.search("Visual C#");

    cout << "\n\nInserting\n\n";
    Book b3(88, "Android", 78.3);
    Book b4(8, "Apple", 58.3);

    BookList obj2;
    obj2.insert(b3);
    obj2.insert(b4);

    obj2.replace(b4);
    obj2.showStructureForward();
    imf.close();

    // obj.remove();
    // obj.showStructureReverse();
    // obj.showStructureForward();
    return 0;
}