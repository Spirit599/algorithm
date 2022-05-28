class Solution {
public:
    string originalDigits(string s) {

        //unordered_map<char, int> memo;
        int memo[125];
        memset(memo, 0, sizeof(memo));

        for(char ch : s)
            ++memo[ch];

        int x[10];

        x[0] = memo['z'];
        // memo['e'] -= memo['z'];
        // memo['r'] -= memo['z'];
        // memo['o'] -= memo['z'];
        x[2] = memo['w'];
        x[4] = memo['u'];
        x[6] = memo['x'];
        x[8] = memo['g'];

        x[1] = memo['o'] - x[4] - x[2] - x[0];
        x[3] = memo['r'] - x[4] - x[0];
        x[5] = memo['f'] - x[4];
        x[7] = memo['s'] - x[6];

        x[9] = memo['i'] - x[5] - x[6] - x[8];

        string ans;
        for (int i = 0; i < 10; ++i)
        {
            cout<<x[i]<<" ";
            for (int j = 0; j < x[i]; ++j)
            {
                ans.push_back(i + '0');
            }
        }

        return ans;
    }
};