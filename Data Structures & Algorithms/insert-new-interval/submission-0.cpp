class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        // Find insertion position
        int pos = lower_bound(intervals.begin(), intervals.end(), newInterval,
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }) - intervals.begin();

        intervals.insert(intervals.begin() + pos, newInterval);

        int i = pos;

        // Merge with previous intervals if needed
        while (i > 0 && intervals[i - 1][1] >= intervals[i][0]) {
            intervals[i - 1][0] = min(intervals[i - 1][0], intervals[i][0]);
            intervals[i - 1][1] = max(intervals[i - 1][1], intervals[i][1]);
            intervals.erase(intervals.begin() + i);
            i--;
        }

        // Merge with next intervals if needed
        while (i + 1 < intervals.size() && intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i][0] = min(intervals[i][0], intervals[i + 1][0]);
            intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
            intervals.erase(intervals.begin() + i + 1);
        }

        return intervals;
    }
};