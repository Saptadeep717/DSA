class Solution {
public:
    int calculate(string s) {
        long long res = 0;   // current result
        long long num = 0;   // current number being built
        int sign = 1;        // +1 or -1

        stack<long long> st; // stores previous state

        for (auto c : s) {

            // ------------------------
            // CASE 1: digit → build number
            // ------------------------
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // ------------------------
            // CASE 2: '+'
            // finalize previous number
            // ------------------------
            else if (c == '+') {
                res += num * sign;
                num = 0;
                sign = 1;
            }

            // ------------------------
            // CASE 3: '-'
            // ------------------------
            else if (c == '-') {
                res += num * sign;
                num = 0;
                sign = -1;
            }

            // ------------------------
            // CASE 4: '('
            // Save current state
            // ------------------------
            else if (c == '(') {
                st.push(res);   // save result so far
                st.push(sign);  // save sign before '('

                // reset for new expression inside ()
                res = 0;
                sign = 1;
                num = 0;
            }

            // ------------------------
            // CASE 5: ')'
            // Resolve inner expression
            // ------------------------
            else if (c == ')') {
                res += num * sign; // finalize inside

                num = 0;

                int prevSign = st.top(); st.pop();
                int prevRes  = st.top(); st.pop();

                // apply sign before '('
                res = res * prevSign;

                // add to previous result
                res = res + prevRes;
            }
        }

        // last number (important)
        res += num * sign;

        return res;
    }
};