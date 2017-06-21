#include <iostream>
#include <Windows.h>

static int sorted[16];

void myMerge(int list[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	int l;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			sorted[k++] = list[i++];
		}
		else
		{
			sorted[k++] = list[j++];
		}
	}

	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			sorted[k++] = list[l];
		}
	}

	else
	{
		for (l = i; l <= mid; l++)
		{
			sorted[k++] = list[l];
		}
	}

	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}

void myMergeSort(int list[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		myMergeSort(list, left, mid);
		myMergeSort(list, mid + 1, right);

		myMerge(list, left, mid, right);
	}
}



int main(void)
{
	int arr[16] = { 10, 15, 31, 1, 11, 6, 8, 9, 3, 20, 4, 14, 12, 5, 7, 2 };

	myMergeSort(arr, 0, 15);

	for (int i = 0; i < 16; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < 16; ++i)
	{
		std::cout << sorted[i] << " ";
	}
	std::cout << std::endl;
	

	getchar();


	return 0;
}