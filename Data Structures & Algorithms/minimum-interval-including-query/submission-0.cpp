class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans;

        for (int q : queries) {
            priority_queue<int, vector<int>, greater<int>> pq;

            for (auto &it : intervals) {
                if (it[0] <= q && q <= it[1]) {
                    int len = it[1] - it[0] + 1;
                    pq.push(len);
                }
            }

            if (pq.empty())
                ans.push_back(-1);
            else
                ans.push_back(pq.top());
        }

        return ans;
    }
};