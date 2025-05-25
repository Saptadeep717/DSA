class MyCalendar {
    // vector<pair<int, int>> books;
    map<int, int> mpp;

public:
    MyCalendar() {}

    bool book(int s, int e) {
        // for (auto p : books) {
        //     if (max(p.first, startTime) < min(endTime, p.second))
        //         return false;
        // }
        // books.push_back({startTime, endTime});
        // return true;
        auto next = mpp.lower_bound(s);
        if (next != mpp.end() && next->first < e)
            return false;
        if (next != mpp.begin() && prev(next)->second > s)
            return false;
        mpp[s] = e;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */