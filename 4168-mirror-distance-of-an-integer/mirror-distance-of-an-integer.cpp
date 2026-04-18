class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n){
            int rem = n%10;
            ans = ans*10 + rem;
            n/=10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        int m = rev(n);
        return abs(m-n);
    }
};