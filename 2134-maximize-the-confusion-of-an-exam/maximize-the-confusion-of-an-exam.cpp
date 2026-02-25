class Solution {
public:
    int func(string &nums, int k, char &ch) {
        int n = nums.size(), l=0,r=0, cnt=0, ans =-1;

        while(r<n){
            if(nums[r]==ch) cnt++;
            while(cnt > k){
                if(nums[l]==ch) cnt--;
                l++;
            }
            if(cnt<=k)ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        char ch1='T',ch2='F';
        return max(func(answerKey,k,ch1),func(answerKey,k,ch2) );
    }
};