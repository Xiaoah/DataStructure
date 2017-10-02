#include<stdio.h>
#include<iostream>

using namespace std;
/*顺序查找*/
int Sequentail_Search(int *a, int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}
int Sequential_Search2(int *a, int n, int key)
{
	int i = n;
	a[0] = key;
	while (a[i] != key)
	{
		i--;
	}
	return i;
	
}

int Binary_Search(int *a, int n, int key)
{
	int mid;
	int low = 1;
	int high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] > key) {
			high = mid - 1;
		}
		else if (a[mid] < key)
		{
			low = mid + 1;
		}
		else
			return mid;
	}
	return 0;
}
/*插值查找法*/
	int InsertValue_Search(int *a, int n, int key)
	{
		int mid;
		int low = 1;
		int high = n;
		while (low <= high)
		{
			mid = low + (high - low)*(key - a[low]) / (a[high] - a[low]);
			if (a[mid] > key) {
				high = mid - 1;
			}
			else if (a[mid] < key)
			{
				low = mid + 1;
			}
			else
				return mid;
		}
		return 0;
	
}

/*斐波那契查找*/
	int Fibonacci(int n)
	{
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else
			return Fibonacci(n - 1) + Fibonacci(n - 2);
	}

	int Fibonacci_Search(int *a, int n, int key)
	{
		int F[50];

		for (int j = 0; j <= n; j++)
		{
			F[j] = Fibonacci(j);
		}
		int low, high, mid, i, k;
		low = 1;
		high = n;
		k = 0;
		while (n > F[k] - 1)
		{
			k++;
		}
		for (i = n; i < F[k] - 1; i++)
		{
			a[i] = a[n];
		}
		while (low <= high)
		{
			mid = low + F[k - 1] - 1;
			if (key < a[mid])
			{
				high = mid - 1;
				k = k - 1;
			}
			else if (key>a[mid])
			{
				low = mid + 1;
				k = k - 2;
			}
			else {
				if (mid <= n)
					return mid;
				else
					return n;
			}
		}
		return 0;
	}