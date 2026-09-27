class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size(), i=0, j=n-1;
        int boat=0;

        while(i<j){
            if(people[i]+people[j]<=limit){
                boat++;
                i++;
                j--;
            }
            else{
                boat++;
                j--;
            }
        }
        if(i==j)boat+=1;
        return boat;
    }
};