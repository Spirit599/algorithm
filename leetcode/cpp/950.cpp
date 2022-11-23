class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        sort(deck.begin(), deck.end(), greater<int>());
        deque<int> deq;
        deq.emplace_front(deck[0]);
        int n = deck.size();

        for(int i = 1; i < n; ++i)
        {
            int last = deq.back();
            deq.pop_back();
            deq.emplace_front(last);
            deq.emplace_front(deck[i]);
        }

        vector<int> ans;
        for(int i = 0; i < n; ++i)
        {
            ans.emplace_back(deq.front());
            deq.pop_front();
        }
        return ans;

    }
};