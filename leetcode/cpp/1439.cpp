
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        int m = mat.size();
        int n = mat[0].size();
        vector<int> vt({0});
        for(int i = 0; i < m; ++i)
        {
            vector<int> vt2;
            for(int num1 : mat[i])
            {
                for(int num2 : vt)
                {
                    vt2.emplace_back(num1 + num2);
                }
            }

            nth_element(vt2.begin(), vt2.begin() + min(k - 1, (int)vt2.size()), vt2.end());
            vt = vector<int>(vt2.begin(), vt2.begin() + min(k, (int)vt2.size()));
        }

        return vt[k - 1];
    }
};