#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<double> profit(n + 1), weight(n + 1), ratio(n + 1);

    cout << "Enter profits: ";
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights: ";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        ratio[i] = profit[i] / weight[i];
    }

    double capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort by ratio
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (ratio[i] < ratio[j]) {
                swap(ratio[i], ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    double totalValue = 0;

    int i;
    for (i = 1; i <= n; i++) {
        if (weight[i] <= capacity) {
            totalValue += profit[i];
            capacity -= weight[i];
        } else {
            break;
        }
    }

    if (i <= n) {
        totalValue += ratio[i] * capacity;
    }

    cout << "Maximum value = " << totalValue << endl;

    return 0;
}

sample input: 
// 7 
// 12 5 16 7 9 11 6
// 3 1 4 2 9 4 3
// 15