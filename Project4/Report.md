# Project 4 Report

Answer the following prompts directly in this file:
* Information about your dataset (you will be assigned a different grader for this project).
* Analyze the data. Graph the number of reads and allocations for each sorting algorithm and look at how the number of reads and allocations grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.
* Look at the output from the stabilityTest function and answer the following questions:
  * How are the names sorted by default?
  * How is the output from the two stable sorting algorithms different from the two unstable ones? Be specific in your answer, and use what you know about how each sorting algorithm works to justify your observations.
* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 
  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

Reads Analysis: 
- Bubble Sort: The 𝑂(n^2) time complexity of the dataset is indicated by the dramatic increase in reads as its size increases. It is what we had anticipated.
- Heap Sort: In line with its 𝑂(nlogn) time complexity, the number of reads increases far more slowly than with Bubble Sort.
Because of its efficiency, it may be used with larger datasets.
- Quick Sort's usual O(nlogn) performance under worst-case conditions is indicated by a notable rise in reads, especially at larger data sizes.
Because more operations are required to ensure stability, Stable Quick Sort uses more reads than Unstable Quick Sort, resulting in a larger total count of reads.
Allocations Analysis: 
- Bubble Sort: Allocations do not increase exponentially, but they are continuously high in relation to dataset size.
- Heap Sort: Minimal allocations compared to reads, showcasing its efficient use of space.
- Unstable Quick Sort: Zero additional allocations, which is characteristic of its in-place nature.
- Stable Quick Sort: Shows significant allocations matching the number of reads, illustrating the extra space used to ensure stability.
- Observations
- Efficiency Comparison: Heap Sort is more efficient in terms of both reads and allocations, while Stable Quick Sort has the highest allocations due to maintaining stability.
- Complexities and Effects:
- Bubble Sort 𝑂(n^2) performs poorly as data size increases.
- Heap Sort 𝑂(nlogn)is efficient, balancing reads and allocations effectively.
Unstable Quick Sort 𝑂(nlogn) is fast but may degrade to 𝑂(n^2) in the worst-case scenarios without careful pivot selection.
Stable Quick Sort maintains stability but at the cost of increased memory usage.
Graphs
Visual representations of the data confirm these trends, showing that Heap Sort is consistently the most efficient for reads and allocations, while Bubble Sort exhibits the steepest growth in both metrics.

Stability Analysis
- Default Sorting: Names are typically sorted based on their ASCII values or inherent order if not explicitly specified by an algorithm.
Stable vs. Unstable Output:
- Stable Sorts (e.g., Stable Quick Sort): Maintain the relative order of duplicate elements, ensuring that elements with equal keys appear in the same order as they were in the input.
- Unstable Sorts (e.g., Unstable Quick Sort, Heap Sort): Do not guarantee this property, potentially rearranging duplicates arbitrarily.

Sorting Algorithm Recommendations
Contacts List (Mobile App)
Recommended Algorithm: Stable Quick Sort or a variant of Merge Sort.
Reasoning: Stability is crucial for maintaining the order of contacts with the same name or group identifier. A stable algorithm ensures that duplicates maintain their original order, providing a better user experience. Quick Sort, optimized for space and efficiency, works well for the smaller data sizes typical of mobile apps.
Large Database (20 Million Client Files)
Recommended Algorithm: Heap Sort or Quick Sort (Optimized for in-place).
Reasoning: For large-scale data sorting, algorithms with
𝑂(nlogn) complexity like Heap Sort are ideal due to their low space complexity. 
