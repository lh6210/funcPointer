#include <iostream>
#include <algorithm>
using namespace std;

void sort(int array[], int length, bool (*compFcn)(int, int));
bool ascending(int ,int );
void display(int arr[], int size);
bool evensFirst(int, int);


int main(int argc, char** argv)
{
	int num;
	int arr[]{14,24,6,8,1,9,20};
	display(arr, 7);
	
	sort(arr, 7, evensFirst);
	display(arr, 7);

	return 0;


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

bool evensFirst(int x, int y)
{
	if (x % 2 == 0 && y % 2 != 0)
		return true;
	if (x % 2 != 0 && y % 2 == 0)
		return false;
	
	return ascending(x, y);
}

