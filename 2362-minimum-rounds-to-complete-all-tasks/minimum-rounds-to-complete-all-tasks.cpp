class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)mpp[tasks[i]]++;
        int cnt =0;
        for(auto &it:mpp){
            if(it.second==1) return -1;
            else{
                int val = (it.second%3==0) ? (it.second/3) : (it.second/3) + 1;
                cnt +=val;
            }
        }
        return cnt;
        
    }
};