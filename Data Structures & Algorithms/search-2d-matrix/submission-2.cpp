class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         
        int rr=matrix.size();
        int cc=matrix[0].size(); 
        int l = 1;
        int r = rr*cc;
        int ans = 0;
       int x=target;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long sq = matrix[(mid-1)/cc][(mid-1)%cc];

            if (sq == x) {
                return true;
            } else if (sq < x) {
              
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return false;
    }
};
