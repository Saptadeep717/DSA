class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if (n==0) return 0;
        sort(tokens.begin(),tokens.end());
        int score=0;
        if(power < tokens[0]) return 0;
        int i=0,j=n-1;
        while(i<=j){
            if(power < tokens[i]){
                power+=tokens[j];
                score-=1;
                j--;
            }
            power-=tokens[i];
            score+=1;
            i++;
        }
        return score;
    }
};