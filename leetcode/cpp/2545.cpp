class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        
        sort(score.begin(), score.end(), [&](vector<int>& a1, vector<int>& a2)
        {
            return a1[k] > a2[k];
        });

        return score;
    }
};