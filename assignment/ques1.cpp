#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solutions;
vector<int> col, ld, rd;

void solve(int row, int n, vector<string> &board) {
    if(row == n) {
        solutions.push_back(board);
        return;
    }
    for(int j=0; j<n; j++) {
        if(!col[j] && !ld[row+j] && !rd[row-j+n-1]) {
            board[row][j] = 'Q';
            col[j] = ld[row+j] = rd[row-j+n-1] = 1;
            solve(row+1, n, board);
            board[row][j] = '.';
            col[j] = ld[row+j] = rd[row-j+n-1] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter size of board : ";
    cin >> n;
    col.assign(n,0);
    ld.assign(2*n,0);
    rd.assign(2*n,0);
    vector<string> board(n, string(n,'.'));
    solve(0, n, board);

    cout << "Total solutions: " << solutions.size() << "\n";
    for(auto &sol : solutions) {
        for(auto &row : sol) cout << row << "\n";
        cout << "\n";
    }
    return 0;
}
