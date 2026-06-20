class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        long long currNum=0,currResult=0;
        int sign=1;
        stack<int>st;
        for(char ch : s){
            if(ch==' ')continue;
            if(isdigit(ch)){
                currNum = currNum*10 + (ch-'0');
                continue;
            }
            if(ch == '+'){
                currResult += currNum*sign;
                sign = 1;
                currNum = 0;
                
            }
            if(ch == '-'){
                currResult += currNum*sign;
                sign = -1;
                currNum = 0;        
            }
            if(ch == '('){
                st.push(currResult);
                st.push(sign);
                sign=1;
                currResult = 0;
            }
            if(ch == ')'){
                currResult += currNum*sign;
                currNum=0;
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();
                currResult = prevResult + (prevSign * currResult);
            }
            
        }
        currResult+=currNum*sign;
        return currResult;
        

    }
};