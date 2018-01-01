#include <iostream>

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* array, int left, int right)
{
	int pivot = array[left];
	int low = left;
	int high = right + 1;

	while (low < high)
	{
		do
		{
			low++;
		} while (low <= right && array[low] < pivot);

		do
		{
			high--;
		} while (high >= left && array[high] > pivot);

		if (low < high)
		{
			swap(&array[low], &array[high]);
			print(array, 10);
		}
	}

	std::cout << "low : " << low << " > high : " << high << std::endl;
	
	swap(&array[left], &array[high]);

	print(array, 10);

	return high;
}

void Qsort(int* myArray, int left, int right)
{
	if (left < right)
	{
		int pivot = partition(myArray, left, right);
		std::cout << "partition at " << pivot << " value is " << myArray[pivot] <<std::endl;
		Qsort(myArray, left, pivot - 1);
		Qsort(myArray, pivot + 1, right);
	}
}

int main(void)
{
	//int arr[] = {3, 5, 8, 1, 14, 2, 11, 10, 4, 7};
	int arr[] = { 8, 9, 1, 7, 22, 5, 4, 18, 2, 10 };

	print(arr, 10);

	Qsort(arr, 0, 9);

	getchar();

	return 0;
}