#include <iostream>
using namespace std;


void output(int a[], int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void check(int arr[], int n)
{
	int firstIndex;
	int lastIndex;
	int count0, count1;
	count0 = count1 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		firstIndex = i;
		count0 = count1 = 0;
		for (int j = 0 ; j < n; j++)
		{
			
			if (arr[j] == 0)
				count0++;
			else
				count1++;
			if (count0 == count1)
			{
				lastIndex = j;
				cout << endl;
				cout << firstIndex << " to " << lastIndex << endl;
				count0 = count1 = 0;
			}
		}
	}
	
}


int main()
{
	int arr[10] = { 0,1,0,1,1,0,0,1,0,1 };

	output(arr, 10);
	check(arr,10);
	return 0;
}