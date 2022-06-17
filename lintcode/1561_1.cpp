//1561 · BST节点距离

class Solution {
public:
    /**
     * @param numbers: the given list
     * @param node1: the given node1
     * @param node2: the given node2
     * @return: the distance between two nodes
     */

    struct TreeNode {
        int val;
        int index;
        TreeNode* left;
        TreeNode* right;
    };
    int check(vector<int> &numbers, int node1, int node2, int& index1, int& index2) 
    {
        int n = numbers.size();
        for (int i = 0; i < n; ++i)
        {
            if(numbers[i] == node1)
                index1 = i;
            else if(numbers[i] == node2)
                index2 = i;
            else if(index1 != -1 && index2 != -1)
                break;
        }
        if(index1 == -1 || index2 == -1)
            return -1;
        return max(index1, index2);
    }

    int insert_node(TreeNode*& head, int val, int index)
    {
        if(head == nullptr)
        {
            TreeNode* h = (TreeNode*)malloc(sizeof(TreeNode));
            h->val = val;
            h->index = index;
            h->left = nullptr;
            h->right = nullptr;
            head = h;
            return -1;
        }
        else
        {
            TreeNode* pre = head;
            TreeNode* p = head;
            while(1)
            {
                //cout<<p->val<<endl;
                if(val < p->val)
                {
                    pre = p;
                    p = p->left;
                    if(p == nullptr)
                    {
                        TreeNode* h = (TreeNode*)malloc(sizeof(TreeNode));
                        h->val = val;
                        h->index = index;
                        h->left = nullptr;
                        h->right = nullptr;
                        pre->left = h;
                        break;
                    }

                }
                else
                {
                    pre = p;
                    p = p->right;
                    if(p == nullptr)
                    {
                        TreeNode* h = (TreeNode*)malloc(sizeof(TreeNode));
                        h->val = val;
                        h->index = index;
                        h->left = nullptr;
                        h->right = nullptr;
                        pre->right = h;
                        break;
                    }
                }
            }
            return pre->index;
        }
    }
    int bstDistance(vector<int> &numbers, int node1, int node2) {
        
        int index1 = -1;
        int index2 = -1;
        int n = check(numbers, node1, node2, index1, index2);
        if(n == -1)
            return -1;

        int father[n + 1];
        memset(father, 0, sizeof(father));

        TreeNode* head = nullptr;

        for(int i = 0; i <= n; ++i)
        {
            father[i] = insert_node(head, numbers[i], i);
            //cout<<father[i]<<" ";
        }

        int ans = 0;
        while(index1 != index2)
        {
            //cout<<index1<<" "<<index2<<endl;
            if(index1 < index2)
                index2 = father[index2];
            else
                index1 = father[index1];
            ++ans;
        }

        return ans;
    }
};