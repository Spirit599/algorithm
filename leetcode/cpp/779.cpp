class Solution {
public:
    int kthGrammar(int n, int k) {

        if(n == 1 && k == 1)
            return 0;
        int pre = kthGrammar(n - 1, (k + 1) / 2);
        if(pre)
        {
            if(k & 1)
                return 1;
            else
                return 0;
        }
        else
        {
            if(k & 1)
                return 0;
            else
                return 1;
        }
    }
};