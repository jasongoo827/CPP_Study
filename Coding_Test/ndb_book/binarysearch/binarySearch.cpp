#include <iostream>

int binary_search(int *arr, int target, int start, int end)
{
	if (start > end)
		return (-1);
	int mid = (start + end) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return binary_search(arr, target, start, mid - 1);
	else
		return binary_search(arr, target, mid + 1, end); 
}