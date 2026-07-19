class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Available room numbers
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++)
            available.push(i);

        // {endTime, roomNumber}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        vector<long long> cnt(n, 0);

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];

            // Free all rooms that have finished
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                // Assign smallest available room
                int room = available.top();
                available.pop();

                cnt[room]++;
                busy.push({end, room});
            } else {
                // Delay meeting until earliest room is free
                auto [finish, room] = busy.top();
                busy.pop();

                long long duration = end - start;
                cnt[room]++;
                busy.push({finish + duration, room});
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (cnt[i] > cnt[ans])
                ans = i;
        }

        return ans;
    }
};