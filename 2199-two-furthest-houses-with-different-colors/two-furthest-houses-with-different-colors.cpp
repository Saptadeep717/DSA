class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans =0;
        int i=0,j=n-1;
        for(int k=0;k<n;k++){
            if(colors[i] != colors[k] && colors[j] != colors[k]){
                    ans = max({ans,abs(j-k), abs(i-k)} );
                }
                else if(colors[i] != colors[k]){
                    ans = max(ans,abs(i-k));
                }

                else if(colors[j] != colors[k]){
                    ans = max(ans,abs(j-k));
                }
                
        }
        return ans;
    }
};