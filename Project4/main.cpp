#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>  // For filesystem operations
#include <iomanip>
#include "sorting-algorithms/bubbleSort.h"
#include "sorting-algorithms/heapSort.h"
#include "sorting-algorithms/insertionSort.h"
#include "sorting-algorithms/mergeSort.h"
#include "sorting-algorithms/quickSort.h"
#include "sorting-algorithms/radixSort.h"
#include "sorting-algorithms/selectionSort.h"
#include "stability-test/contactsList.h"

using namespace std;

void stabilityTest();

std::vector<std::string> parseCSVLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string field;
    bool inQuotes = false;

    for (char ch : line) {
        if (ch == '\"') {
            inQuotes = !inQuotes;  // Toggle in/out of quotes
        } else if (ch == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        } else {
            field += ch;
        }
    }

    if (!field.empty()) {
        fields.push_back(field);  // Add the last field
    }
    return fields;
}

int main() {
    // Debug: print the current working directory
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

    // Step 1: Load movies data from CSV
    std::string filePath = "../movies.csv";

    // Check if file exists
    if (!std::filesystem::exists(filePath)) {
        return 1;
    }

    std::ifstream file(filePath);
    std::vector<std::vector<std::string>> moviesData;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> parsedLine = parseCSVLine(line);
        moviesData.push_back(parsedLine);
    }

    file.close();
    std::cout << "Loaded " << moviesData.size() << " movies from CSV." << std::endl;

    // Step 2: Open CSV file for saving results
    std::ofstream outputFile("sorting_results.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening CSV file for writing." << std::endl;
        return 1;
    }

    // Write the CSV headers
    outputFile << "Movie Count,Sorting Algorithm,Reads,Allocations" << std::endl;

    // Step 3: Sort with different vector sizes and save results to CSV
    for (int size = 1000; size >= 100; size -= 100) {
        std::vector<std::vector<std::string>> tempData(moviesData.begin(), moviesData.begin() + size);
        cout << "Sorting " << size << " movies." << endl;

        unsigned long reads = 0, allocations = 0;

        // Bubble Sort
        tempData = bubbleSort(tempData, reads, allocations);
        outputFile << size << ",Bubble Sort," << reads << "," << allocations << std::endl;

        reads = allocations = 0;  // Reset counts
        // Heap Sort
        tempData = heapSort(tempData, reads, allocations);
        outputFile << size << ",Heap Sort," << reads << "," << allocations << std::endl;

        reads = allocations = 0;  // Reset counts
        // Unstable Quick Sort
        tempData = quickSortUnstable(tempData, reads, allocations);
        outputFile << size << ",Unstable Quick Sort," << reads << "," << allocations << std::endl;

        reads = allocations = 0;  // Reset counts
        // Stable Quick Sort
        tempData = quickSortStable(tempData, reads, allocations);
        outputFile << size << ",Stable Quick Sort," << reads << "," << allocations << std::endl;
    }

    outputFile.close();
    std::cout << "Sorting results saved to 'sorting_results.csv'" << std::endl;

    stabilityTest();  // Run stability tests
    return 0;
}

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../names.csv");  // Use relative path
    cout << "People (Default ordering)" << endl;
    people.printList();

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>);

    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>);

    cout << endl << "Unstable Quick Sort" << endl;
    people.sortAndPrint(quickSortUnstable<contact>);

    cout << endl << "Stable Quick Sort" << endl;
    people.sortAndPrint(quickSortStable<contact>);
}
