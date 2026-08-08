class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int i = s.size() - 1;

        while (i >= 0) {

            // Closing bracket
            if (s[i] == ']') {
                st.push("]");
                i--;
            }

            // Opening bracket
            else if (s[i] == '[') {

                // Get number before '['
                int j = i - 1;
                string num = "";

                while (j >= 0 && isdigit(s[j])) {
                    num.push_back(s[j]);
                    j--;
                }

                // Since we are moving right -> left,
                // digits were collected in reverse order.
                reverse(num.begin(), num.end());

                int number = stoi(num);

                // Get everything inside [ ]
                string temp = "";

                while (!st.empty() && st.top() != "]") {
                    temp += st.top();
                    st.pop();
                }

                // Remove "]"
                if (!st.empty())
                    st.pop();

                // Duplicate
                string dup = "";

                for (int k = 0; k < number; k++) {
                    dup += temp;
                }

                st.push(dup);

                // Skip the digits
                i = j;
            }

            // Normal character
            else {
                st.push(string(1, s[i]));
                i--;
            }
        }

        // Build final answer
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};