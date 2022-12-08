class Solution {
public:
    unordered_map<int, int> blackToWhite;
    int limit;
    Solution(int n, vector<int>& blacklist) {

        int m = blacklist.size();
        limit = n - m;
        unordered_set<int> isBlack;
        for(int b : blacklist)
        {
            if(b >= limit)
                isBlack.insert(b);
        }

        int w = limit;
        for(int b : blacklist)
        {
            if(b < limit)
            {
                while(isBlack.count(w))
                    ++w;
                blackToWhite[b] = w++;

            }
        }


    }
    
    int pick() {

        int r = rand() % limit;
        auto it = blackToWhite.find(r);
        if(it == blackToWhite.end())
            return r;
        else
            return blackToWhite[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */