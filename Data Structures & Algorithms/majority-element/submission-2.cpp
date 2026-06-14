class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        
        int count =1,ans=nums[0];
        for (int i = 1; i < nums.size() ; i++) {
            if (nums[i] != nums[i - 1]) {
                count--;
            }
            if (count == 0) {
                ans = nums[i];count=1;
            } else {
                count++;
            }
        }
       
        cout << ans;
        return ans;
    }
};