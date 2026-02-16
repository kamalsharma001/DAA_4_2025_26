#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& arr, int target, vector<vector<int>>& dp) {
    int n = arr.size();
    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= target; sum++) {
            dp[i][sum] = dp[i-1][sum];
            if (arr[i-1] <= sum) {
                dp[i][sum] += dp[i-1][sum - arr[i-1]];
            }
        }
    }
    return dp[n][target];
}

void printSubsets(vector<int>& arr, int i, int sum, vector<int>& current, vector<vector<int>>& dp) {
    if (sum == 0) {
        for (int x : current) cout << x << " ";
        cout << endl;
        return;
    }
    if (i == 0) return;

    if (dp[i-1][sum] > 0) {
        printSubsets(arr, i-1, sum, current, dp);
    }

    if (sum >= arr[i-1] && dp[i-1][sum - arr[i-1]] > 0) {
        current.push_back(arr[i-1]);
        printSubsets(arr, i-1, sum - arr[i-1], current, dp);
        current.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int target;
    cin >> target;

    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    int count = countSubsets(arr, target, dp);
    cout <<"Number of subsets : "<<count << endl;

    cout<<"Subsets :"<<endl;
    vector<int> current;
    printSubsets(arr, n, target, current, dp);

    return 0;
}
