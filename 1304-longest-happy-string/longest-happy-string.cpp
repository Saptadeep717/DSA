class Solution {
public:
    using P = pair<int,char>;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P>pq;

        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        string ans;
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            if(ans.size()>=2 && ans[ans.size()-1]==ch && ans[ans.size()-2]==ch){
                if(pq.empty())break;
                int freqAlt = pq.top().first;
                char chAlt = pq.top().second;
                pq.pop();
                ans.push_back(chAlt);
                freqAlt-=1;
                if(freqAlt>0)pq.push({freqAlt,chAlt});

            }else{ 
                freq--; 
                ans.push_back(ch);
            }
            if(freq>0)pq.push({freq,ch});
        }
        return ans;
    }
};