//wrong no pass

class Solution {
public:
    int strongPasswordChecker(string password) {

        int triple = 0;
        int password_len = password.size();

        for(int i = 0; i + 2 < password_len; )
        {
            if(password[i] == password[i + 1] &&
                password[i + 1] == password[i + 2])
            {
                ++triple;
                printf("%d ",i);
                i = i + 3;
                
            }
            else
            {
                ++i;
            }
        }
        printf("\n");

        int upper_c = 0;
        int lower_c = 0;
        int number = 0;
        for(char c : password)
        {
            if(c >= '0' && c <= '9')
            {
                ++number;
            }
            else if(c >= 'a' && c <= 'z')
            {
                ++lower_c;
            }
            else if(c >= 'A' && c <= 'Z')
            {
                ++upper_c;
            }
        }

        int lack_kind = 0;
        if(upper_c == 0)
            ++lack_kind;
        if(lower_c == 0)
            ++lack_kind;
        if(number == 0)
            ++lack_kind;

        int ans = 0;
        if(password_len < 6)
        {
            //替换
            int change = min(lack_kind, triple);
            printf("%d %d\n",lack_kind, triple);
            ans += change;
            lack_kind -= change;
            triple -= change;

            ans += max(6 - password_len, max(lack_kind, triple));
        }
        else if(password_len >= 6 && password_len <= 20)
        {
            int change = min(lack_kind, triple);
            printf("%d %d\n",lack_kind, triple);
            ans += change;
            lack_kind -=change;
            triple -= change;

            ans += max(lack_kind, triple);
        }
        else
        {
            int change = min(lack_kind, triple);
            printf("%d %d %d\n",password_len, lack_kind, triple);
            ans += change;
            lack_kind -=change;
            triple -= change;

            ans += (password_len - 20);
            ans += max(lack_kind, triple);
        }


        return ans;
    }
};