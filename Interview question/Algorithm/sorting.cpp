#include <iostream>
#include <vector>
using namespace std;

/*
 Every time select minimum value from remaining data
 and swap with the next sorted position
*/
void SelectionSort() {
    vector<int> arr = {64, 25, 12, 22, 11, 23, 22, 67, 12, 1, 7};
    int n = arr.size();               // O(1)

    for (int i = 0; i < n - 1; i++) {  // O(n-1)
        int min_idx = i;              // O(1)

        // find minimum element in remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // swap minimum with first element of unsorted part
        swap(arr[i], arr[min_idx]);
    }

    cout << "Selection sort : ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n\n\n";
}

/*
 Bubbling and swapping continuously n*n times,
 but if once no swap happens in one full traversal,
 then array is already sorted
*/
void BubbleSort() {
    vector<int> arr = {64, 25, 12, 22, 11, 23, 22, 67, 12, 1, 7};
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // if no swap occurred, array is sorted
        if (!swapped) {
            break;
        }
    }

    cout << "Bubble sort : ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n\n\n";
}

/*
 Consider two parts: sorted and unsorted
 Take the desired value from unsorted part
 and insert it into the correct position
 in the sorted part
*/
void InsertionSort() {
    vector<int> arr = {1, 2, 3, 5, 6, 4, 22, 67, 12, 1, 7};
    int n = arr.size();

    for (int unsorted_first = 1; unsorted_first < n; unsorted_first++) {

        // value to be inserted
        int key = arr[unsorted_first];

        // last index of sorted part
        int sorted_last = unsorted_first - 1;

        // shift elements to the right
        while (sorted_last >= 0 && arr[sorted_last] > key) {
            arr[sorted_last + 1] = arr[sorted_last];
            sorted_last--;
        }

        // insert at correct position
        arr[sorted_last + 1] = key;
    }

    cout << "Insertion sort : ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << "\n\n\n";
}

int main() {
    //SelectionSort();
    BubbleSort();
    //InsertionSort();

    return 0;
}
