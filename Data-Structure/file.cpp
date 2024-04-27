#include "iostream"
#include "fstream"
#include "cstdio"
using namespace std;

int main() {
    const char* filename = "output.txt";

    // Open the file for writing (formatted output)
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Write data to the file
    outFile << "This is some data.\n";
    outFile << "12345\n";
    outFile << "3.14\n";

    // Close the file
    outFile.close();

    std::cout << "Data written to the file." << std::endl;

    return 0;
}
