class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>> ans;
        int n1 = firstList.size();
        int n2 = secondList.size();
        int idx1 = 0;
        int idx2 = 0;

        while(idx1 < n1 && idx2 < n2)
        {
            int ll = max(firstList[idx1][0], secondList[idx2][0]);
            int rr = min(firstList[idx1][1], secondList[idx2][1]);
            if(ll <= rr)
                ans.push_back({ll, rr});
            if(firstList[idx1][1] < secondList[idx2][1])
                ++idx1;
            else
                ++idx2;
        }
        return ans;
    }
};