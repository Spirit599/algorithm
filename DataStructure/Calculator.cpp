class Solution {
public:
    int optPrior[256];
    void makePrior() {
        optPrior['+'] = 1;
        optPrior['-'] = 1;
        optPrior['*'] = 2;
        optPrior['/'] = 2;

    }
    void replaceAll(std::string& str, const std::string& from, const std::string& to)
    {
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos){
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
    }
    bool Opt1HigherThanOpt2(char opt1, char opt2) {
        return optPrior[opt1] > optPrior[opt2];
    }
    int calculate(string s) {

        replaceAll(s, " ", "");

        makePrior();

        vector<char> optStk;
        vector<int> numStk;

        auto eval = [&]() -> void {

            int optSize = optStk.size();
            int numSize = numStk.size();
            assert(optSize > 0);
            assert(numSize > 1);
            if(optStk[optSize - 1] == '+')
                numStk[numSize - 2] += numStk[numSize - 1];
            else if(optStk[optSize - 1] == '-')
                numStk[numSize - 2] -= numStk[numSize - 1];
            else if(optStk[optSize - 1] == '*')
                numStk[numSize - 2] *= numStk[numSize - 1];
            else if(optStk[optSize - 1] == '/')
                numStk[numSize - 2] /= numStk[numSize - 1];
            numStk.pop_back();
            optStk.pop_back();
        };

        int n = s.size();
        int i = 0;

        while(i < n)
        {
            if(isdigit(s[i]))
            {
                int num = 0;
                while(i < n && isdigit(s[i]))
                {
                    num = 10 * num - '0' + s[i];
                    ++i;
                }
                --i;
                numStk.push_back(num);
            }
            else if(s[i] == ' ')
            {
                ;
            }
            else if(s[i] == '(')
            {
                optStk.push_back('(');
            }
            else if(s[i] == ')')
            {
                while(!optStk.empty() && optStk.back() != '(')
                    eval();
                optStk.pop_back();
            }
            else
            {
                if(i == 0 || s[i - 1] == '(')
                    numStk.push_back(0);
                char opt = s[i];
                while(!optStk.empty() && optStk.back() != '(' && !Opt1HigherThanOpt2(opt, optStk.back()))
                    eval();
                optStk.push_back(opt);
            }
            ++i;
        }

        while(!optStk.empty())
            eval();

        return numStk.back();
    }
};