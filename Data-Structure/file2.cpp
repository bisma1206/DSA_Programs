#include <iostream>
#include <cstdio>

int main() {
    const char* filename = "output.dat";

    // Open the file for writing in binary mode
    FILE* outFile = fopen(filename, "wb");

    if (outFile == nullptr) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    int numbers[] = {1, 2, 3, 4, 5};

    // Write data to the file
    std::size_t num_elements = sizeof(numbers) / sizeof(numbers[0]);
    fwrite(reinterpret_cast<const char*>(&numbers[0]), sizeof(int), num_elements, outFile);

    // Close the file
    fclose(outFile);

    std::cout << "Data written to the file." << std::endl;

    // Open the file for reading in binary mode
    FILE* inFile = fopen(filename, "rb");

    if (inFile == nullptr) {
        std::cerr << "Error opening file for reading." << std::endl;
        return 1;
    }

    // Allocate memory to read the file
    int* read_numbers = new int[num_elements];

    // Move the file pointer to the beginning of the file
    fseek(inFile, 0, SEEK_SET);

    // Read data from the file
    fread(reinterpret_cast<char*>(read_numbers), sizeof(int), num_elements, inFile);

    // Close the file
    fclose(inFile);

    std::cout << "Data read from the file:" << std::endl;
    for (std::size_t i = 0; i < num_elements; ++i) {
        std::cout << read_numbers[i] << " ";
    }
    std::cout << std::endl;

    // Don't forget to release the allocated memory
    delete[] read_numbers;

    return 0;
}

