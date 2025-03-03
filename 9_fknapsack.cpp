#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Comparator function to sort items by value/weight ratio in descending order
bool cmp(pair<int, int> a, pair<int, int> b) {
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;
    return r1 > r2;
}

// Function to calculate the maximum total value in the knapsack
double fractionalKnapsack(int capacity, vector<pair<int, int>> items) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto item : items) {
        if (capacity >= item.first) {
            // Take the whole item
            capacity -= item.first;
            totalValue += item.second;
        } else {
            // Take the fraction of the item
            totalValue += item.second * ((double)capacity / item.first);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;
    cout <<"Enter number of items and knapsack capacity: ";
    cin >> n >> capacity;

    vector<pair<int, int>> items(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
