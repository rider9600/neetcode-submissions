class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int one = 0, two = 0;
       int three = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                one++;
            } else if (bills[i] == 10) {
                if (one >= 1) {
                    one--;
                    two++;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (one >= 1 && two >= 1) {
                    one -= 1;
                    two -= 1;
                    three++;
                } else if (one >= 3) {
                    one -= 3;
                    three++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};