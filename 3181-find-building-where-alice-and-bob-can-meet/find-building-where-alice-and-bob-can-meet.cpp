class Solution {
public:
    void build(int i, int l, int r, vector<int>&seg, vector<int>&h){
        if(l==r){
            seg[i]=l;
            return;
        }
        int m = l + (r-l)/2;
        build(2*i+1,l,m,seg,h);
        build(2*i+2,m+1,r,seg,h);
        int leftIdx = seg[2*i+1];
        int rightIdx =seg[2*i+2];
        if(h[leftIdx] >= h[rightIdx])seg[i]=leftIdx;
        else seg[i]=rightIdx;
    }
    vector<int>constructSeg(vector<int>& heights){
        int n = heights.size();
        vector<int>seg(4*n);
        build(0,0,n-1,seg,heights);
        return seg;
    }
    int query(int a,int b,int i,int s, int e,vector<int>&seg, vector<int>&h){
        if(a>e || b<s)return -1;
        if(s>=a && e<=b) return seg[i];
        int m = s + (e-s)/2;

        int leftIdx = query(a,b,2*i+1,s,m,seg,h);
        int rightIdx = query(a,b,2*i+2,m+1,e,seg,h);
        if(leftIdx==-1) return rightIdx;
        if(rightIdx==-1) return leftIdx;
        if(h[leftIdx] >= h[rightIdx])return leftIdx;
        else return rightIdx;
    }
    int RMIQ(int a, int b, vector<int>&seg, vector<int>&h, int n){
        return query(a,b,0,0,n-1,seg,h);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        
        int n = heights.size();
        vector<int> seg = constructSeg(heights);
        vector<int> results;
        for (auto& it : queries) {
            int min_idx = min(it[0], it[1]);
            int max_idx = max(it[0], it[1]);

            if (min_idx == max_idx) {
                results.push_back(min_idx);
                continue;
            } else if (heights[max_idx] > heights[min_idx]) {
                results.push_back(max_idx);
                continue;
            } else {
                int l = max_idx + 1, r = n - 1;
                int result_idx = INT_MAX;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    int idx = RMIQ(l, mid, seg,heights,n);

                    if (heights[idx] > max(heights[max_idx],heights[min_idx]))
                        {
                            result_idx = min(result_idx,idx);
                            r=mid-1;

                        }else{
                            l = mid+1;
                        }

                        
                }
                if(result_idx==INT_MAX)results.push_back(-1);
                else results.push_back(result_idx);
            }
        }
        return results;
    }
};