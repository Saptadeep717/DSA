class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       set<long long>st(nums.begin(),nums.end());
       vector<long long>temp(st.begin(),st.end());
       sort(temp.begin(),temp.end());
        int ans=-1;
       for(auto it:temp){
        int len=0;
        long long cur =it;

        if(!st.count((long long)sqrt(cur)) || (long long)sqrt(cur) * (long long)sqrt(cur) != cur){
            while(st.count(cur)){
                len++;
                cur*=cur;
                if (cur > 1e10) break; 
            }
            if(len>=2)ans=max(ans,len);
        }
       }
       return ans;
    }
};