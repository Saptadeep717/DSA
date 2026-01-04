class Solution {
public:
    static constexpr int N = 100000;
    vector<bool> isPrime;

   Solution() {
        // Sieve of Eratosthenes
        isPrime.assign(N + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {

            //Case 1: p^3 
            int p = round(cbrt(x));
            if ((long long)p * p * p == x && isPrime[p]) {
                ans += 1 + p + p * p + x;
                continue;
            }

            //Case 2: p * q
            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    int a = d;
                    int b = x / d;

                    if (a != b && isPrime[a] && isPrime[b]) {
                        ans += 1 + a + b + x;
                    }
                    break;
                }
            }
        }

        return ans;
    }
};