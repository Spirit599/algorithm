class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        sort(skill.begin(), skill.end());
        int n = skill.size();
        long long ans = 0;
        long long key = skill.back() + skill.front();

        int left = 0;
        int right = n - 1;
        while(left < right)
        {
            long long cur = skill[left] + skill[right];
            if(cur != key)
                return -1;
            ans += 1ll * skill[left] * skill[right];
            ++left;
            --right;
        }

        return ans;
    }
};