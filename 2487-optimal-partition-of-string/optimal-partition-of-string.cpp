class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), i=0,j=0;
        int cnt=0;
        unordered_map<char,int>mpp;
        while(j<n){
            mpp[s[j]]++;

            if(j-i+1 > mpp.size()){
                mpp.clear();
                cnt+=1;
                i=j;
                mpp[s[i]]++;
            }
            j++;
        }
        return cnt+1;
    }
};