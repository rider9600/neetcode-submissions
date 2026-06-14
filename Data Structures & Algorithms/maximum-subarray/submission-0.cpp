class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, n = nums.size();
        int ma = INT_MIN;
        int j;
        int i = j = 0;
        while (i < n && j < n) {
            sum += nums[j];
            j++;
            ma = max(ma, sum);
            if (sum < 0) {
                i = j;
                sum = 0;
            }
        }
        return ma;
    }
};
