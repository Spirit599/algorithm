class Solution {
public:
    bool equationsPossible(vector<string>& equations) {

        int fa[26];
        memset(fa, -1, sizeof(fa));

        auto findFa = [&](int a) {

            while(fa[a] != -1)
                a = fa[a];
            return a;
        };

        auto unionFa = [&](int a, int b) {

            int f1 = findFa(a);
            int f2 = findFa(b);
            if(f1 != f2)
                fa[f1] = f2;
        };

        vector<pair<int, int>> diff;
        for(auto& str : equations)
        {
            int a = str[0] - 'a';
            int b = str[3] - 'a';
            if(str[1] == '!')
            {
                diff.emplace_back(a, b);
                continue;
            }
            unionFa(a, b);
        }

        for(auto& pii : diff)
        {
            int a = pii.first;
            int b = pii.second;
            if(findFa(a) == findFa(b))
                return false;
        }
        return true;
    }
};