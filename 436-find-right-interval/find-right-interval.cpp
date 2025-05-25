class Solution {
public:

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < intervals.size(); i++) {
            intervals[i].push_back(i);
        }
       

        vector<int> v(n,-1);
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b)
        { return a[0]<b[0];
        }
        );
        
        for(int i=0;i<n;i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            int ind=intervals[i][2];

            auto it = lower_bound(intervals.begin(), intervals.end(), e, [](const vector<int>& v, int value) {
        return v[0] < value;
    });

        if(it!=intervals.end()) v[ind] = (*it)[2];

        }

        return v;

       
    }
};