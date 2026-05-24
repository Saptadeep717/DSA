class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& e) {
        vector<int>temp;
        int n = e.size();
        sort(e.begin(),e.end(),cmp);
        temp.push_back(e[0][1]);
        int len=1;
        for(int i=1; i<n;i++){
            if(e[i][1] > temp.back()){
                temp.push_back(e[i][1]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),e[i][1]) - temp.begin();
                temp[ind] = e[i][1];
            }
        }
        return len;
    }
};