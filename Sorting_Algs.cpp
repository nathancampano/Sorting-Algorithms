#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

void PrintVector(vector<int> empLoads);
void insertionSort(vector<int> &empLoads);
void MergeSortedIntervals(vector<int> &v, int s, int m, int e);
void MergeSort(vector<int> &v, int s, int e);
int Partition(vector<int> &v, int start, int end);
void Quicksort(vector<int> &v, int start, int end);
void StoogeSort(vector<int> &v, int start, int end);
void saveVectorToFile(vector<int> &v);
void MergeSortAlgo(vector<int> &empWorkLoads, int count);
void QuickSortAlgo(vector<int> &empWorkLoads);
void StoogeSortAlgo(vector<int> &empWorkLoads);

/* Driver code */
int main() {
	int number;
	cout << "Welcome!"<<endl;
	cout << "The application will sort sales data made by a company on a given number of days."<<endl;

	while (true) {
		char choice;
		vector<int> empWorkLoads;
		int count = 1;

		cout << "Enter 'f' to import data from a file or 'm' to manually input data.\n (When manually entering data use '-1' when finished)" << endl;
		cin >> choice;

		if (choice=='f' || choice=='F') {
			string filename = "";
			cout << "Enter file path:";
			cin >> filename;
			ifstream input_file(filename);
			if (!input_file.is_open()) {
				cout << "Could not open the file - '"
					<< filename << "'" << endl;
				
			}

			while (input_file >> number) {
				empWorkLoads.push_back(number);
			}
			cout << endl;
			input_file.close();
		}
		else {
			while (true) {
				cout << "\nEnter sales made on day " << count << " : ";
				cin >> number;
				
				if (number < 0) {
					break;
				}
				empWorkLoads.push_back(number);
				count++;
			}
		}
		
		int algoChoice;
		cout << "Please choose which algorithm you would like to sort the data:" << endl;
		cout << "1. Merge Sort." << endl << "2. Insertion Sort." << endl << "3. Quick Sort." << endl << "4. Stooge Sort." << endl;
		cin >> algoChoice;

		switch (algoChoice) {
		case 1:
			MergeSortAlgo(empWorkLoads, empWorkLoads.size());
			break;
		case 2:
			cout << "Before Sorting" << endl;
			PrintVector(empWorkLoads);
			cout << "\nAfter Sorting" << endl;
			insertionSort(empWorkLoads);
			saveVectorToFile(empWorkLoads);
			break;
		case 3:
			QuickSortAlgo(empWorkLoads);
			break;
		case 4:
			StoogeSortAlgo(empWorkLoads);
			break;
		default:
			cout << "Invalid choice"<<endl;
			break;
		}

		char _continue;
		cout << "\n\nWould you want to add more data? [y/n]";
		cin >> _continue;

		if (_continue == 'n' || _continue == 'N')
			break;
	}

	return 0;
}

// A utility function to print an array of size n
void PrintVector(vector<int> empLoads) {
	int i;

	for (i = 0; i < empLoads.size(); i++)
		cout << empLoads.at(i) << " ";
	cout << endl;
}

/* Function to sort vector using insertion sort*/
void insertionSort(vector<int> &empLoads) {
	auto start = chrono::steady_clock::now();
	int i, key, j;

	for (i = 1; i < empLoads.size(); i++) {
		key = empLoads[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && empLoads[j] > key) {
			empLoads[j + 1] = empLoads[j];
			j = j - 1;
		}
		empLoads[j + 1] = key;
	}

	auto end = chrono::steady_clock::now();
	PrintVector(empLoads);

	cout << "Elapsed time in nanoseconds: "
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds: "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec";
}

// the interval from [s to m] and [m+1 to e] in v are sorted
// the function will merge both of these intervals
// such the interval from [s to e] in v becomes sorted
void MergeSortedIntervals(vector<int> &v, int s, int m, int e) {
	// temp is used to temporary store the vector obtained by merging
	// elements from [s to m] and [m+1 to e] in v
	vector<int> temp;
	int i, j;
	i = s;
	j = m + 1;

	while (i <= m && j <= e) {
		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}
	}

	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}

	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}

	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<int> &v, int s, int e) {
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		MergeSortedIntervals(v, s, m, e);
	}
}

// last element is taken as pivot
int Partition(vector<int> &v, int start, int end) {
	int pivot = end;
	int j = start;

	for (int i = start; i < end; ++i) {
		if (v[i] < v[pivot]) {
			swap(v[i], v[j]);
			++j;
		}
	}
	swap(v[j], v[pivot]);

	return j;
}

void Quicksort(vector<int> &v, int start, int end) {
	if (start < end) {
		int p = Partition(v, start, end);
		Quicksort(v, start, p - 1);
		Quicksort(v, p + 1, end);
	}

}

// A function implementing stooge sort.
void StoogeSort(vector<int> &v, int start, int end) {
	int temp;

	// Further breaking the array if the Subpart's length is more than 2. 
	if (end - start + 1 > 2) {
		temp = (end - start + 1) / 3;
		StoogeSort(v, start, end - temp);
		StoogeSort(v, start + temp, end);
		StoogeSort(v, start, end - temp);
	}

	// swapping the element at start and end. 
	if (v[end] < v[start]) {
		temp = v[start];
		v[start] = v[end];
		v[end] = temp;
	}
}

//Save vector elements into file
void saveVectorToFile(vector<int> &v) {
	cout << "\n Would you like to export the sorted array into a file?[y/n]" << endl;
	char saveChoice;
	cin >> saveChoice;

	if (saveChoice == 'y' || saveChoice == 'Y') {
		fstream file;
		cout << "Enter file path: ";
		string path;
		cin >> path;
		file.open(path, ios_base::out);

		for (int i = 0; i < v.size(); i++) {
			file << v[i] << endl;
		}

		file.close();
	}
}

void MergeSortAlgo(vector<int> &empWorkLoads, int count) {
	cout << "Before Sorting" << endl;
	PrintVector(empWorkLoads);

	cout << "\nAfter Sorting" << endl;
	auto start = chrono::steady_clock::now();
	MergeSort(empWorkLoads, 0, count - 1);
	auto end = chrono::steady_clock::now();
	PrintVector(empWorkLoads);

	cout << "Elapsed time in nanoseconds: "
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;
	cout << "Elapsed time in microseconds: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds: "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec";

	saveVectorToFile(empWorkLoads);
}

void QuickSortAlgo(vector<int> &empWorkLoads) {
	cout << "Before Sorting" << endl;
	PrintVector(empWorkLoads);

	cout << "\nAfter Sorting" << endl;
	auto start = chrono::steady_clock::now();
	Quicksort(empWorkLoads, 0, empWorkLoads.size() - 1);
	auto end = chrono::steady_clock::now();
	PrintVector(empWorkLoads);

	cout << "Elapsed time in nanoseconds: "
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds: "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec";

	saveVectorToFile(empWorkLoads);
}

void StoogeSortAlgo(vector<int> &empWorkLoads) {
	cout << "Before Sorting" << endl;
	PrintVector(empWorkLoads);

	cout << "\nAfter Sorting" << endl;
	auto start = chrono::steady_clock::now();
	StoogeSort(empWorkLoads, 0, empWorkLoads.size() - 1);
	auto end = chrono::steady_clock::now();
	PrintVector(empWorkLoads);

	cout << "\nElapsed time in nanoseconds: "
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds: "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds: "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds: "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec";

	saveVectorToFile(empWorkLoads);
}
