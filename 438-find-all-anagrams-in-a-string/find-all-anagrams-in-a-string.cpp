class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ws = p.size(), n = s.size();
        unordered_map<char,int>mpp;
        for(auto &it:p)mpp[it]++;
        vector<int>ans;
        for(int i=0,j=0; j<n;j++){
            mpp[s[j]]--;
            if(mpp[s[j]]==0)mpp.erase(s[j]);
            while(j-i+1 > ws){
                mpp[s[i]]++;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }
            if(mpp.size()==0)ans.push_back(i);
        }
        return ans;
    }
};