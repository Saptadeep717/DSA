class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
       vector<int>ans,A;
       for(int i=0;i<s.size();i++){
        if(s[i]=='|')A.push_back(i);
       }
       for(int q=0;q<queries.size();q++){
        int i = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
        //  int j = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() ;
          int j = lower_bound(A.begin(), A.end(), queries[q][1]+1) - A.begin() ;
         j--;
        ans.push_back(i < j ? (A[j] - A[i]) - (j - i) : 0);

       }
       return ans;
    }
};