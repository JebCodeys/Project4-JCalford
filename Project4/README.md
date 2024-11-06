# CS 2240 Project 4

For this project, you will sort the 1000 objects from your data set. You will modify each sorting algorithm to collect data. You will analyze the results from the different sorting algorithms. You will test the stability of each algorithm.

## Implement
You should have your 1000+ objects stored in a vector, initially unsorted. Your custom class should overload all comparison operators, and you can compare them based on any field you like (it doesn't have to be a unique field).

Use these sorting algorithms:
1. Bubble Sort
1. At least one more stable sorting algorithm*
1. Heap Sort
1. At least one more unstable sorting algorithm*

\*At least one of these two must have non-constant auxiliary complexity.

Modify each sorting algorithm to record the number of **reads**. This is the number of times you **use a Comparable object**. This could be using it to store somewhere else, using it to compare to another object, etc. Temporary Comparable objects count towards the reads. 
* Example code:
  ```cpp
  if (vec[i] > vec[i+1]) // This counts as two reads, which should
      // be counted whether the if statements evaluates to true or false.
  Comparable temp = vec[i]; // This is one read (of vec[i]).
  vec[i] = vec[i+1]; // This is one read (of vec[i+1]).
  smaller.push_back(vec[i]); // This is one read (of vec[i]).
  n = items.size(); // This doesn't count as any reads because it's getting 
      // vector metadata and not accessing a specific Comparable value.
  // The next line doesn't count as any reads because it is comparing
  // integers and we only count Comparable objects.
  if (child != n - 1)
  ```
Modify each sorting algorithm to record the number of **allocations**. This is the number of **bytes of temporary memory** declared inside the functions. You should use the `sizeof` function built into C++ to get the number of bytes that a data type is allocated.
* Example code:
  ```cpp
  int numPasses = 0, i; // This allocates 2 * sizeof(int).
  Comparable temp;      // This allocates sizeof(Comparable).
  // You don't have to count the vector that's passed in by value
  // because that's only for the format of this project. You would
  // normally pass the vector in by reference.
  vector<Comparable> bubbleSort(vector<Comparable> vec)
  // The line below allocates 2 * sizeof(int) because you only count 
  // the parameters passed in by value. You can count this either at 
  // the beginning of the body of the function or wherever the function 
  // is called (but not both, that would be overcounting).
  void mergeSortRec(vector<Comparable> &vec, 
                    int startIndex, 
                    int endIndex, 
                    unsigned long& reads, 
                    unsigned long& allocations)
  // You don't have to count anything for lines that declare empty vectors.
  vector<Comparable> temp; 
  // The next line allocates sizeof(Comparable)
  smaller.push_back(vec[i]); 
  ```
Use a loop to record the number of reads and allocations needed to sort a vector of size 100, 200, 300, 400, 500, 600, 700, 800, 900, and 1000.
* Hint: start with 1000 and then use the vector resize method to make it smaller. 

Each of the sorting algorithms should be given identical unsorted vectors to begin with. 
* Note that the starter code passes the vector to each sorting algorithm by value (not by reference). This means that calling one of the sorting algorithms from the main function will *not* modify the vector in main that you pass to the function.
* If your data is naturally sorted by the attribute you use to overload your operators, change how you overload your operators.

Finally, the starter code includes a function in main.cpp called `stabilityTest`. **Do not modify the contactsList.h file. The stability test is not run on your custom data type, it is run on the provided contacts list of ten names.** The `stabilityTest` function is set up for bubble sort and heap sort. Add your other two sorting functions and observe the output critically. You will be asked to analyze the output in your report.

## Extra Credit
To earn up to 10 extra credit points (at the grader’s discretion), you can get more thorough results. This can include, but is not limited to:
* Setting timers to record how long it takes you to sort the objects with each algorithm.
* Performing the same experiment, except double the size of the data set each time (instead of having it grow linearly).
* Using more than four sorting algorithms. This includes storing and graphing the read and allocation counts, adding the algorithm(s) to the `stabilityTest` function, and including the algorithm(s) in the answers to the questions in the report.

Note that if you add this logic to your code but do not analyze it in your report, it will not count towards extra credit. If you complete extra credit, clearly label it in your Report.md file.

## Report
You must write a report for this project. Answer the prompts in the Report.md file.

## Submit
You must include your source (all .cpp and .h) files, your data (.csv) file(s), CMakeLists.txt, and your updated Report.md file to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Grading
The project is out of 90 points.

| Points Possible | Description of requirement                                                       |
|-----------------|----------------------------------------------------------------------------------|
| 5 pts           | Program compiles and runs.                                                       |
| 5 pts           | Code style. Readable, naming style is consistent, comments where appropriate.    |
| 8 pts           | Use four sorting algorithms according to the directions above.                   |
| 15 pts          | Sort the 100, 200, … 1000 objects according to the directions above.             |
| 32 pts          | Record the correct number of reads and allocations for each sort.                |
| 25 pts          | Report: content, formatting, professional, grammatically correct, cites sources. |