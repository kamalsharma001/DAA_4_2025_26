#include <bits/stdc++.h>
using namespace std;

long long max_operation = 0;
int max_depth = 0;

void complexRec(int n, int depth) {
    max_depth = max(max_depth, depth);

    if (n <= 2) {
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            max_operation++;
        }
        p >>= 1;
        max_operation++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        max_operation++;
    }

    reverse(small.begin(), small.end());
    max_operation++;

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    vector<int> test_sizes = {4, 16, 128, 512, 1024, 8192, 32768};
    cout<<endl<<"Recurrence Relation : T(n)=3T(n/2)+nlog(n)"<<endl;
    cout<<"Master Theoram Case 1 used : a>b^k"<<endl;
    cout<<"Time Complexity : O(n^log(2,3))"<<endl<<endl;
    for (int n : test_sizes) {
        max_operation = 0;
        max_depth = 0;
        auto start = chrono::high_resolution_clock::now();
        complexRec(n, 1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        
        cout << "Input size: " << n << endl;
        cout << "Max operations: " << max_operation << endl;
        cout << "Max recursion depth: " << max_depth << endl;
        cout << "Execution time: " << duration.count() << " ms" << endl<<endl;
    }
    return 0;
}
/*
Recurrence Relation : T(n)=3T(n/2)+nlog(n)
Master Theoram Case 1 used : a>b^k
Time Complexity : O(n^log(2,3))
*/
