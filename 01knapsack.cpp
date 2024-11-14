#include <iostream>
#include <vector>

using namespace std;

int knapsack01(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));  // dp table

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                // Max value by including or excluding the current item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];  // Exclude the item
            }
        }
    }

    // Return the maximum value that can be carried
    return dp[n][W];
}

int main() {
    int W = 15;  // Maximum weight capacity of the knapsack
    vector<int> weights = {2, 3, 5, 7, 1, 4, 1};  // Weights of items
    vector<int> values = {10, 5, 15, 7, 6, 18, 3};  // Values of items

    int maxValue = knapsack01(W, weights, values);
    
    cout << "Maximum profit we can obtain = " << maxValue << endl;

    return 0;
}
