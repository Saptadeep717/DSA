class Solution {
public:
    int lengthOfLongestSubstring(string s) {
   int i=0, j=0,n=s.size(),mx=-1;
        if(n==0) return 0;
    unordered_map<char,int>mpp;
    while(j<n){
        mpp[s[j]]++;
        
         if(mpp.size()==j-i+1){
            mx= max(mx,j-i+1);
            j++;
        }
        
        else if(mpp.size()<j-i+1){
            while(mpp.size()<j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]]==0) mpp.erase(s[i]);
                i++;
            }
            
            j++;
            
            
        }
    }
    return mx;
    
    }
};