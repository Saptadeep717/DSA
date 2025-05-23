class Solution {
public:
    int findNthDigit(int n) {
        long long start=1,end=9, digitInNum=1;

        //to check n in which block of 9, 2*90 , 3*900...

        while(n > digitInNum * end){
            n-= digitInNum * end;
            digitInNum++;
            start *=10;
            end *=10;

        }
        //now after getting right block make the number 
        //in which  nth digit is present
        //n-1 as 0 based indexing

        int num = start + (n-1)/digitInNum;

        string numStr = to_string(num);

        //now which digit place value i need

        int i = (n-1)%digitInNum;
        return numStr[i]-'0';


    }
};