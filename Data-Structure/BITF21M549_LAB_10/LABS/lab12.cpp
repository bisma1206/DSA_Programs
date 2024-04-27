#include <iostream>
#include <cmath>
using namespace std;

class Student {
    friend class StudentMaxHeap;

private:
    double cgpa; // Student’s CGPA
    int rollNo;   // Student’s roll number

public:
    // Default constructor
    Student() : rollNo(0), cgpa(0.0) {}

    // Parameterized constructor
    Student(int roll, double gpa) : rollNo(roll), cgpa(gpa) {}
};

class StudentMaxHeap {
private:
    Student* arr;  // Array of students which, arranged like a Max Heap
    int curSize;   // Current number of students present in the heap
    int maxSize;   // Maximum number of students that can be present in heap

public:
    StudentMaxHeap(int size) : maxSize(size), curSize(0) {
        arr = new Student[size];
    }

    ~StudentMaxHeap() {
        delete[] arr;
    }

    bool isEmpty() const {
        return curSize == 0;
    }

    bool isFull() const {
        return curSize == maxSize;
    }

    bool insert(int rollNo, double cgpa) {
        if (isFull()) {
            return false;
        }

        arr[curSize] = Student(rollNo, cgpa);
        heapifyUp(curSize);
        curSize++;

        return true;
    }

    bool remove(int& rollNo, double& cgpa) {
        if (isEmpty()) {
            return false;
        }

        rollNo = arr[0].rollNo;
        cgpa = arr[0].cgpa;

        arr[0] = arr[curSize - 1];
        curSize--;

        heapifyDown(0);

        return true;
    }

    void displayStudentList() const {
        StudentMaxHeap tempHeap(maxSize);

        for (int i = 0; i < curSize; i++) {
            tempHeap.insert(arr[i].rollNo, arr[i].cgpa);
        }

        while (!tempHeap.isEmpty()) {
            int rollNo;
            double cgpa;
            tempHeap.remove(rollNo, cgpa);
            cout << "Roll No: " << rollNo << ", CGPA: " << cgpa << endl;
        }
    }

    void levelOrder() const {
        int h = ceil(log2(curSize + 1));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < (1 << i) && j + (1 << i) - 1 < curSize; j++) {
                int index = j + (1 << i) - 1;
                cout << arr[index].rollNo << " " << arr[index].cgpa << " ";
            }
            cout << endl;
        }
    }

private:
    void heapifyUp(int index) {
        while (index > 0 && arr[parent(index)].cgpa < arr[index].cgpa) {
            swap(arr[parent(index)], arr[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int maxIndex = index;
        int leftChildIndex = leftChild(index);
        int rightChildIndex = rightChild(index);

        if (leftChildIndex < curSize && arr[leftChildIndex].cgpa > arr[maxIndex].cgpa) {
            maxIndex = leftChildIndex;
        }

        if (rightChildIndex < curSize && arr[rightChildIndex].cgpa > arr[maxIndex].cgpa) {
            maxIndex = rightChildIndex;
        }

        if (index != maxIndex) {
            swap(arr[index], arr[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    int parent(int index) const {
        return (index - 1) / 2;
    }

    int leftChild(int index) const {
        return 2 * index + 1;
    }

    int rightChild(int index) const {
        return 2 * index + 2;
    }
};

void menu(StudentMaxHeap& maxHeap) {
    int choice;
    do {
        cout << "1. Insert a new student\n";
        cout << "2. Remove (and display) the student with the Max CGPA\n";
        cout << "3. Display the list of students (Descending order of CGPA)\n";
        cout << "4. Display the list of students (Level-order traversal)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int rollNo;
            double cgpa;
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            if (maxHeap.insert(rollNo, cgpa)) {
                cout << "Student record inserted successfully!\n";
            } else {
                cout << "Failed to insert student record. Heap is full.\n";
            }
        } else if (choice == 2) {
            int rollNo;
            double cgpa;
            if (maxHeap.remove(rollNo, cgpa)) {
                cout << "Removed student: Roll No = " << rollNo << ", CGPA = " << cgpa << endl;
            } else {
                cout << "Heap is empty. Cannot remove student.\n";
            }
        } else if (choice == 3) {
            cout << "List of students (Descending order of CGPA):\n";
            maxHeap.displayStudentList();
        } else if (choice == 4) {
            cout << "Level order traversal of students:\n";
            maxHeap.levelOrder();
        } else if (choice == 5) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);
}

int main() {
    int maxSize;
    cout << "Enter the maximum number of students that can be present in the heap: ";
    cin >> maxSize;

    StudentMaxHeap maxHeap(maxSize);
    menu(maxHeap);

    return 0;
}
