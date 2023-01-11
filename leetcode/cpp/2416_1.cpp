// 2416. 字符串的前缀分数和
// 字典树
// 前缀树

class Trie {
	class TrieNode {
	public:
		int cnt;
		TrieNode* next[26];
		TrieNode() {
			cnt = 0;
			memset(next, 0, sizeof(next));
		}
	};
public:
	TrieNode root;
	void  Insert(string word) {
		TrieNode* p = &root;
		int n = word.size();
		for(int i = 0; i < n; ++i) {
			int kid = word[i] - 'a';
			if(p->next[kid] == nullptr) {
				p->next[kid] = new TrieNode();
			}
			p = p->next[kid];
			++(p->cnt);
		}
	}

	int search(string word) {

		TrieNode* p = &root;
		int n = word.size();
		int ret = 0;
		for(int i = 0; i < n; ++i) {
			int kid = word[i] - 'a';

			p = p->next[kid];
			ret += p->cnt;
		}

		return ret;
	}
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        

    	Trie trie;
    	for(string& str : words) {
    		trie.Insert(str);
    	}

    	int n = words.size();
    	vector<int> ans(n);
    	for(int i = 0; i < n; ++i) {
    		ans[i] = trie.search(words[i]);
    	}


        return ans;
    }
};