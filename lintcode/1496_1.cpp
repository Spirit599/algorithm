// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution :public SolBase {
public:
    int rand10() {
         
         while(1)
         {
            int k = (rand7() - 1) * 7 + rand7();
            if(k <= 40)
                return k % 10 + 1;
         }

         return -1;
    }
};