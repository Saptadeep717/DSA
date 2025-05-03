class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>ans;
       unordered_map<int,int>mpp;
       sort(changed.begin(),changed.end());
        int n = changed.size();
        if(n%2 != 0) return {};
        for(int i=0;i<n;i++){
            mpp[changed[i]]++;
        }
        for(int num : changed){
            if(mpp[num]==0) continue;
            if(mpp[num * 2]==0) return {};
            ans.push_back(num);
            mpp[num]--;
            mpp[num*2]--;
        }
        return ans;


       
    }
};