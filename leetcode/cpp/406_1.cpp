// 406. 根据身高重建队列
// 贪心
bool cmp(const vector<int>& v1, const vector<int>& v2)
{
	if(v1[0] != v2[0])
		return v1[0] > v2[0];
	else
		return v1[1] < v2[1];
}
class Solution {
public:
	
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

    	sort(people.begin(), people.end(), cmp);

    	vector<vector<int>> ans;
    	for(auto& v : people)
    	{
    		ans.insert(ans.begin() + v[1], std::move(v));
    	}
    	return ans;
    }
};