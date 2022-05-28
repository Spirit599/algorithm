class Solution {
public:
    string getHint(string secret, string guess) {

        string ans;
        int secret_size = secret.size();

        int i = 0;
        int bulls = 0;
        unordered_map<char, int> um;

        while(i < secret_size)
        {
            if(secret[i] == guess[i])
            {
                ++bulls;
            }
            else
            {
                if(um.count(secret[i]) != 0)
                {
                    ++um[secret[i]];
                }
                else
                {
                    um[secret[i]] = 1;
                }
            }
            ++i;
        }

        int cows = 0;
        i = 0;
        while(i < secret_size)
        {
            if(secret[i] != guess[i])
            {
                if(um.count(guess[i]))
                {
                    if(um[guess[i]] == 1)
                        um.erase(guess[i]);
                    else
                        --um[guess[i]];
                    ++cows;
                }
            }
            ++i;
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};