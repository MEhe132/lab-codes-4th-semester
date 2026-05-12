#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<double> profit(n), weight(n), ratio(n);

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        ratio[i] = profit[i] / weight[i];
    }

    double capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items by ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }
    double totalValue = 0;
    // Take full items first
    int i;
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            totalValue += profit[i];
            capacity -= weight[i];
        } else {
            break;
        }
    }
    // Take fractional part if any capacity remains
    if (i < n) {
        totalValue += ratio[i] * capacity;
    }
    cout << "Maximum value = " << totalValue << endl;

    return 0;
}