#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
    friend class StudentBST;

private:
    int id;
    string name;
    float fee;
    Student *left;
    Student *right;

public:
    Student(int studentId, string studentName, float studentFee) : id(studentId), name(studentName), fee(studentFee), left(nullptr), right(nullptr) {}
};
class StudentBST
{
private:
    Student *root;

public:
    StudentBST() : root(nullptr)
    {
    }
    ~StudentBST()
    {
        destroy(root);
    }
    bool insert(int id, string name, float fee)
    {
        if (root == nullptr)
        {
            root = new Student(id, name, fee);
            return true;
        }

        Student *curr = root;
        Student *parent = nullptr;

        while (curr != nullptr)
        {
            parent = curr;

            if (id < curr->id)
                curr = curr->left;
            else if (id > curr->id)
                curr = curr->right;
            else
                return false; // Duplicate id, not allowed
        }

        if (id < parent->id)
            parent->left = new Student(id, name, fee);
        else
            parent->right = new Student(id, name, fee);

        return true;
    }
void search(int id)
{
   Student* curr = root;

    while (curr != nullptr)
    {
        if (id == curr->id)
        {
            cout << "Student Found - ID: " << curr->id << ", Name: " << curr->name << ", Fee: " << curr->fee << endl;
            return;
        }
        else if (id < curr->id)
            curr = curr->left;
        else
            curr = curr->right;
    }

    cout << "Student not found with ID: " << id << endl; 
}
void inOrder()
{
    inOrder(root);
    cout << endl;
}
void preOrder()
{
   preOrder(root);
    cout << endl;
}
void postOrder()
{
    postOrder(root);
    cout << endl;
}
void remove(int id)
{
    root = remove(root, id);
}
private:
void inOrder(Student *stree)
{
     if (stree != nullptr)
    {
        inOrder(stree->left);
        cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
        inOrder(stree->right);
    }
}
void preOrder(Student *stree)
{
    if (stree != nullptr)
    {
        cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
        preOrder(stree->left);
        preOrder(stree->right);
    }
}
void postOrder(Student *stree)
{
     if (stree != nullptr)
    {
        postOrder(stree->left);
        postOrder(stree->right);
        cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
    }
}
void destroy(Student *stree)
{
     if (stree != nullptr)
    {
        destroy(stree->left);
        destroy(stree->right);
        delete stree;
    }
}
Student*remove(Student* stree, int id)
{
    if (stree == nullptr)
        return stree;

    if (id < stree->id)
        stree->left = remove(stree->left, id);
    else if (id > stree->id)
        stree->right = remove(stree->right, id);
    else
    {
        if (stree->left == nullptr)
        {
            Student* temp = stree->right;
            delete stree;
            return temp;
        }
        else if (stree->right == nullptr)
        {
            Student* temp = stree->left;
            delete stree;
            return temp;
        }

        Student* temp = findMin(stree->right);
        stree->id = temp->id;
        stree->name = temp->name;
        stree->fee = temp->fee;
        stree->right = remove(stree->right, temp->id);
    }

    return stree;
}

Student*findMin(Student* stree)
{
    while (stree->left != nullptr)
        stree = stree->left;

    return stree;
}

};
int main()
{
    ifstream inputFile("input.txt");
    int id;
    string name;
    float fee;

    StudentBST studentTree;

    while (inputFile >> id >> name >> fee)
    {
        if (!studentTree.insert(id, name, fee))
        {
            cout << "Duplicate ID found: " << id << ". Ignoring." << endl;
        }
    }

    cout << "In-Order Traversal:" << endl;
    studentTree.inOrder();

    cout << "Pre-Order Traversal:" << endl;
    studentTree.preOrder();

    cout << "Post-Order Traversal:" << endl;
    studentTree.postOrder();

    cout << "Searching for a student with ID 101:" << endl;
    studentTree.search(101);
    cout << "Removing a student with ID 12" << endl;
    studentTree.remove(12);

    cout << "In-Order Traversal after removal:" << endl;
    studentTree.inOrder();

    return 0;
}