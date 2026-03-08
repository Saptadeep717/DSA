class Solution {
public:
    unordered_map<string,int>mpp;
    bool hasDuplicate(string &s1, string &s2){
        vector<int>freq(26);

        for(auto &it : s1){
            if(freq[it-'a']>0) return true;
            freq[it-'a']++;
        }

        for(auto &it : s2){
            if(freq[it-'a']>0) return true;
        }
        return false;
        
    }
    int solve(vector<string>&arr,int idx,int n,string temp){
        if(idx>=n) return temp.size();
        if(mpp.count(temp)) return mpp[temp];
        int include=0,exclude=0;
        if(hasDuplicate(arr[idx],temp)){
            exclude = solve(arr,idx+1,n,temp);
        }else{
            include = solve(arr,idx+1,n,temp+arr[idx]);
            exclude = solve(arr,idx+1,n,temp);
        }

        return mpp[temp] = max(include,exclude);
        
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        mpp.clear();
        string temp="";
        return solve(arr,0,n,temp);
        
    }
};