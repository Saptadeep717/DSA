class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        int cnt1,cnt2,cnt3;
        int n = words.size();
        int m;
        string g1 = "qwertyuiop", g2 = "asdfghjkl", g3 = "zxcvbnm";
        for (int i = 0; i < n; i++) {
            string temp = words[i];
            m = temp.size();
            //cout<<m<<endl;
             cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for (int i = 0; i < m; i++) {
                char ch = tolower(temp[i]);
                //cout<<ch<<endl;
                if (g1.find(ch) != string::npos) cnt1++;
                else if (g2.find(ch) != string::npos) cnt2++;
                else if (g3.find(ch) != string::npos) cnt3++;
        }
        if (cnt1 == m || cnt2 == m || cnt3 == m) {
            ans.push_back(temp);
        }

        //cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
    }
    return ans;
}
}
;