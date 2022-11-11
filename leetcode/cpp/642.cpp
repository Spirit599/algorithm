class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<int> rr,dd;
        int n = senate.size();
        for(int i = 0; i < n; ++i)
        {
            if(senate[i] == 'R')
                rr.push(i);
            else
                dd.push(i);
        }

        while(!rr.empty() && !dd.empty())
        {
            if(rr.front() < dd.front())
            {
                rr.push(rr.front() + n);
            }
            else
            {
                dd.push(dd.front() + n);
            }
            rr.pop();
            dd.pop();
        }

        if(rr.empty())
            return "Dire";
        else
            return "Radiant";
    }
};