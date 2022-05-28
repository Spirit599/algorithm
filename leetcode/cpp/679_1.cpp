//24点


const int NUM_SIZE = 4;
const int SYMBOL_KIND = 4;


class Solution {
private:
    bool ans = false;
    double target = 24.0;
    double eps = 1e-6;
    double _cards[NUM_SIZE];
    double _cur_cards[NUM_SIZE];
    double _next_cards[NUM_SIZE];
    
    enum symbol
    {
        ADD,
        SUB,
        MULT,
        DIV,
    };

public:
    double calculate(double num1, double num2, int symbol)
    {
        if(symbol == ADD)
            return num1 + num2;
        else if(symbol == SUB)
            return num1 - num2;
        else if(symbol == MULT)
            return num1 * num2;
        else if(symbol == DIV)
            return num1 / num2;

        return -1;
    }

    bool check(double n1, double n2)
    {
        return fabs(n1 - n2) < eps;
    }

    void dfs(int depth)
    {
        // for(int i = 0; i < NUM_SIZE - depth; ++i)
        // {
        //     printf("%lf ", _cur_cards[i]);
        // }
        // printf("\n");

        if(ans == true)
            return ;

        if(depth == NUM_SIZE - 1)
        {
            if(check(_cur_cards[0], target))
                ans = true;
            return ;
        }
        
        for(int i = 0; i < NUM_SIZE - depth; ++i)
        {
            for(int j = 0; j < NUM_SIZE - depth; ++j)
            {

                int cnt = 0;
                for(int k = 0; k < NUM_SIZE - depth; ++k)
                {
                    if(k != i && k != j)
                    {
                        _next_cards[cnt++] = _cur_cards[k];
                    }
                }

                if(i != j)
                {
                    for(int symbol = 0; symbol < SYMBOL_KIND; ++symbol)
                    {    
                        double num = calculate(_cur_cards[i], _cur_cards[j], symbol);

                        //printf("num = %lf\n", num);

                        _next_cards[cnt++] = num;

                        double _tmp_cards[NUM_SIZE];
                        memcpy(_tmp_cards, _cur_cards, sizeof(_tmp_cards));
                        memcpy(_cur_cards, _next_cards, sizeof(_cur_cards));

                        dfs(depth + 1);

                        memcpy(_cur_cards, _tmp_cards, sizeof(_cur_cards));

                        --cnt;
                    }
                }
            }
        }


    }

    bool judgePoint24(vector<int>& cards) {

        for(int i = 0; i < cards.size(); ++i)
            _cards[i] = cards[i];

        memcpy(_cur_cards, _cards, sizeof(_cur_cards));
        memset(_next_cards, 0, sizeof(_next_cards));

        dfs(0);

        return ans;
    }
};