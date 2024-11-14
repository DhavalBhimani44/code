#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono> 

using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int recBinarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = (l + r)  / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return recBinarySearch(arr, l, mid - 1, x);
        }
        return recBinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(){
    const int n = 100; 
    int arr[n];
    srand(time(0)); 

    cout << "Random array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    int x = rand() % 101;
    cout << "Searching for: " << x << endl; 

    auto start = high_resolution_clock::now();
    sort(arr, arr + n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // Timing linear search
    int linearSearchResult = linearSearch(arr, n, x);
    auto end = high_resolution_clock::now();
    double linearSearchTime = duration<double, milli>(end - start).count();

    if (linearSearchResult == -1) {
        cout << "Linear search: Element not found" << endl;
    } else {
        cout << "Linear search: Element found at index " << linearSearchResult << endl;
    }
    cout << "Linear search time: " << linearSearchTime << " milliseconds" << endl << endl;

    // Timing binary search
    int recBinarySearchResult = recBinarySearch(arr, 0, n - 1, x);
    end = high_resolution_clock::now();
    double binarySearchTime = duration<double, milli>(end - start).count();

    if (recBinarySearchResult == -1) {
        cout << "Binary search: Element not found" << endl;
    } else {
        cout << "Binary search: Element found at index " << recBinarySearchResult << endl;
    }
    cout << "Binary search time: " << binarySearchTime << " milliseconds" << endl;

    return 0;
}
