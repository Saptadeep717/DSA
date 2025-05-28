class SnapshotArray {
public:
map<int, map<int, int>> mpp;
int snapId=0;

    SnapshotArray(int length) {
       for(int i=0;i<length;i++){
        map<int,int>m;
        m[0]=0;
        mpp[i]=m;
       }
    }
    
    void set(int index, int val) {
        mpp[index][snapId]=val;
    }
    
    int snap() {
       return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto it = mpp[index].upper_bound(snap_id);
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */