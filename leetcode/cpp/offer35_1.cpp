// low中low

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return NULL;

        Node* phead = head;
        Node* dummy = (Node*)malloc(sizeof(Node));
        //Node* copy_head = NULL;
        Node* pcopy_head = dummy;
        int length = 0;

        while(phead)
        {
            Node* tmp = (Node*)malloc(sizeof(Node));
            tmp->val = phead->val;
            tmp->next = NULL;
            pcopy_head->next = tmp;
            pcopy_head = tmp;
            ++length;
            phead = phead->next;
        }

        int random_index[length];
        phead = head;
        int i = 0;
        while(phead)
        {
            int index = 0;
            Node* tmp = head;
            //cout<<phead->random->val<<endl;
            while(tmp != phead->random && tmp != NULL)
            {
                cout<<tmp->val<<" ";
                tmp = tmp->next;
                ++index;
            }
            if(tmp)
                random_index[i] = index;
            else
                random_index[i] = -1;
            cout<<endl;
            cout<<random_index[i]<<" ";
            phead = phead->next;
            ++i;
        }

        pcopy_head = dummy->next;
        i = 0;
        cout<<endl;
        while(pcopy_head)
        {
            cout<<pcopy_head->val<<" ";
            Node* tmp = dummy->next;
            if(random_index[i] == -1)
            {
                pcopy_head->random = NULL;
            }
            else
            {
                while(random_index[i]--)
                {
                    tmp = tmp->next;
                }
                pcopy_head->random = tmp;
            }
            pcopy_head = pcopy_head->next;
            ++i;
        }

        return dummy->next;
    }
};