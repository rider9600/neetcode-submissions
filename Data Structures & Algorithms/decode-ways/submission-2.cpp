class Solution {
   public:
    int fib(int n) {
        if (n <= 0) return 1;
        if (n == 1) return 2;
        int a = 1, b = 2;
        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (s[0] == '0') return 0;
        if (n == 1) return 1;
        vector<int> groups;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '0') return 0;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '0' && s[i - 1] != '1' && s[i - 1] != '2') return 0;
        }
        for (int i = 0; i < n - 1; i++) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a == 1 || (a == 2 && b <= 6)) {
                if (b == 0) {
                    if (cnt > 0) cnt--;
                    groups.push_back(cnt);
                    cnt = 0;
                    i++;
                } else {
                    cnt++;
                }
            } else {
                if (cnt > 0) groups.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt > 0) groups.push_back(cnt);
        int ans = 1;
        for (int x : groups) ans *= fib(x);
        return ans;
    }
};