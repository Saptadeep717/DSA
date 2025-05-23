class Solution {
public:
    bool isPerfectSquare(int n) { return (sqrt(n) * sqrt(n)) == n; }
    bool judgeSquareSum(int c) {
        int start = 0, end = ceil(sqrt(c));
        bool flag=false;

        while (start <= end) {
            //int mid = (start + end) / 2;

            // if (isPerfectSquare(c - mid * mid))
            //     return true;
            // else {
            //     if(mid*mid )
            // }
            long long val = (long long)start*start + (long long)end*end;
            if(val > c) end--;
            else if(val < c) start++;
            else{
                flag=true;
                break;
            }

        }
        return flag;
    }
};