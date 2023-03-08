class Solution {
public:
    vector<string> braceExpansionII(string expression) {

        vector<set<string>> stk;
        vector<char> opt;
        expression.push_back(0);

        auto compute = [&]() {
            int n = stk.size();
            // printf("%d %d\n", stk.size(), opt.size());
            auto& ll = stk[n - 2];
            auto& rr = stk[n - 1];
            // for(auto& str : stk[n - 1])
            //     cout<<str<<" ";
            // cout<<endl;
            // for(auto& str : stk[n - 2])
            //     cout<<str<<" ";
            // cout<<endl;
            // cout<<opt.back()<<endl;
            if(opt.back() == '+')
            {
                ll.merge(rr);
            }
            else
            {
                set<string> tmp;
                for (auto &left : ll) 
                {
                    for (auto &right : rr) 
                    {
                        tmp.insert(left + right);
                    }
                }
                stk[n - 2] = move(tmp);
            }

            stk.pop_back();
            opt.pop_back();
        };

        string tmp;
        int n = expression.size();
        for(int i = 0; i < n; ++i)
        {
            char c = expression[i];
            if(isalpha(c))
            {
                if(i && expression[i - 1] == '}')
                    opt.push_back('*');
                tmp.push_back(c);
            }
            else if(c == ',')
            {
                if(tmp != "")
                    stk.push_back({tmp});
                tmp = "";
                while (!opt.empty() && opt.back() == '*') {
                    compute();
                }
                opt.push_back('+');
            }
            else if(c == '{')
            {
                if(tmp != "")
                    stk.push_back({tmp});
                tmp = "";
                if(i && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                    opt.push_back('*');
                opt.push_back('{');
            }
            else if(c == '}')
            {
                if(tmp != "")
                    stk.push_back({tmp});
                tmp = "";

                while(!opt.empty() && opt.back() != '{')
                {
                    compute();
                }
                opt.pop_back();
            }
            else
            {
                if(tmp != "")
                    stk.push_back({tmp});
            }
        }

        while(!opt.empty())
        {
            compute();
        }


        return {stk.back().begin(), stk.back().end()};
    }
};