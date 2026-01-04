class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), m = popped.size();
        stack<int>st;
        if(n!=m) return false;
        int i=0,j=0;
        while(i<n && j<m){
            st.push(pushed[i]);
            while(j<m && !st.empty() && st.top()== popped[j]){
                st.pop();
                j++;
            }
            i++;
        }

        return st.empty();

    }
};