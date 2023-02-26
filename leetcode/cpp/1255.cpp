class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        int cnt[26];
        memset(cnt, 0, sizeof(cnt));

        for(char c : letters)
            ++cnt[c - 'a'];

        int n = words.size();
        int ans = 0;

        function<void(int, int)> dfs = [&](int idx, int cur) -> void {

            ans = max(ans, cur);
            // printf("%d %d\n", idx, cur);
            if(idx == n)
                return ;

            dfs(idx + 1, cur);

            bool ok = true;
            for(char c : words[idx])
            {
                if(--cnt[c - 'a'] == -1)
                    ok = false;
                cur += score[c - 'a'];
            }

            if(ok)
                dfs(idx + 1, cur);

            for(char c : words[idx])
                ++cnt[c - 'a'];



        };

        dfs(0, 0);

        return ans;
    }
};