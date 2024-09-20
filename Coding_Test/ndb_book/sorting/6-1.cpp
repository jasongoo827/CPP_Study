#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int n;
int arr[100001] = {0,};

void quicksort(int *array, int start, int end)
{
	if (start >= end)
		return ;
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right)
	{
		while (left <= end && array[left] <= array[pivot])
			left++;
		while (right > start && array[right] >= array[pivot])
			right--;
		if (left > right)
			swap(array[pivot], array[right]);
		else
			swap(array[left], array[right]);
	}
	quicksort(array, start, right - 1);
	quicksort(array, right + 1, end);
}

int main(void)
{
	cin >> n;

	// Counting Sort
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		arr[x]++;
	}

	int maxVal = *max_element(arr, arr + 100001);
	for (int i = maxVal; i >= 1; i--)
	{
		for (int j = 0; j < arr[i]; ++j)
			cout << i << ' ';
	}

	// Sort Library
	vector<int> v; // 미리 할당하면 어떻게 해야할까
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<>()); // cmp를 직접 정의 가능.
	
	// Quick Sort
	quicksort(arr, 0, 100001);
}