class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int extraFuel = 0, pos =0;
        int totC = accumulate(cost.begin(),cost.end(),0);
        int totG = accumulate(gas.begin(),gas.end(),0);
        if(totG < totC) return -1;

        for(int i =0; i<gas.size(); i++){
            extraFuel += gas[i]-cost[i];
            if(extraFuel<0){
                pos = i + 1;
                extraFuel = 0;
                
            }
            
        }
        return pos;
    }
};