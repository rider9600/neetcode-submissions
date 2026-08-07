class Solution {
   public:
    string gcdOfStrings(string str1, string str2) {
        int a = str1.size();
        int b = str2.size();
        int g = gcd(a, b);  // __gcd(a, b) also works
        cout << "GCD = " << g << "\n";
        vector<int> divisors;
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                divisors.push_back(i);
                if (i != g / i) divisors.push_back(g / i);
            }
        }
        sort(divisors.begin(), divisors.end());
        cout << "Divisors of GCD:\n";
        for (int i = divisors.size()-1; i>=0; i--) {
            string first = str1.substr(0, divisors[i]);
            int val1 = a / divisors[i];
            int val2 = b / divisors[i];
            string ans1;
            string ans2;
            for (int i = 0; i < val1; i++) {
                ans1.append(first);
            }
            for (int i = 0; i < val2; i++) {
                ans2.append(first);
            }
            if(ans1==str1 && str2==ans2)
            {
                return first;
            }
        }
        return "";
    }
};