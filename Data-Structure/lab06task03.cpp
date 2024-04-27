                        //Task 03
#include "iostream"
#include "fstream"
#include "string"
using namespace std;

void countWordOccurrences(const string& filename, const string& Word) 
{
    ifstream input3(filename);
    if (!input3.is_open()) 
    {
        cerr << "File is not open." << endl;
        exit(0);
    }

    string line;
    int lineCount = 0;

    while (getline(input3, line)) {
        lineCount++;
        size_t position = 0;
        int wordCount = 0;

        while ((position = line.find(Word, position)) !=-1) 
        {
            wordCount++;
            position ++;
        }

        cout << "Line " << lineCount << ": " << wordCount << endl;
    }

    input3.close();
}

int main() {
    string filename = "input3.txt";  
    string Word;
    // cout << "Enter the word to be find: ";
    // cin >> Word;

    countWordOccurrences(filename,Word);

    return 0;
}