class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        vector<pair<int,int>> a;
        stack<double> st;
        for(int i = 0; i < n; i++)
        {
            a.push_back({position[i], speed[i]});
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            double time = (double)(target - a[i].first) / a[i].second;
            if(st.empty())
            {
                st.push(time);
            }
            else if(st.top() >= time)
            {
                continue;
            }
            else
            {
                st.push(time);
            }
        }
        return st.size();
    }
};