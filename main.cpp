#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(const int array[], int first, int last, int value);
void sort(int array[], int length, bool (*compFcn)(int, int));
bool ascending(int ,int );
void display(int arr[], int size);
//bool evensFirst(int, int);


int main(int argc, char** argv)
{
	int num;
	int arr[]{14,24,6,8,1,9,20};
	display(arr, 7);
	
	sort(arr, 7, ascending);
	display(arr, 7);

	cout << "Enter the number you are searching for: ";
	cin >> num;

	//cout << endl;
	while (num != -1)
	{
		int result = binarySearch(arr, 0, 6, num);
		if (result == -1)
			cout << num << " not found!" << endl;
		else 
			cout << num << " is at index " << result << endl;

		cout << endl;
		cout << "Enter the number you are searching for: ";
		cin >> num;
	}
	return 0;








}

int binarySearch(const int array[], int first, int last, int value)
{
	int index;
	if (last < first)
		index = -1;
	else
	{
		int mid = (first + last) / 2;
		if (value == array[mid])
			index = mid;
		
		else if (value < array[mid])
		{
			last = mid - 1;
			index = binarySearch(array, first, last, value);
		}
		else
		{
			first = mid + 1;
			index = binarySearch(array, first, last, value);
		}	
	}
	return index;
}



void sort(int array[], int size, bool (*compFcn)(int, int))
{
	for (int i = 0; i < size; i++)
	{
		int bestIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (compFcn(array[j], array[bestIndex]))
				bestIndex = j;
		}
		std::swap(array[i], array[bestIndex]);
	}
}

bool ascending(int x, int y)
{
	if (x <= y)
		return true;
	else
		return false;
}

void display(int arr[], int size)
{
	bool first = true;
	for (int i = 0; i < size; i++)
	{
		if (first)
		{
			first = false;
			cout << arr[i];
		}
		else
			cout << ", " << arr[i];
	}
	cout << endl;
}

/*
bool evensFirst(int x, int y)
{
	if (x % 2 == 0 && y % 2 != 0)
		return false;
	if (x % 2 != 0 && y % 2 == 0)
		return true;
	
	return ascending(x, y);
}
*/



