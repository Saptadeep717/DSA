class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int cnt =0;
        vector<int>prevNoCustomer(n), nextCustomer(n), temp(n+1);
        prevNoCustomer[0] = 0;
        for(int i=1;i<n;i++){
            if(customers[i-1]=='N'){
                prevNoCustomer[i] = prevNoCustomer[i-1]+1;
            }else prevNoCustomer[i] = prevNoCustomer[i-1];
        }
        nextCustomer[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            if(customers[i+1]=='Y'){
                nextCustomer[i] = nextCustomer[i+1]+1;
            } else nextCustomer[i] = nextCustomer[i+1];
        }

        for(int i=0;i<n;i++){
          
            if(customers[i] == 'Y'){
                temp[i] = 1 + nextCustomer[i] + prevNoCustomer[i];
            }
            else {
                cnt++;
                temp[i] = nextCustomer[i] + prevNoCustomer[i];
            } 
        }

        temp[n] = cnt;

       int mini = INT_MAX, idx =-1;
       for(int i=0;i<=n;i++){
            if(temp[i] < mini){
                mini = temp[i];
                idx = i;
            }
       }
       return idx;
        
    }
};