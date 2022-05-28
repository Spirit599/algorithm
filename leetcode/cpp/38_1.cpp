class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        int i = 1;

        while(i != n)
        {
            int str_len = ret.size();
            int j = 0;
            char prior_c = '*';
            int num = 0;
            string temp;
            while(j < str_len)
            {
                if(prior_c == ret[j])
                {
                    num++;
                }
                else
                {
                    if(j != 0) 
                    {
                        temp.push_back(num + '0');
                        temp.push_back(prior_c);
                    }
                    prior_c = ret[j];
                    num = 1;
                }
                j++;
            }
            temp.push_back(num + '0');
            temp.push_back(prior_c);
            ret = temp;
            //cout<<ret<<endl;
            i++;
        }

        return ret;

    }
};