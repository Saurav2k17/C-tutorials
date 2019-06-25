// Binary Search recursive implementation for an array
// Given a sorted array arr[] of n elements, write a function to search a given element x in arr[]
// Search a sorted array by repeatedly dividing the search interval into half
// Begin with an interval covering the whole array
// If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half
// Else narrow it to the upper half
// Repeatedly check until the value is found or the interval is empty

#include <stdio.h>

/* Recursive binary search function */
int binarySearch(int arr[], int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l + (r - l) / 2;

		// If the element is present in the middle
		if(arr[mid] == x)
			return mid;

		// If the element is smaller than mid
		if(arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in the right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}

int main(void)
{
	int arr[] = {1, 3, 6, 10, 15, 19, 23, 31, 45};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x; // the value to be searched
	printf("Elements in the array: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\nPlease enter an integer to be searched: ");
	scanf("%d", &x);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1) ? printf("%d is not present in the array\n", x)
		           : printf("%d is present in the array at index %d\n",
		                    x, result);
	return 0;
}
