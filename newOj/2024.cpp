#include<iostream>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;

// 线段树
unordered_map<int, int> memo;
int* segMentTree = nullptr;
int* arr = nullptr;
int* maxIndex = nullptr;

void build(int treeIndex, int left, int right)
{
	if(left == right)
	{
		segMentTree[treeIndex] = maxIndex[left];
		return ;
	}
	else if(left > right)
		return ;

	int mid = (left + right) >> 1;
	int leftIndex = 2 * treeIndex + 1;
	int rightIndex = 2 * treeIndex + 2;
	build(leftIndex, left, mid);
	build(rightIndex, mid + 1, right);
	segMentTree[treeIndex] = max(segMentTree[leftIndex], segMentTree[rightIndex]);
	//printf("%d %d %d %d\n",treeIndex, segMentTree[treeIndex], segMentTree[leftIndex], segMentTree[rightIndex]);
}

int query(int treeIndex, int left, int right, int queryLeft, int queryRight)
{
    if(queryLeft <= left && right <= queryRight)
        return segMentTree[treeIndex];
    else if(queryLeft > right || queryRight < left)
        return -1;
    
    int ret = -1;
    int mid = (left + right) >> 1;
    int leftIndex = 2 * treeIndex + 1;
    int rightIndex = 2 * treeIndex + 2;

    ret = query(leftIndex, left, mid, queryLeft, queryRight);
    ret = max(ret, query(rightIndex, mid + 1, right, queryLeft, queryRight));

    return ret;
} 

int main(int argc, char const *argv[])
{
	
	int n, m, x;
	scanf("%d%d%d",&n,&m,&x);
	arr = (int*)malloc(sizeof(int) * n);
	maxIndex = (int*)malloc(sizeof(int) * n);
	memset(maxIndex, -1, sizeof(int) * n);
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
		memo[arr[i]] = i;
		auto it = memo.find(arr[i] ^ x);
		if(it != memo.end())
			maxIndex[i] = it->second;

	}

	segMentTree = (int*)malloc(sizeof(int) * 4 * n);
	memset(segMentTree, -1, sizeof(int) * 4 * n);

	build(0, 0, n - 1);

	int start, end;
	while(m--)
	{
		scanf("%d%d",&start,&end);
		--start;
		--end;
		int ret = query(0, 0, n - 1, start, end);
		//printf("ret = %d\n",ret);
		if(ret >= start)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}