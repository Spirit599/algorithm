// bool cmp(pair<int, int>& p1, pair<int, int> p2)
// {
//     if(p1.second != p2.second)
//         return p1.second < p2.second;
//     else
//         return p1.first < p2.first;
// }

//优先队列 堆

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        //vector<pair<int, int>> vp;

        int m = mat.size();
        int n = mat[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < m; ++i)
        {
            int j = 0;
            for (; j < n; ++j)
            {
                if(mat[i][j] != 1)
                    break;
            }
            cout<<i<<" "<<j<<endl;
            pq.push({j, i});
        }

        //sort(vp.begin(), vp.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};