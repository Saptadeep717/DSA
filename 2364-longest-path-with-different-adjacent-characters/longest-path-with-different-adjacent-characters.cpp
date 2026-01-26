class Solution {
public:
    int result = INT_MIN;

    int dfs(int curr, int parent, unordered_map<int,vector<int>>&adj,string &s){
        int longest=0, secondLongest=0;

        for(auto &child : adj[curr]){
            if(child==parent)continue;

            int child_longest_length = dfs(child,curr,adj,s);
            if(s[child]==s[curr]) continue;

            if(child_longest_length > secondLongest) secondLongest = child_longest_length;

            if(secondLongest > longest) swap(secondLongest,longest);
        }
        // send ans to upwards to check other side
        int koi_ek_accha = max(secondLongest, longest) + 1;
        // root is better than both left and right subtree 
        int root_accha = 1;
        // any subtree with U path is the best
        int neeche_se_accha_mil_gaya = 1 + secondLongest + longest;

        result = max({result,koi_ek_accha,root_accha,neeche_se_accha_mil_gaya });

        return max(koi_ek_accha,root_accha);
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int,vector<int>>adj;

        for(int i=1;i<n;i++){
            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,-1,adj,s);

        return result;
    }
};