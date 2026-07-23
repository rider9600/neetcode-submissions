
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        double ans = INT_MIN;
        double prod = 1;
        double prefix_up_to_first_neg = 1;
        bool has_neg = false;

        for (int x : nums) {
            ans = std::max(ans, (double)x); 
            
            if (x == 0) {
                prod = 1;
                has_neg = false; // Reset for the new segment
                continue;
            }
            
            prod *= x;
            
            // This implicitly evaluates dropping the LAST negative 
            // (since we check max before multiplying future negatives)
            ans = std::max(ans, prod); 

            if (prod < 0) {
                if (has_neg) {
                    // This explicitly drops the FIRST negative and its prefix
                    ans = std::max(ans, prod / prefix_up_to_first_neg); 
                } else {
                    has_neg = true;
                    prefix_up_to_first_neg = prod; 
                }
            }
        }
        
        return ans;
    }
};