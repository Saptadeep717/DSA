class Solution {
public:
    int calculate(string s) {
        long long currentFormedNum=0, currentFormedResult=0;
        int sign = 1;
        stack<int>st;
        for(char c : s){
            if(c ==' ') continue;
            if(isdigit(c)){
                currentFormedNum = currentFormedNum*10 + (c-'0');
                continue;
            }
            if(c == '+'){
                currentFormedResult += currentFormedNum*sign;
                sign = 1;
                currentFormedNum = 0;
            }

            if(c == '-'){
                currentFormedResult += currentFormedNum*sign;
                sign = -1;
                currentFormedNum = 0;
            }

            if(c == '('){
                st.push(currentFormedResult);
                st.push(sign);
                currentFormedResult=0;
                currentFormedNum = 0;
                sign = 1;
            }

            if(c == ')'){
                currentFormedResult += currentFormedNum*sign;
                currentFormedNum = 0;
                int prevSign = st.top();
                st.pop();
                int prevVal = st.top();
                st.pop();
                currentFormedResult = prevVal + (currentFormedResult * prevSign);
            }
            
        }
        currentFormedResult += currentFormedNum*sign;
        return (int)currentFormedResult;
    }
};