class TopVotedCandidate {
public:
    vector<pair<int, int>> onlineQuery;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {

        int n = persons.size();
        int maxVoted = 0;
        int memo[n];
        memset(memo, 0, sizeof(memo));

        for(int i = 0; i < n; ++i)
        {
            ++memo[persons[i]];
            int getVoted = memo[persons[i]];
            if(getVoted >= maxVoted)
            {
                maxVoted = getVoted;
                onlineQuery.emplace_back(times[i], persons[i]);
            }
        }
    }
    
    int q(int t) {

        
        auto it = upper_bound(onlineQuery.begin(), onlineQuery.end(), make_pair(t + 1, -1));
        --it;
        return it->second;

    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */