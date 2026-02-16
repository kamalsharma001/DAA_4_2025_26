#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> buildSubset(vector<vector<int>>& dp, vector<int>& numbers, int count, int targetSum){
    vector<int> subset;
    if (dp[count][targetSum] == -1) return subset;

    while (count > 0 && targetSum > 0){
        if (dp[count][targetSum] == dp[count - 1][targetSum]){
            count--;
        }
        else{
            subset.push_back(numbers[count - 1]);
            targetSum -= numbers[count - 1];
            count--;
        }
    }
    reverse(subset.begin(), subset.end());
    return subset;
}

int main()
{
    vector<int> numbers = {6, 2, 3, 7, 4};
    int targetSum = 9;
    int count = numbers.size();

    vector<vector<int>> dp(count + 1, vector<int>(targetSum + 1, -1));

    for (int i = 0; i <= count; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= count; i++){
        for (int j = 1; j <= targetSum; j++){
            dp[i][j] = dp[i - 1][j];
            if (numbers[i - 1] <= j && dp[i - 1][j - numbers[i - 1]] != -1){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - numbers[i - 1]] + 1);
            }
        }
    }

    if (dp[count][targetSum] == -1){
        cout << "No subset found\n";
        return 0;
    }

    cout << "Length of longest subset: " << dp[count][targetSum] << endl;
    vector<int> subset = buildSubset(dp, numbers, count, targetSum);

    cout << "Longest Subset: ";
    for (int val : subset){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
