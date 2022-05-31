#ifndef ____LIST__
#define ____LIST__

namespace ___list
{
	template<typename _Ty>
	class list;

	template<typename _Ty>
	class list_it;

	template<typename _Ty>
	class list_node
	{
		friend class list<_Ty>;
		friend class list_it<_Ty>;
	public:
		list_node() :
		_data(_Ty()),
		_prev(nullptr),
		_next(nullptr)
		{}
		list_node(_Ty data, list_node* prev = nullptr, list_node* next = nullptr) :
		_data(data),
		_prev(prev),
		_next(next)
		{}
	private:
		_Ty _data;
		list_node* _prev;
		list_node* _next;
	};

	template<typename _Ty>
	class list_it
	{
		typedef list_it<_Ty> __it;
	public:
		list_it(list_node<_Ty>* ptr = nullptr) :
		__ptr(ptr)
		{}
	
		__it& operator++() //++obj
		{
			__ptr = __ptr->_next;
			return *this;
		}

		__it& operator--() //--obj
		{
			__ptr = __ptr->_prev;
			return *this;
		}

		_Ty& operator*() const
		{
			return __ptr->_data;
		}

		_Ty* operator->() const
		{
			return &(operator*());
		}

		bool operator==(const __it &it) const
		{
			return it.__ptr == __ptr;
		}

		bool operator!=(const __it &it) const
		{
			return it.__ptr != __ptr;
		}

		list_node<_Ty>* _ptr()
		{
			return __ptr;
		}

	private:
		list_node<_Ty>* __ptr;
	};


	template<typename _Ty>
	class list
	{
	public:
		typedef list_node<_Ty>* __ptr;
		typedef list_it<_Ty> __it;
		typedef unsigned int __unint;

		list() :
		_size(0)
		{
			create_head();
		}

		list(__unint n, const _Ty &data = _Ty()) :
		_size(0)
		{
			create_head();
			insert(begin(), n, data);
		}

		~list()
		{
			clear();
			delete_head();
		}
		//---------------------------------------------//
		void push_back(const _Ty &x)
		{
			insert(end(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const _Ty &x)
		{
			insert(begin(), x);
		}

		void pop_front(const _Ty &x)
		{
			erase(begin());
		}

		_Ty& front()
		{
			return *begin();
		}

		const _Ty& front() const
		{
			return *begin();
		}

		_Ty& back()
		{
			return *--end();
		}

		const _Ty& back() const
		{
			return *--end();
		}

		//---------------------------------------------//
		__it begin()
		{
			return __it(__head->_next);
		}

		__it end()
		{
			return __it(__head);
		}

		void clear()
		{
			erase(begin(), end());
		}

		__unint size() const
		{
			return _size;
		}

		bool empty() const
		{
			return _size == 0;
		}


		//---------------------------------------------//
		//it之前插入x//
		__it insert(__it it, const _Ty &x)
		{
			__ptr ptr = it._ptr();
			__ptr add = new list_node<_Ty>(x);

			add->_next = ptr;
			add->_prev = ptr->_prev;
			add->_prev->_next = add;
			add->_next->_prev = add;
			++_size;

			return __it(add);
		}

		void insert(__it it, __unint n, const _Ty &x)
		{
			while(n--)
				insert(it, x);
		}

		__it erase(__it it)
		{
			__ptr ptr = it._ptr();
			__ptr ret = ptr->_next;


			ptr->_next->_prev = ptr->_prev;
			ptr->_prev->_next = ptr->_next;
			--_size;

			return __it(ret);
		}

		__it erase(__it first, __it last)
		{
			while(first != last)
			{
				first = erase(first);
			}

			return first;
		}

	private:
		void create_head()
		{
			__head = new list_node<_Ty>;
			__head->_next = __head;
			__head->_prev = __head;
		}
		void delete_head()
		{
			delete __head;
		}

		__ptr __head;
		__unint _size;
	};
}

#endif