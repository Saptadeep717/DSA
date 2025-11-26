class Solution {
public:
    int rev(int x){
        long long ans = 0;
        while(x){
            int rem = x%10;
            ans = ans*10 + rem;
            x/=10;
        }
        return ans;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;

        int z = (int)rev(x);

        return (z==x);
    }
};