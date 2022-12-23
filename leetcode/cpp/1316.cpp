typedef unsigned long long ull;

class Solution {
public:
    int distinctEchoSubstrings(string text) {

        int n = text.size();
        ull hashCode[n + 1];
        hashCode[0] = 0;
        ull power[n + 1];
        power[0] = 1;
        ull base = 131;

        for(int i = 0; i < n; ++i)
        {
            hashCode[i + 1] = hashCode[i] * base + text[i];
            power[i + 1] = power[i] * base;
        }

        auto getHash = [&](int left, int right) -> ull {

            return hashCode[right + 1] - hashCode[left] * power[right + 1 - left];
        };

        unordered_set<ull> memo;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; j += 2)
            {
                int mid = (i + j) >> 1;
                if(getHash(i, mid) == getHash(mid + 1, j))
                    memo.insert(getHash(i, j));
            }
        }


        return memo.size();
    }
};