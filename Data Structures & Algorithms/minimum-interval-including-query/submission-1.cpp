class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());

        int m = queries.size();

        vector<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        // {length, right}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<int> ans(m, -1);

        int i = 0;

        for (auto &[query, idx] : q) {

            // Add all intervals whose left <= query
            while (i < intervals.size() && intervals[i][0] <= query) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                pq.push({len, intervals[i][1]});
                i++;
            }

            // Remove intervals that cannot contain query
            while (!pq.empty() && pq.top().second < query)
                pq.pop();

            if (!pq.empty())
                ans[idx] = pq.top().first;
        }

        return ans;
    }
};