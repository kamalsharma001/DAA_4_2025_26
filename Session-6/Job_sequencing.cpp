class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        vector<pair<int,int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        sort(jobs.rbegin(), jobs.rend());

        int max_deadline = 0;
        for (auto &job : jobs) max_deadline = max(max_deadline, job.second);

        parent.resize(max_deadline + 1);
        for (int i = 0; i <= max_deadline; i++) parent[i] = i;

        int maxProfit = 0, countJobs = 0;
        for (auto &job : jobs) {
            int availSlot = find(job.second);
            if (availSlot > 0) {
                maxProfit += job.first;
                countJobs++;
                parent[availSlot] = find(availSlot - 1);
            }
        }
        return {countJobs, maxProfit};
    }
};
