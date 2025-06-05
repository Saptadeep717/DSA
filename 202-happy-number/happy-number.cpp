class Solution {
public:
   int square(int num) {
        
        int ans = 0;
        
        while(num > 0) {
            int remainder = num % 10;
            ans += remainder * remainder;
            num /= 10;
        }
        
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = square(slow);
            fast = square(square(fast));
        }while(slow!=fast && fast!=-1);

        return fast==1;
    }
};