<h1 align="center"> CSC212 Final Project: Sorting Algorithms </h1>

<h2 align="center"> Spring 2022 </h2>

<h3 align="center"> Contributers: Brendon Lorena, Ezekiel Velasquez, Emmanuel Bazile, Nathan Campano </h3>




<h2 align="center"> Data Structure: Sorting Algorithms </h2>

Sorting algorithms can be seen as a quintessential part of data structures. A sorting algorithm rearranges data elements within an array or list in accordance with a comparison operator. The comparison operator determines why certain elements are in the new order within a data structure. In essence, sorting algorithms are methods to reorganize data sets or items into a specific order. Such orders consist of numerical values of high to low, distance between shortest to longest, or alphabetical order. The process in which the algorithm analyzes a data set by taking in a list of items as input data, reads it, and performs a specific operation based on the type of sorting algorithm used. After the operation is performed on the list of data, it is outputted as an ordered array. Sorting algorithms are used in numerous applications including but not limited to organizing medical documents, ecommerce and retail pricing, entertainment programming based on view time and engagements, determining relevant search engine results, and operational research.
 

### **File Descriptions**

#### 1. Sorting_Algs.cpp

"This file is..."
- it does this
- it does this
- it does this 

---

### **Methods**

#### 1. Print Vector Function 

This function was simply used by our group in order to print an array of whatever size input we put in manually or from a text file. This can be seen at the completion of our code since we either output the sorted data to a text file or we just display the data before running and after running, unsorted vs. sorted. 2

#### 2.  Insertion Sort Function 

The first sorting function we implemented into our program was the insertion sort function. We chose this as our first due to the ability to easily understand what is happening throughout the entire sorting process. To implement this specific type into our code we knew we had to, of course, include a method of tracking our runtime for the algorithm which resulted in our group using the <chrono> library. Specifically, we used the steady_clock function which represents a monotonic clock, a clock whose time points only increase and where the time between ticks is constant, making it the most suitable for measuring intervals. We then did the actual sorting by looking at the demo provided from lecture and building off that in our own way by instead using a while loop within our for loop. This function ends, which you’ll notice in the other sorts as well, by ending the clock, printing out the new sorted vector, and providing us with many different variables of speed starting from nanoseconds to seconds. 

#### 3.  Merge Sorted Intervals Function

Following insertion sort, our team decided to implement merge sort since it seemed to us to be the most complicated to understand conceptually, but in order to do so, we had to first implement this. Merge sort is considered a divide and conquer sort and so we have to first split our array in half. In the end, this function provided us the ability to merge our split arrays into one, sorted array after calling merge sort on both halves of the array.


#### 4. Merge Sort Function

Our second sorting function was merge sort. As previously stated, merge sort is a divide and conquer sorting algorithm. Because of this, we first had to use an equation to split our array in half and obtain the midpoint. Then we proceeded to call mergesort on the first half of the array, followed by the second. After doing so, we call the merge sorted interval function from above and that gives us our desired sorted array. 

#### 5. Partition Function

In order to implement the quicksort function, we first decided to create a partition function in order to simplify the amount of code in our quick sort function. Having a partition function made it so that we could select a needed pivot point, the last element in our case, and have it loop through and rearrange our input data into two partitions (subarrays). This is an essential part of quicksort since it allows us to divide and conquer the problem recursively, in the end sorting both subarrays and resulting in a fully sorted array. 


#### 6. Quick Sort Function

The third sorting function that was implemented was the quick sort function. To implement this sort, we had to use the partition function mentioned above. We made an int variable called p that was essentially used as our pivot point within our quicksort calls. The p variable was used to replace the end argument in the first quicksort call and we made it (p -1) in order to get the left side partition. Oppositely, we replaced the start argument with the p variable plus 1 (p + 1) in order to begin in the right partition and run it until the end (last element). Once again, giving us a sorted array. 

 
#### 7. Stooge Sort Function

Lastly, the sorting function we chose to implement that was not talked about in class was the stooge sort function. We honestly ended up choosing this sort because of its name but after researching it, we not only learned that it is one of the slowest sorting algorithms out there but also found that it was not going to be that hard to code. In order to implement this sort, we ended up resorting to just 2 if statements, one if statement to recursively sort the initial 2/3rd of the array, the last 2/3rd of the array, and once again the first 2/3rd of the array again and the second if statement to swap the first element with the last element in the array if the last element was a larger number than the first. 
 
#### 8. Save Vector to File Function
 
This function simply allows for the end user to be able to output the sorted array into a file. By passing in a vector of ints by reference, specifically the sorted array, it then prompts the user to decide whether or not they would like to output this sorted array into a file and if the user says yes, it asks them for an output name and does so.
 
#### 9. Merge Sort Algo, Quick Sort Algo, and Stooge Sort Functions

These final three functions in our code are what can be considered to be our end result givers. All three functions work exactly the same way in which they have an std::out saying “Before Sorting”, our Print Vector function, another std::out saying “After Sorting”, a steady clock start followed by the certain sort called and an end clock, our sorted array being printed out alongside the amount of time it took the code to run overall and finally our Save Vector to File function (explained above). 



### **Implementation: How to Compile and Run**

"$$$$Sample text: This project does not use a GUI, instead it relies on command line arguments for input and will spit out .txt files as an output.  Download the project, create a .txt file containing the sorting you are using into the SpMfile directory.  Now just update the main functions of COO.cpp and LlL.cpp to take in however many CLAs you want and what you want the to do with the lists that are created.""

### **Contribution**

Brendon Lorena:

*  
* 
* 

Ezekiel Velasquez:

*
*  
* 

Emmanuel Bazile:

*  
* 
* 

Nathan Campano:

*  
* 
* 

