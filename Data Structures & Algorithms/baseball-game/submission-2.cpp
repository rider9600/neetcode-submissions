class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (string x : operations) {

            if (x != "C" && x != "D" && x != "+") {
                st.push(stoi(x));
            } 
            else if (x == "C") {
                st.pop();
            } 
            else if (x == "D") {
                st.push(2 * st.top());
            } 
            else { // "+"
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int c = a + b;

                st.push(b);
                st.push(a);
                st.push(c);
            }
        }

        int sum = 0;

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};