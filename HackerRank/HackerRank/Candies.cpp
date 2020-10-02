#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {

	int sum = 0;
	int count = 1;

	if (arr[0] < arr[1]) {
		count = 2;
	}

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > arr[i + 1]) {
			count++;
		}
		else if (arr[i] < arr[i + 1]) {
			count--;
		}
		sum = sum + count;
	}

	return sum;
}

int candies()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr[i] = arr_item;
	}

	long result = candies(n, arr);

	fout << result << "\n";

	fout.close();

	return 0;
}
