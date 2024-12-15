#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& values) {
    for (size_t i = 0; i < values.size() - 1; ++i) {
        for (size_t j = 0; j < values.size() - i - 1; ++j) {
            if (values[j] > values[j + 1]) {
                swap(values[j], values[j + 1]);
            }
        }
    }
}

// Binary Search
int binarySearch(const vector<int>& values, int target) {
    int left = 0, right = values.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (values[mid] == target) {
            return mid;
        } else if (values[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Ziel nicht vorhanden
}

int main() {
    ifstream inFile("data.txt");

    if (!inFile) {
        cout << "Unable to open file." << endl;
        return 1;
    }

    vector<int> values;
    int x;
    while (inFile >> x) {
        values.push_back(x);
    }

    cout << "Original values from the file:" << endl;
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;

    // Sort
    bubbleSort(values);

    cout << "\nSorted values:" << endl;
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;
	bool finish = false;

	while (!finish){
		// Input
    	int target;
    	cout << "\nEnter a number to search: ";
    	cin >> target;

    	// Search
    	int result = binarySearch(values, target);

			if (result != -1) {
        		cout << "\nNumber found at index " << result << " in the sorted list." << endl;
        		finish = true;
			} else {
        		cout << "\nNumber not found." << endl;
    		}
		}

    return 0;
}
