#include <iostream>
#include <vector>
#include <ctime>
#include <cstddef>

using namespace std;

int knapsack(vector<int>& val, vector<int>& wt, int W, int n) {
    if (n < 0 || W <= 0) {
        return 0;
    }
    if (wt[n] > W) {
        return knapsack(val, wt, W, n - 1);
    } else {
        return max(val[n] + knapsack(val, wt, W - wt[n], n - 1), knapsack(val, wt, W, n - 1));
    }
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> val(n);
    vector<int> wt(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of item " << i + 1 << ": ";
        cin >> val[i];
        cout << "Enter the weight of item " << i + 1 << ": ";
        cin >> wt[i];
    }

    int W;
    cout << "Enter the maximum weight capacity: ";
    cin >> W;

    clock_t start_time = clock();
    int result = knapsack(val, wt, W, n - 1);
    // clock_t end_time = clock();

    // double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

    // size_t space_complexity = sizeof(val) + sizeof(wt) + sizeof(n) + sizeof(W) + sizeof(result);

    cout << "Maximum value: " << result << endl;
    // cout << "Elapsed time (seconds): " << elapsed_time << endl;
    // cout << "Space complexity (bytes): " << space_complexity << endl;

    return 0;
}
