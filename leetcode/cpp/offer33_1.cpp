//分治


class Solution {
public:

    bool judge(int left, int right, vector<int>& postorder)
    {
        //cout<<left<<" "<<right<<endl;
        if(left >= right)
            return true;

        int i = right;
        for (; i >= left; --i)
        {
            if(postorder[i] < postorder[right])
            {
                break;
            }
        }
        int mid = i;

        for (; i >= left; --i)
        {
            if(postorder[i] > postorder[right])
                return false;
        }

        return judge(left, mid, postorder) && judge(mid + 1, right - 1, postorder);
    }

    bool verifyPostorder(vector<int>& postorder) {

        int right = postorder.size() - 1;
        return judge(0, right, postorder);
    }
};