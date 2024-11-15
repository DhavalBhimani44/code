#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item{
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double r1 = (double) a.value/a.weight;
    double r2 = (double) b.value/b.weight;
    return r1 > r2;  
}

double knapsack_greedy(int maxCap, vector<Item>& items) {
    double maxVal = 0.0;
    vector<double> fractions(items.size(), 0);  // To store fractions of each item included

    sort(items.begin(), items.end(), compare);  // Sort items based on value/weight ratio

    for(int i = 0; i < items.size(); i++) {
        if(items[i].weight <= maxCap) {
            // If the entire item can be included
            maxCap -= items[i].weight;
            maxVal += items[i].value;
            fractions[i] = 1;  // The whole item is included
        } else {
            // If only a fraction of the item can be included
            maxVal += (double)(maxCap * (items[i].value / items[i].weight));
            fractions[i] = (double)maxCap / items[i].weight;  // Fraction of the item included
            break;  // The knapsack is full
        }
    }

    // Print the details for each item
    cout << "\nItem\tWeight\tFraction";
    for (int i = 0; i < items.size(); i++) {
        cout << i + 1 << "\t" << items[i].weight << "\t" << fractions[i] << "\t\t" << endl;
    }

    return maxVal;
}

int main() {
    int maxCap, n;

    cout << "Enter max capacity of knapsack: ";
    cin >> maxCap;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> items[i].weight;
        cout << "Enter value for item " << i + 1 << ": ";
        cin >> items[i].value;
    }

    double maxValue = knapsack_greedy(maxCap, items);

    cout << "\nMaximum value of knapsack: " << maxValue << endl;
}