class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(a[i] > 0) temp.push_back(a[i]);
            else{
                while(!temp.empty() && temp.back() > 0 && temp.back() < abs(a[i])) temp.pop_back();
                if(!temp.empty() && temp.back() == abs(a[i])) temp.pop_back();
                else if(temp.empty() || temp.back() < 0) temp.push_back(a[i]);
            }
        }
        return temp;
    }
};