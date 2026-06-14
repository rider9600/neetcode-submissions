class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
      int i = 0, j = nums.size() - 1;
        while (i <= j) {
           
            if (nums[(i + j) / 2] == target) {
                  cout<<i<<" 1 "<<j<<nums[(i + j) / 2]<<endl;
                return (i + j) / 2;
            } else if (nums[(i + j) / 2] > target) {
                  cout<<i<<" 2 "<<j<<nums[(i + j) / 2]<<endl;
                  if(i==j)return i;
                j=(i+j)/2-1;
                if(j<i)return i;
            } else if (nums[(i + j) / 2] <target) {
                  cout<<i<<" 3 "<<j<<nums[(i + j) / 2]<<endl;
                     if(i==j)return i+1;
                i=(i+j)/2+1;

            }
           
        }
        return -1;  
    }
};