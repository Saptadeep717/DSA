class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int>l;
        vector<int>v;
        int i=0,n=nums.size();
        for(int j=0;j<n;j++){
            while(!l.empty() && l.back()< nums[j]) l.pop_back();
            l.push_back(nums[j]);

            while(j-i+1 > k){
                if(nums[i]==l.front())l.pop_front();
                i++;
            }
            if(j-i+1 == k){
                int val = l.empty() ? 0 : l.front();
                v.push_back(val);
            }
        }
        return v;
    }
};