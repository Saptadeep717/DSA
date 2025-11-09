class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(),i=0,j=0,maxi=1;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[fruits[j]]++;

            if(mpp.size()<=2){
                maxi = max(maxi, j-i+1);
            }

            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0)mpp.erase(fruits[i]);
                i++;
                if(mpp.size()==2) maxi = max(maxi, j-i+1);
            }
            j++;
        }
        return maxi;
    }
};