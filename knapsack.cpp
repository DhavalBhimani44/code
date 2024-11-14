#include <iostream>
#include <vector>

using namespace std;

int knapsack01(int W, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));  

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

    // Print dp table
    cout << "\nDP Table:\n";
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            cout << dp[i][w] << "\t"; 
        }
        cout << endl;
    }

    // Return the maximum value that can be carried
    return dp[n][W];
}

int main() {
    int W = 40;  
    vector<int> weights = {2, 11, 22, 15};  
    vector<int> values = {11, 21, 31, 33};  

    int maxValue = knapsack01(W, weights, values);
    
    cout << "Maximum profit we can obtain = " << maxValue << endl;

    return 0;
}
