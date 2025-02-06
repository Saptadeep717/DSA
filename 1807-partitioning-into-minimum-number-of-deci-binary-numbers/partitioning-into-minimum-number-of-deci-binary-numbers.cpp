class Solution {
public:
    int minPartitions(string n) {
        int s=n.size();
        int ans=-1,val;
        for(int i=0;i<s;i++){
            val= (n[i]-'0');
           ans=max(ans,val);
        }
        return ans;
    }
};