class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
           
            if (nums[(i + j) / 2] == target) {
                  cout<<i<<" 1 "<<j<<nums[(i + j) / 2]<<endl;
                return (i + j) / 2;
            } else if (nums[(i + j) / 2] > target) {
                  cout<<i<<" 2 "<<j<<nums[(i + j) / 2]<<endl;
                j=(i+j)/2-1;
            } else if (nums[(i + j) / 2] <target) {
                  cout<<i<<" 3 "<<j<<nums[(i + j) / 2]<<endl;
                i=(i+j)/2+1;
            }
           
        }
        return -1;
    }
};
