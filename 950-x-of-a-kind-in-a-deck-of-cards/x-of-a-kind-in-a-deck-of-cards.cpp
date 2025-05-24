class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mpp;
        if(deck.size()<=1) return false;
        int g=-1;
        for(auto it:deck)mpp[it]++;
        int maxi=-1e9,mini=1e9;
        for(auto it:mpp){
            if(g==-1) g=it.second;
            else g=gcd(g,it.second);
        }
       return g>=2;
    }
};