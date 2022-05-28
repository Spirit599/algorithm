bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if(v1[1] != v2[1])
        return v1[1] < v2[1];
    else
        return v1[0] < v2[0];
}
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end(), cmp);
        int ans = 0;
        
    }
};