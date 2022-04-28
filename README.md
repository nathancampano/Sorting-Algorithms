<h1 align="center"> CSC212 Final Project </h1>

<h2 align="center"> Spring 2022 </h2>

<h3 align="center"> Contributers: Brendon Lorena, Ezekiel Velasquez, Emmanuel Bazile, Nathan Campano </h3>


<h2 align="center"> Our Project: Sorting Algorithms </h2>
For our final project we chose to implement four different sorting algorithms, three of which we talked about in class this semester and one of our choosing. Those three from class being Insertion Sort, Merge Sort, and Quick Sort while we all decided on having Stooge Sort be our fourth and final sorting algorithm. Not only was our task to implement these sorting algorithms but we also had to benchmark their runtimes using different sizes and forms of data sets, for example, a large reversed set of data, a short, sorted set of data, etc...
 

### **How to Compile and Run the Program**
Running and compiling our program is simple! To compile, one only needs to use the standard c++ format with the single program, in this case, Sorting_Algs.cpp. When the code is ran, it opens up a terminal window on the end user's device to which they get welcomed and prompted to either input data manually or from a text file. 

From there, if the end user decides to input data from a text file, they input their file name and are then prompted with four choices, Insertion Sort, Merge Sort, Quick Sort, or Stooge Sort. <b><em> To select a sort </b></em> one must input the corresponding number of the sort, i.e. 1 for Merge Sort.

After selecting a sort, it returns to the user the array of data before sorting and then after sorting alongside the runtimes of the sort from nanoseconds up to seconds. Next, another prompt appears asking the user whether or not they would like to output the newly sorted array into a file. If no, one can choose to either continue or end the program by answering another prompt that appears. If yes, one can simply name the ouput file and then once again is asked if they would like to continue or end. 
