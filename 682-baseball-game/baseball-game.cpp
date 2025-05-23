class Solution {
public:

bool isNumber(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if(c=='-') continue;
        if (!isdigit(c)) return false;
    }
    return true;
}
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            string temp=ops[i];
            if(isNumber(temp)) v.push_back(stoi(temp));
            if(temp=="C" && i>=1)v.pop_back();
            if(temp=="D" && i>=1)v.push_back(2* v.back());
            if(temp=="+" && i>=2)v.push_back(v.back() + v[v.size()-2]);
            

        }
        for(auto it:v){
            cout<< it<<" ";
        }
        return accumulate(v.begin(),v.end(),0);
    }
};