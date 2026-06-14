class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
    map<int,int> mp;
    for(auto num:nums){
        if(mp.count(num))return true;
        mp[num]++;
    }    
    return false;
    }
};