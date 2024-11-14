#include <iostream>
#include <queue> 
#include <vector> 
#include <algorithm> 

using namespace std;

int optimalMergePattern(int files[], int n) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; ++i) {
        minHeap.push(files[i]);
    }

    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int mergedFile = first + second;
        totalCost += mergedFile;

        minHeap.push(mergedFile);
    }

    return totalCost;
}

void printFiles(int files[], int n) {
    cout << "\nFiles: ";
    for (int i = 0; i < n; ++i) {
        cout << files[i] << " ";
    }
    cout << endl;
}

void printSortedFiles(int files[], int n) {
    int sortedFiles[100]; 
    for (int i = 0; i < n; ++i) {
        sortedFiles[i] = files[i];
    }

    sort(sortedFiles, sortedFiles + n);

    cout << "Sorted Files: ";
    for (int i = 0; i < n; ++i) {
        cout << sortedFiles[i] << " ";
    }
    cout << endl;
}

int main() {
    int numFiles;
    cout << "Enter number of files: ";
    cin >> numFiles;

    if (numFiles > 100) {
        cout << "Number of files exceeds the limit (100)." << endl;
        return 1;
    }

    int files[100]; 
    
    cout << "Enter the weight of each file:\n";
    for (int i = 0; i < numFiles; ++i) {
        cout << "File " << i + 1 << ": ";
        cin >> files[i];
    }

    printFiles(files, numFiles);

    printSortedFiles(files, numFiles);

    int result = optimalMergePattern(files, numFiles);
    cout << "\nMinimum cost to merge files: " << result << endl;

    return 0;
}
