class Solution {
public:
    string pushDominoes(string dominoes) {

        int n = dominoes.size();
        int right[n];
        memset(right, 0x3f, sizeof(right));
        int left[n];
        memset(left, 0x3f, sizeof(left));

        int pre = -1;
        for(int i = 0; i < n; ++i)
        {
            if(dominoes[i] == '.' && pre != -1)
                right[i] = i - pre;
            else if(dominoes[i] == 'R')
                pre = i;
            else if(dominoes[i] == 'L')
                pre = -1;
        }
        pre = n;
        for(int i = n - 1; i >= 0; --i)
        {
            if(dominoes[i] == '.' && pre != n)
                left[i] = pre - i;
            else if(dominoes[i] == 'L')
                pre = i;
            else if(dominoes[i] == 'R')
                pre = n;
        }

        for(int i = 0; i < n; ++i)
        {
            if(dominoes[i] != '.')
                continue;
            if(left[i] < right[i])
                dominoes[i] = 'L';
            else if(left[i] > right[i])
                dominoes[i] = 'R';
        }
        return dominoes;
    }
};