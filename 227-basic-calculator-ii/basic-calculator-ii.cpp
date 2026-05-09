class Solution {
public:
    int calculate(string s) {
      char prevOperator = '+';
      s+='+';
      stack<int>st;
      int num = 0;
      for(char ch : s){
        if(ch ==' ')continue;
        if(isdigit(ch)){
            num = num*10 + (ch-'0');
            continue;
        }

        if(prevOperator == '+'){
            st.push(num);
        }
        if(prevOperator == '-'){
            st.push(-1 * num);
        }
        if(prevOperator == '*'){
           int prevVal = st.top();
           st.pop();
           st.push(prevVal * num);
        }

        if(prevOperator == '/'){
        int prevVal = st.top();
           st.pop();
           st.push(prevVal / num);
        }

        prevOperator = ch;
        num = 0;
      }

      int ans = 0;
      while(!st.empty()){
        ans+= st.top();
        st.pop();
      }
      return ans;
    }
};