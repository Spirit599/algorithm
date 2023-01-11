class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        int n = row.size();
        int numToIndex[n];
        for(int i = 0; i < n; ++i)
            numToIndex[row[i]] = i;

        int ans = 0;
        for(int i = 0; i < n; i += 2)
        {
            int a = row[i];
            int b = a ^ 1;
            if(row[i + 1] == b)
                continue;
            int c = row[i + 1];
            int bIndex = numToIndex[b];
            swap(row[bIndex], row[numToIndex[c]]);
            numToIndex[c] = bIndex;
        }

        return ans;
    }
};