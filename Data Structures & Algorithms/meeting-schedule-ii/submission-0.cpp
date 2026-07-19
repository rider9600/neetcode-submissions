/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            if (a.start == b.start)
                return a.end < b.end;
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;

        for (auto &it : intervals) {
            while (!pq.empty() && pq.top() <= it.start)
                pq.pop();

            pq.push(it.end);
            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};