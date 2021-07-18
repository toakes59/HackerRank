#include <iostream>

using namespace std;

int minSawps(int* arr[], int minSwaps)
{
	int size = (sizeof(arr) / sizeof(arr[0]));
	int count = minSwaps;
	int tempVal = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i]!=i+1){
			tempVal = arr[arr[i]-1];
			arr[arr[i]-1]=arr[i];
			arr[i]=tempVal;
			count++;
		}
	}
	
	//recursivly checks if there are any swaps remaining
	for (int i = 0; i < size; i++) {
        if(arr[i]!=i+1){
            return minimumSwaps(arr, count);
        }
    }

	return count;
}

int initializeMinSwaps2()
{
	int arrSize = 0;
	int minSwaps = 0;

	int* arr = new int[arrSize];

	cout << "Enter Array: " << endl;
	cin >> arr;


	minSwaps = minSawps(&arr, 0);

	cout << "Minimum Sawps is: " << minSwaps <<endl;

	return 0;
}