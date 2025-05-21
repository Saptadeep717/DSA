class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        unordered_map<char, int> rowMap;
        string row1 = "qwertyuiop", row2 = "asdfghjkl", row3 = "zxcvbnm";

        for (char ch : row1)
            rowMap[ch] = 1;
        for (char ch : row2)
            rowMap[ch] = 2;
        for (char ch : row3)
            rowMap[ch] = 3;

        for (string word : words) {
            int currentRow = rowMap[tolower(word[0])];
            bool valid = true;

            for (char ch : word) {
                if (rowMap[tolower(ch)] != currentRow) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                ans.push_back(word);
        }

        return ans;
    }
};