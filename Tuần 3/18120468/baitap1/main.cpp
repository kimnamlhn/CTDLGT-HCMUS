#include <iostream>
using namespace std;


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
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
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}



int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return true;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}

	return false;
}


//kiem tra mang nay co phai la mang con cua mang kia khong
//arr1 -> mang 1
//arr2 -> mang 2
//n1 -> so luong mang 1
//n2 -> so luong mang 2
bool check(int arr1[], int arr2[], int n1, int n2)
{
	quickSort(arr1, 0, n1 - 1);
	quickSort(arr2, 0, n2 - 1);
	for (int i = 0; i < n2; i++)
	{
		if (binarySearch(arr1, 0, n1 - 1, arr2[i]) == false)
			return false;

	}
	return true;

}

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[3] = { 2,3,4 };
	if (check(arr1, arr2, 5, 3) == true)
		cout << "Mang arr2 la mang con cua mang arr1 !!!" << endl;
	else cout << "Mang arr2 khong phai la mang con cua mang arr1 !!! " << endl;


	return 0;
}