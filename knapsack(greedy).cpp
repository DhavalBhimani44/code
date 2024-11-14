#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight, value;
    double ratio;
};

// Comparator function to sort items based on value-to-weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;  // Descending order
}

double fractionalKnapsack(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<Item> items(n);

    // Prepare items with value-to-weight ratio
    for (int i = 0; i < n; ++i) {
        items[i] = {weights[i], values[i], (double)values[i] / weights[i]};
    }

    // Sort items based on value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;  // To store the total value of items picked
    int remainingCapacity = W;

    for (int i = 0; i < n && remainingCapacity > 0; ++i) {
        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalValue += items[i].ratio * remainingCapacity;
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int W = 15;  // Maximum weight capacity of the knapsack
    vector<int> weights = {2, 3, 5, 7, 1, 4, 1};  // Weights of items
    vector<int> values = {10, 5, 15, 7, 6, 18, 3};  // Values of items

    double maxValue = fractionalKnapsack(W, weights, values);
    
    cout << "Maximum profit (Fractional) we can obtain = " << maxValue << endl;

    return 0;
}
