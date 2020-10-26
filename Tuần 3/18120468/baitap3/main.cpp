#include <iostream>	
#include <time.h>
#include <algorithm> 
#include <chrono> 
using namespace std;
using namespace std::chrono;

// Các hàm sort 
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void selectionSort(int arr[], int n)
{
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

// A function to implement bubble sort  
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

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

//// Merges two subarrays of arr[]. 
//// First subarray is arr[l..m] 
//// Second subarray is arr[m+1..r] 
//void merge(int arr[], int l, int m, int r)
//{
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//
//	/* create temp arrays */
//	int L[n1], R[n2];
//
//	/* Copy data to temp arrays L[] and R[] */
//	for (i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//
//	/* Merge the temp arrays back into arr[l..r]*/
//	i = 0; // Initial index of first subarray 
//	j = 0; // Initial index of second subarray 
//	k = l; // Initial index of merged subarray 
//	while (i < n1 && j < n2)
//	{
//		if (L[i] <= R[j])
//		{
//			arr[k] = L[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	/* Copy the remaining elements of L[], if there
//	   are any */
//	while (i < n1)
//	{
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	/* Copy the remaining elements of R[], if there
//	   are any */
//	while (j < n2)
//	{
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
///* l is for left index and r is right index of the
//   sub-array of arr to be sorted */
//void mergeSort(int arr[], int l, int r)
//{
//	if (l < r)
//	{
//		// Same as (l+r)/2, but avoids overflow for 
//		// large l and h 
//		int m = l + (r - l) / 2;
//
//		// Sort first and second halves 
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, r);
//
//		merge(arr, l, m, r);
//	}
//}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

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

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
//void countSort(int arr[], int n, int exp)
//{
//	int output[n]; // output array 
//	int i, count[10] = { 0 };
//
//	// Store count of occurrences in count[] 
//	for (i = 0; i < n; i++)
//		count[(arr[i] / exp) % 10]++;
//
//	// Change count[i] so that count[i] now contains actual 
//	//  position of this digit in output[] 
//	for (i = 1; i < 10; i++)
//		count[i] += count[i - 1];
//
//	// Build the output array 
//	for (i = n - 1; i >= 0; i--)
//	{
//		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//		count[(arr[i] / exp) % 10]--;
//	}
//
//	// Copy the output array to arr[], so that arr[] now 
//	// contains sorted numbers according to current digit 
//	for (i = 0; i < n; i++)
//		arr[i] = output[i];
//}
//
//// The main function to that sorts arr[] of size n using  
// Radix Sort 
//void radixsort(int arr[], int n)
//{
//	// Find the maximum number to know number of digits 
//	int m = getMax(arr, n);
//
//	// Do counting sort for every digit. Note that instead 
//	// of passing digit number, exp is passed. exp is 10^i 
//	// where i is current digit number 
//	for (int exp = 1; m / exp > 0; exp *= 10)
//		countSort(arr, n, exp);
//}
///* function to sort arr using shellSort */
//int shellSort(int arr[], int n)
//{
//	// Start with a big gap, then reduce the gap 
//	for (int gap = n / 2; gap > 0; gap /= 2)
//	{
//		// Do a gapped insertion sort for this gap size. 
//		// The first gap elements a[0..gap-1] are already in gapped order 
//		// keep adding one more element until the entire array is 
//		// gap sorted  
//		for (int i = gap; i < n; i += 1)
//		{
//			// add a[i] to the elements that have been gap sorted 
//			// save a[i] in temp and make a hole at position i 
//			int temp = arr[i];
//
//			// shift earlier gap-sorted elements up until the correct  
//			// location for a[i] is found 
//			int j;
//			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//				arr[j] = arr[j - gap];
//
//			//  put temp (the original a[i]) in its correct location 
//			arr[j] = temp;
//		}
//	}
//	return 0;
//}
int binarySearch(int a[], int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);
	return binarySearch(a, item, low, mid - 1);
}


//chạy hàm main 10 lần 
int main()
{
	const int SIZE = 50000;
	int a[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) 
		a[i] = (rand() % 100) + 1;


	//Hàm slect sort 

	// Get starting timepoint 
	auto start = high_resolution_clock::now();
	// Get ending timepoint 
	selectionSort(a, SIZE);
	auto stop = high_resolution_clock::now();
	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;


	//Hàm insert sort 
	auto start = high_resolution_clock::now();
	insertionSort(a, SIZE);  
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;



	//Hàm bubble sort 
	auto start = high_resolution_clock::now();
	bubbleSort(a, SIZE);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;



	//Hàm quick sort 
	auto start = high_resolution_clock::now();
	quickSort(a, 0, SIZE - 1);  
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;


	//Hàm heap sort 
	auto start = high_resolution_clock::now();
	heapSort(a, SIZE); 
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;


	//Hàm binary insert sort 
	auto start = high_resolution_clock::now();
	insertionSort(a, SIZE);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;




	return 0;
}
