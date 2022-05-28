class Solution {
private:
    vector<string> mapping;
    vector<string> ret;
    vector<int> index_len;
public:
    vector<string> letterCombinations(string digits) {


        if(digits == "")
            return ret;

        init_mapping();

        string temp;
        dfs_ret(digits, 0, temp);

        return ret;

    }

    void dfs_ret(string digits, int depth, string temp)
    {
        if(digits.size() == depth){
            ret.push_back(temp);
            return;
        }

        //cout<<"depth = "<<depth<<endl;
        int mapping_index = digits[depth] - '0';
        //<<digits[depth]<<' '<<mapping_index<<endl;

        int index_length = mapping[mapping_index].size();
        //cout<<index_length<<endl;

        for (int i = 0; i < index_length; ++i)
        {
            temp.push_back(mapping[mapping_index][i]);
        
            //cout<<temp<<endl;
            dfs_ret(digits, depth + 1, temp);
            temp.pop_back();
        }
    }


    void init_mapping()
    {
        mapping = {"000",
                    "111",
                    "abc",
                    "def",
                    "ghi",
                    "jkl",
                    "mno",
                    "pqrs",
                    "tuv",
                    "wxyz"};

    }
};