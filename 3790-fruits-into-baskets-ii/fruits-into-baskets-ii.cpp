class Solution {
public:
    void build(int i, int l, int r, vector<int>&seg, vector<int>&baskets){
        if(l==r){
            seg[i]=baskets[l];
            return;
        }
        int m = l + (r-l)/2;
        build(2*i+1,l,m,seg,baskets);
        build(2*i+2,m+1,r,seg,baskets);
        seg[i] = max(seg[2*i+1], seg[2*i+2]);
    }

    bool query(int i, int s, int e, vector<int>&seg, int fruit){
        if(seg[i] < fruit) return false;
        if(s==e){
            seg[i]=-1;
            return true;
        }
        int mid = s + (e-s)/2;
        bool placed = false;
        if(seg[2*i+1]>=fruit){
            placed = query(2*i+1,s,mid,seg,fruit);
        }else{
            placed = query(2*i+2,mid+1,e,seg,fruit);
        }
        seg[i]= max(seg[2*i+1],seg[2*i+2]);
        return placed;
        
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int>seg(4*n);
        build(0,0,n-1,seg,baskets);
        int unplaced=0;

        for(auto &it:fruits){
            if(query(0,0,n-1,seg,it)==false)unplaced++;
        }
        return unplaced;
    }
};