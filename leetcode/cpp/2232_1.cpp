class Solution {
public:
    string minimizeResult(string expression) {
       
        int left = 0;
        int right = 0;
        int mid = 0;
        int minn = 0x3f3f3f3f;
    
        for(int i = 0; i < expression.size(); ++i)
        {
            if(expression[i] == '+') 
            {
                mid = i;
            }
        }
    
        for(int i = 0; i <= mid - 1; ++i)
        {
            for(int j = mid + 2; j <= expression.size(); ++j)
            {
                int k = 0;
    
                int p1 = 0;
                while(k != i)
                {
                    p1 = 10 * p1 + expression[k] - '0';
                    ++k;
                }
    
                int p2 = 0;
                while(k != mid)
                {
                    p2 = 10 * p2 + expression[k] - '0';
                    ++k;
                }

                ++k;

                int p3 = 0;
                while(k != j)
                {
                    p3 = 10 * p3 + expression[k] - '0';
                    ++k;
                }
    
                int p4 = 0;
                while(k != expression.size())
                {
                    p4 = 10 * p4 + expression[k] - '0';
                    ++k;
                }

                if(p1 == 0)
                    p1 = 1;
                if(p4 == 0)
                    p4 = 1;

                int cur = p1 * (p2 + p3) * p4;
                if(cur < minn)
                {
                    minn = cur;
                    left = i;
                    right = j;
                }
                //printf("cur = %d\n", cur);
    
                //printf("%d %d %d %d\n",p1,p2,p3,p4);
            }
        }
    
        string ans(expression);
        
        ans.insert(left, "(");
        ans.insert(right + 1, ")");


        return ans;
    }
};