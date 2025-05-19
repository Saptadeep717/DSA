class Solution {
public:
    string mostCommonWord(string para, vector<string>& banned) {
        vector<string> words;
        unordered_map<string, int> mpp;
        int i = 0;
        string temp = "";

        while (i < para.size()) {
            char c = para[i];
            if (isalpha(c)) {
                temp += tolower(c);
            } else if (c == ' ' || ispunct(c)) {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            }
            i++;
        }
        if (!temp.empty()) {
            words.push_back(temp);
        }
        for (auto& word : words) {
            mpp[word]++;
        }

        for (auto& it : banned) {
            string lowered = "";
            for (char c : it)
                lowered += tolower(c);
            mpp.erase(lowered);
        }
        string val;
        int mx =-1;
        for(auto it:mpp){
            if(it.second > mx){
                mx=it.second;
                val=it.first;
            }
            //cout<<it.first<<" "<<it.second<<endl;
        }
        return val;
    }
};