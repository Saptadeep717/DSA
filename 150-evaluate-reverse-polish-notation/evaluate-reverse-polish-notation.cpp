class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            if(tokens[i] != "+" && tokens[i] != "-" && 
                tokens[i] != "*" && tokens[i] != "/" ){
                int num = stoi(tokens[i]);
                st.push(num);
            }else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i]=="+") st.push(a+b);
                else if(tokens[i]=="-") st.push(b-a);
                else if(tokens[i]=="*") st.push(a*b);
                else if(tokens[i]=="/") st.push(b/a);
            }
        }

        return st.top();
    }
};