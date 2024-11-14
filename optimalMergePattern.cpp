#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int optimalMergePattern(vector<int> &files) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Add all file sizes to the min-heap
    for (int file : files)
        minHeap.push(file);

    int totalCost = 0;

    // Merge until only one file remains
    while (minHeap.size() > 1) {
        // Extract two smallest files
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Merge the two files
        int mergeCost = first + second;
        totalCost += mergeCost;

        cout << "Merging files of size " << first << " and " << second << " with cost " << mergeCost << endl;

        minHeap.push(mergeCost);
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> files(n);
    cout << "Enter the sizes of the files:\n";
    for (int i = 0; i < n; ++i)
        cin >> files[i];

    cout << "\nSteps of merging files:\n";
    int minCost = optimalMergePattern(files);
    cout << "\nMinimum cost of merging files: " << minCost << endl;

    return 0;
}
