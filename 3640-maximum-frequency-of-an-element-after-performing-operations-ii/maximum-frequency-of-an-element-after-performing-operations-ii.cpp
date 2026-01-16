class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int>freq;
        map<int,int>diff;
        int maxVal = *max_element(begin(nums),end(nums)) + k;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;

            int L = max(nums[i]-k , 0);
            int R = min(nums[i]+k, maxVal);
            diff[L]+=1;
            diff[R+1]-=1;
            diff[nums[i]]+=0;
        }
        int cumSum = 0,result=1;
        for(auto it:diff){
            int val = it.first;
            it.second+=cumSum;
            int freqPresent = freq[val];
            int neededFreq = it.second - freqPresent;
            int freqCanBeAcheievd = min(neededFreq, numOperations);
            result = max(result, freqPresent+freqCanBeAcheievd);
            cumSum = it.second;
        }

        return result;
    }
};