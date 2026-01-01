class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), cnt=0;
        vector<int>v = digits;
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9) cnt++;
            else break;
        }
        cout<< cnt << endl;
        if(cnt == n){
            vector<int>v1(n+1,0); 
            v1[0]=1;
            //for(auto it : v) cout<<it<<" ";
            return v1;
        }
        if(cnt==0){
            v[n-1] = v[n-1]+1;
            return v;
        }
        int i = n-1;
        while(cnt > 0){
            v[i] = 0;
            cnt--;
            i--;
        }
        v[i] = v[i]+1;
        return v;

    }
};