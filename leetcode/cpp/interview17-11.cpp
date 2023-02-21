class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {

        vector<int> v1;
        vector<int> v2;
        int n = words.size();
        for(int i = 0; i < n; ++i)
        {
            if(words[i] == word1)
                v1.emplace_back(i);
            else if(words[i] == word2)
                v2.emplace_back(i);

        }

        int ans = abs(v1[0] - v2[0]);
        printf("%d\n", ans);
        int n1 = v1.size();
        int n2 = v2.size();
        int idx1 = 0;
        int idx2 = 0;

        while(idx1 < n1 && idx2 < n2)
        {
            if(v1[idx1] < v2[idx2])
            {
                ans = min(ans, v2[idx2] - v1[idx1]);
                ++idx1;
            }
            else
            {
                ans = min(ans, v1[idx1] - v2[idx2]);
                ++idx2;
            }
        }
        return ans;
    }
};