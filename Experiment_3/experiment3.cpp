class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<bool> vis;

    bool solve(int u, int cnt) {
        if (cnt == n) {
            return true;
        }
        for (int x : adj[u]) {
            if (!vis[x]) {
                vis[x] = true;
                if (solve(x, cnt + 1)){
                    return true;
                }
                vis[x] = false;
            }
        }
        return false;
    }

    bool check(int n, int m, vector<vector<int>> edges) {
        this->n=n;
        adj.assign(n, {});
        for (auto e:edges) {
            int a=e[0]-1;
            int b=e[1]-1;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 0; i <n; i++) {
            vis.assign(n, false);
            vis[i] = true;
            if (solve(i, 1)){
                return true;
            }
        }
        return false;
    }
};
