namespace jiangxy
{
	class priority_queue
	{
	private:
		vector<int> pq_;
		void buildHeap()
		{
			int len = pq_.size();
			for(int i = len / 2; i >= 0; --i)
			{
				downModify(i);
			}
		}
		void downModify(int idx)
		{
			int len = pq_.size();
			while(idx * 2 + 1 < len)
			{
				int ll = idx * 2 + 1;
				int rr = idx * 2 + 2;
				int maxIdx = idx;

				if(pq_[ll] < pq_[maxIdx])
					maxIdx = ll;
				if(rr < len && pq_[rr] < pq_[maxIdx])
					maxIdx = rr;
				if(maxIdx != idx)
				{
					swap(pq_[idx], pq_[maxIdx]);
					idx = maxIdx;
				}
				else
					break;
			}
		}
		void upModify(int idx)
		{
			while(idx)
			{
				int fa = (idx - 1) / 2;
				if(pq_[fa] > pq_[idx])
				{
					swap(pq_[fa], pq_[idx]);
					idx = fa;
				}
				else
					break;
			}
		}
	public:
		priority_queue()
		{}
		priority_queue(vector<int>& arr)
			:	pq_(arr)
		{
			buildHeap();
		}
		int top() const
		{
			return pq_[0];
		}
		void pop()
		{
			int len = pq_.size();
			swap(pq_[0], pq_[len - 1]);
			pq_.pop_back();
			downModify(0);
		}
		void push(int val)
		{
			pq_.push_back(val);
			int len = pq_.size();
			upModify(len - 1);
		}
		bool empty() const
		{
			return pq_.empty();
		}
		void print() const
		{
			for(int num : pq_)
				printf("%d ",num);
			printf("\n");
		}
	};
}