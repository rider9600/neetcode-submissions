class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c : tasks) freq[c]++;
        priority_queue<int> pq;
        for (auto& p : freq) pq.push(p.second);
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            while (cycle > 0 && !pq.empty()) {
                int cnt = pq.top();
                pq.pop();
                cnt--;
                if (cnt > 0) temp.push_back(cnt);

                time++;
                cycle--;
            }
            for (int x : temp) pq.push(x);
            if (pq.empty()) break;
            time += cycle;
        }
        return time;
    }
};