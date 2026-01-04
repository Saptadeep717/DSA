class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (ast[i] > 0) {
                temp.push_back(ast[i]);
            } else {
                while (!temp.empty() && temp.back() > 0 &&
                       temp.back() < abs(ast[i])) {
                    temp.pop_back();
                }
                if (!temp.empty() && temp.back() == abs(ast[i]))
                    temp.pop_back();
                else if(temp.empty() || temp.back() < 0) temp.push_back(ast[i]);    
            }
        }
        return temp;
    }
};