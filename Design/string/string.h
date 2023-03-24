#ifndef __JIANGXY__STRING__
#define __JIANGXY__STRING__

#include<cstring>
#include<iostream>
#include <cassert>

// using namespace 

namespace jiangxy
{
	class string
	{
	public:
		string()
		{
			std::cout<<"string()"<<std::endl;
		}
		string (const string& obj) : size_(obj.size())
		{
			std::cout<<"string (const string& obj)"<<std::endl;
			MallocAndCpyDataToPtr(size_ + 1, obj.ptr_);
		}
		string (const char* cstr)
		{
			std::cout<<"string (const char* cstr)"<<std::endl;
			if(cstr)
			{
				size_ = strlen(cstr);
				MallocAndCpyDataToPtr(size_ + 1, cstr);
			}
			else
			{
				size_ = 0;
				ptr_ = (char*)malloc(sizeof(char) * 1);
				ptr_[0] = '\0';
			}
		}
		~string()
		{
			std::cout<<"~string()"<<std::endl;
			assert(ptr_);
			free(ptr_);
		}
		size() const
		{
			return size_;
		}
		string& operator= (const string& rhs)
		{
			if(rhs.ptr_ == ptr_)
				return *this;
			free(ptr_);
			ptr_ = nullptr;
			size_ = rhs.size();
			MallocAndCpyDataToPtr(size_ + 1, rhs.ptr_);
			return *this;
		}
		string& operator+= (const string& rhs)
		{
			if(rhs.ptr_ != ptr_)
			{
				// free(ptr_);
				int allSize = size_ + rhs.size();
				char* tmp = (char*)malloc(sizeof(char) * (allSize + 1));
				std::cout<<allSize<<std::endl;
				memcpy(tmp, ptr_, size_);
				memcpy(tmp + size_, rhs.ptr_, rhs.size());
				tmp[allSize] = '\0';
				free(ptr_);
				ptr_ = tmp;
				size_ = allSize;
			}
			return *this;
		}
		char* c_str() const 
		{
			return ptr_;
		}
		
	private:
		void MallocAndCpyDataToPtr(int size, const char* from)
		{
			ptr_ = (char*)malloc(sizeof(char) * size);
			memcpy(ptr_, from, sizeof(char) * size);
			ptr_[size - 1] = '\0';
		}
		char* ptr_;
		int size_;
	};
}

using namespace jiangxy;


// string operator+

std::ostream& operator<< (std::ostream& os, const string& rhs)
{
	os << rhs.c_str();
	return os;
}

#endif