class Solution {
public:
    string countOfAtoms(string formula) {

        unordered_map<string, int> ans;
        vector<unordered_map<string, int>> stk;


        int i = 0;
        int n = formula.size();
        int num = 0;
        string atom;

        while(i < n)
        {

            if(isdigit(formula[i]))
            {
                while(i < n && isdigit(formula[i]))
                {
                    num = 10 * num + formula[i] - '0';
                    ++i;
                }
                --i;
            }
            else if(isupper(formula[i]))
            {
                if(atom != "")
                {
                    if(num == 0)
                        num = 1;
                    ans[atom] += num;
                }
                atom = "";
                num = 0;

                atom.push_back(formula[i]);
                if(i + 1 < n && islower(formula[i + 1]))
                {
                    atom.push_back(formula[i + 1]);
                    ++i;
                }
            }
            else if(formula[i] == '(')
            {
                if(atom != "")
                {
                    if(num == 0)
                        num = 1;
                    ans[atom] += num;
                }
                atom = "";
                num = 0;

                stk.push_back(ans);
                ans.clear();
            }
            else if(formula[i] == ')')
            {
                if(atom != "")
                {
                    if(num == 0)
                        num = 1;
                    ans[atom] += num;
                }
                atom = "";
                num = 0;

                ++i;
                int val = 0;
                while(i < n && isdigit(formula[i]))
                {
                    val = 10 * val + formula[i] - '0';
                    ++i;
                }
                --i;
                if(val == 0)
                    val = 1;

                unordered_map<string, int> tmp;

                auto& pre = stk.back();
                for(auto& kv : pre)
                {
                    tmp[kv.first] += kv.second;
                }
                for(auto& kv : ans)
                {
                    tmp[kv.first] += val * kv.second;
                }
                ans = tmp;
                stk.pop_back();
            }
            ++i;
        }

        if(atom != "")
        {
            if(num == 0)
                num = 1;
            ans[atom] += num;
        }
        atom = "";
        num = 0;

        vector<pair<string, int>> vpsi;
        for(auto& kv : ans)
            vpsi.emplace_back(kv.first, kv.second);
        sort(vpsi.begin(), vpsi.end());

        string ret;
        for(auto& psi : vpsi)
        {
            ret += psi.first;
            if(psi.second != 1)
                ret += to_string(psi.second);
        }

        return ret;
    }
};