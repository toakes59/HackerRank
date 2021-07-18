#include <iostream>

using namespace std;

//General information regarding sorting
void sortingInformation() {
	int selection = 0;
	
	cout << "***********************************************************" << endl
		<< "Sorting:" << endl
		<< "-Sorting is used rearrange a given array or list elements according to a comparison operator on the elements." << endl
		<< "-The comparison operator is used to decide the new order of elements in the respective data structure" << endl
		<< "-Common sorting algorithm:" << endl
		<< "\t1. Selection Sort" << endl
		<< "\t2. Bubble Sort" << endl
		<< "\t3. Insertion Sort" << endl
		<< "\t4. Merge Sort" << endl
		<< "\t5. Exit" << endl;
	
	//implement while loop to continue selection
	cout << "\nEnter a number to learn more or to exit!";
	cin >> selection;

	switch (selection) {
		case 1:
			cout << "Selection Sort:" << endl
				<< "\tSort array by repeatedly finding the minimum elements from unsorted part and putting it at the beginning. This aglorithm maintains 2 sibarrays." << endl;
			break;
		case 2:
			cout << "Bubble Sort:" << endl
				<< "\tSimplest sorting algorithm that repeatability swaps the adjacent elements if they are in the wrong order." << endl;
			break;
		case 3:
			cout << "Insertion Sort:" << endl
				<< "A simple algorithm that works similar to sorting playing cards by hand. The array is split into a sorted and unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part." << endl;
			break;
		case 4:
			cout << "This is a divide and conquer algorithm. It divides the input array into 2 halves, calls itself with the two halves, and them merges the two sorted halves. The merge() function is used for merging 2 halves. The merge(arr,1,m,r) is a key process that assumes that arr[1...m] and arr[m+1...r] are sorted and merges the 2 sorted subarrays into one." << endl;
			break;
		case 5:
			//TODO -- exit
			break;
		default:
			cout << "Invalid number selection"<<endl;
			break;
	}
}

//utilized by sorting algorithms to swap two numbers
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Function showing a simple selection sort implementation
void selectionSortAlgo(int arr[], int n) {
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}


//Function showing a bubble sort implementation
void bubbleSortAlgo(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


//Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


//Function used by the merge sort algorithm to merge two subarrays
//First subarray is arr[begin..mid]
//Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

//Function that implements Merge Sorting
// begin is for left index and end is right index of the sub-array of arr to be sorted 
void mergeSortAlgo(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; // Returns recursivly

	auto mid = begin + (end - begin) / 2;
	mergeSortAlgo(array, begin, mid);
	mergeSortAlgo(array, mid + 1, end);
	merge(array, begin, mid, end);
}


/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//Function that implements Quick Sort Algorithm
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSortAlgo(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSortAlgo(arr, low, pi - 1);
		quickSortAlgo(arr, pi + 1, high);
	}
}