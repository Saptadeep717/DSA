class Solution {
public:
    string minWindow(string s, string t) {
        int req = t.size();
        unordered_map<char,int>mpp;
        for(auto &it:t)mpp[it]--;

        int i=0, j=0, n = s.size(),len=1e9,sp=-1;
        if(req > n) return "";

        for(j=0;j<n;j++){
            if(mpp.count(s[j])){
                if(mpp[s[j]]<0) req--;
                mpp[s[j]]++;               
            }

            while(req==0){
                    if(len > j-i+1){
                        len = j-i+1;
                        sp=i;
                    }
                    if(mpp.count(s[i])){
                        mpp[s[i]]--;
                        if(mpp[s[i]]<0) req++;
                    }
                    i++;
            }
        }
        if(sp==-1) return "";
        return s.substr(sp, len);
    }
};