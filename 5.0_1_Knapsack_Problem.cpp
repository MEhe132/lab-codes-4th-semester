#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values of items: ";
    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items: ";
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int c;
    cout << "Enter knapsack capacity: ";
    cin >> c;

    // DP table using vector
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

    // Fill table
    for(int i = 1; i <= n; i++) {

        for(int w = 0; w <= c; w++) {

            if(wt[i-1] > w) {
                dp[i][w] = dp[i-1][w];
            }

            else {

                int take = val[i-1] + dp[i-1][w - wt[i-1]];
                int notTake = dp[i-1][w];

                if(take > notTake)
                    dp[i][w] = take;
                else
                    dp[i][w] = notTake;
            }
        }
    }

    cout << "Maximum value = " << dp[n][c];

    return 0;
}