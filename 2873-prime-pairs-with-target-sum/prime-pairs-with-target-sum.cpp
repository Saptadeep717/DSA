class Solution {
public:
    vector<long long int>primeCalculate(int n){
        vector<long long int>sieve(n+1,1);
        sieve[1] =sieve[0] =0;
        //for(int i=3;i<=n;i+=2) sieve[i]=1;
        for(long long int i=2;i*i<=n;i++){
            if(sieve[i]){
                for(long long int j=i*i;j<=n;j+=i)sieve[j]=0;
            }
        }

        return sieve;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>ans;
        vector<long long int>sieve = primeCalculate(n);

        // map<int,int>mpp;
        // for(auto i=0;i<=n;i++){
        //     if(sieve[i]==1) mpp.insert({i,i});
        // }

        for(int i=2;i<=n/2;i++){

            int key = n-i;
            if(sieve[i] && sieve[key]) ans.push_back({i,key});
        }

       

        return ans;
    }
};