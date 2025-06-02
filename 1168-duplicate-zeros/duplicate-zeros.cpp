class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int sh = 0,i=0;
        for (; sh + i < arr.size(); i++)
            sh += arr[i] == 0;
        for (i = i - 1; sh > 0; --i) {
            if (i + sh < arr.size())
                arr[i + sh] = arr[i];
            if (arr[i] == 0)
                arr[i + --sh] = 0;
        }
    }
};