// 2410. 运动员和训练师的最大匹配数

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        int ans = 0;
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0;
        int j = 0;
        int n = players.size();
        int m = trainers.size();
        while(i < n && j < m)
        {
        	if(players[i] <= trainers[j])
        	{
        		++i;
        		++j;
        		++ans;
        	}
        	else
        	{
        		++j;
        	}
        }

        return ans;
    }
};