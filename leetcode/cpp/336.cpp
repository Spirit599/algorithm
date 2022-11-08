// 哈希函数
// 字符串哈希

typedef unsigned long long ull;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        int n = words.size();
        vector<vector<ull>> preHashCode(n);
        vector<vector<ull>> sufHashCode(n);
        ull base = 131;

        unordered_map<ull, int> memo;

        int maxLength = 0;
        int i = 0;
        for(int i = 0; i < n; ++i)
        {
            string& str = words[i];
            int m = str.size();
            maxLength = max(maxLength, m);
            preHashCode[i].resize(m + 1);
            sufHashCode[i].resize(m + 1);
            vector<ull>& preHash = preHashCode[i];
            vector<ull>& sufHash = sufHashCode[i];

            preHash[0] = 0;
            sufHash[m] = 0;
            for(int j = 0; j < m; ++j)
            {
                preHash[j + 1] = preHash[j] * base + str[j];
                sufHash[m - j - 1] = sufHash[m - j] * base + str[m - j - 1];
            }

            memo[preHash[m]] = i;
        }
        ull power[maxLength + 1];
        power[0] = 1;
        for(int i = 0; i < maxLength; ++i)
            power[i + 1] = power[i] * base;

        function<bool(int, int, int)> checkPalin = [&](int i, int left, int right) {

            ull preCode = preHashCode[i][right + 1] - preHashCode[i][left] * power[right - left + 1];
            ull sufCode = sufHashCode[i][left] - sufHashCode[i][right + 1] * power[right - left + 1];
            if(preCode == sufCode)
            {
                // printf("%d %d %d\n", i,left,right);
                return true;
            }
            else
                return false;
        };


        vector<vector<int>> ret;

        for(int i = 0; i < n; ++i)
        {
            string& str = words[i];
            int m = str.size();

            //一个字符不取
            ull code = sufHashCode[i][0];
            auto it = memo.find(code);
            if(it != memo.end())
            {
                
                if(it->second != i)
                {
                    cout<<code<<endl;
                    ret.push_back({it->second, i});
                }

            }

            //至少取一个字符且是回文
            for(int j = 0; j < m; ++j)
            {
                if(checkPalin(i, 0, j))
                {
                    //范围[j + 1, m - 1]
                    ull code = sufHashCode[i][j + 1] - sufHashCode[i][m] * power[m - j - 1];
                    auto it = memo.find(code);
                    if(it != memo.end())
                    {
                        ret.push_back({it->second, i});
                        if(it->first == 0)
                            ret.push_back({i, it->second});
                    }
                }
                if(checkPalin(i, j, m - 1))
                {
                    if(j == 0)
                        continue;
                    //范围[0, j - 1]
                    ull code = sufHashCode[i][0] - sufHashCode[i][j] * power[j];
                    // printf("code = %d\n", code);
                    auto it = memo.find(code);
                    if(it != memo.end())
                    {
                        ret.push_back({i, it->second});
                        // if(it->first == 0)
                        //     ret.push_back({i, it->second});
                    }
                }
            }

        }

        return ret;

    }
};