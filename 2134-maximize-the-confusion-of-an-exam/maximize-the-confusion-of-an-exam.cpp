class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0,n=answerKey.size(),tCnt=0,fCnt=0,res=-1;

        while(j<n){
            if(answerKey[j]=='T'){
                tCnt++;
            }else{
                fCnt++;
            }

            while(min(tCnt,fCnt) > k){
                if(answerKey[i++]=='T')tCnt--;
                else fCnt--;
            }

            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};