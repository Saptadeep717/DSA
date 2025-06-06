class Solution {
public:
    //Eulerian path exist
    //all edges visit once and for directed all indeg==outdeg
    //except 2. for that 2 indeg=outdeg+1 for ending node 
    // outdeg-indeg+1 for starting node 
    map<string,multiset<string>>mp;
    vector<string>route;
    void visit(string airport){
        while(mp[airport].size()){
            string nextAirport = *mp[airport].begin();
            mp[airport].erase(mp[airport].begin());
            visit(nextAirport);
        }

        route.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it:tickets){
            mp[it[0]].insert(it[1]);
        }
        visit("JFK");
        return vector<string>(route.rbegin(),route.rend());
    }
};