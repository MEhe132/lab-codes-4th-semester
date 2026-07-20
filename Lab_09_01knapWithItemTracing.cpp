#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {

    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[W + 1];
    }

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i] <= w) {
                dp[i][w] = max(
                    val[i] + dp[i - 1][w - wt[i]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 🔥 Trace selected items
    cout << "\nSelected items:\n";

    int i = n, w = W;
    while (i > 0 && w > 0) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i 
                << " (Weight=" << wt[i] 
                << ", Value=" << val[i] << ")\n";

            w -= wt[i]; // reduce capacity
        }
        i--; // move to previous item
    }

    int result = dp[n][W];

    // Free memory
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return result;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int* val = new int[n + 1];
    int* wt  = new int[n + 1];

    cout << "Enter profits:\n";
    for (int i = 1; i <= n; i++) cin >> val[i];

    cout << "Enter weights:\n";
    for (int i = 1; i <= n; i++) cin >> wt[i];

    int W;
    cout << "Enter capacity: ";
    cin >> W;

    int maxVal = knapsack(W, wt, val, n);

    cout << "\nMaximum value: " << maxVal << endl;

    delete[] val;
    delete[] wt;

    return 0;
}

// 4
// 1 4 5 7
// 1 3 4 5
// 7