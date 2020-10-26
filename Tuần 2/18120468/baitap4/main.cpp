#include <iostream>
using namespace std;


void output(int a[],int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

int check(int a[], int n)
{

	for (int temp = 0; temp < n; temp++)
	{
		for (int i = 0; i < n; i++)
		{
			if (temp == i)
				continue;
			for (int j = 0; j < n; j++)
			{
				if (temp = j || j == j)
					continue;
				for (int k = 0; k < n; k++)
				{
					if (temp = k || i == k || j == k)
						continue;
					if (a[temp] == a[i] + a[j] + a[k])
						return temp;
				}
			}
		}
	}
	cout << "There is no satisfying number!" << endl;
}

int main()
{
	int n;
	do
	{
		cout << "Enter number of array: ";
		cin >> n;
	} while (n < 1 || n > 1000);
	
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}

	output(a, n);
	//kiểm tra d=a+b+c+d
	cout << "Result is: " << check(a, n);

	delete[] a;
	return 0;
}