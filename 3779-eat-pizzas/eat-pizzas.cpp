class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
    sort(pizzas.begin(), pizzas.end());
     int n = pizzas.size();
         int m = n / 4;
        int oddC = (m + 1) / 2;
        int evenC = m - oddC;
        
        long long total = 0;
        int left =0,right = n - 1;
        
        
        for (int i = 0; i < oddC; i++) {
            total += pizzas[right];
            right--;
            //left += 3;
        }
        for (int i = 0; i < evenC; i++) {
            right--;
            total += pizzas[right];
            right--;
        }
        return total;
    }
};