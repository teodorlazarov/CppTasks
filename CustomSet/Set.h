#pragma once

#include <vector>
#include <algorithm>
#include <cassert>

template <typename T>
class Set
{
public:
	//Insert the element if the vector is empty, if not check if the element exists and if it doesn't then place in accending order 
	void insert(T t)	
	{
		if (_data.empty()) //Checks for empty vector and places the elements if so
		{
			_data.push_back(t);
			return;
		}

		for (int i = 0; i < _data.size(); i++) //If the element exists, the insertion is stopped
		{
			if (_data.at(i) == t)
			{
				return;
			}
		}

		for (int i = 0; i < _data.size(); i++) //Compare the element with the other elements in the vector and insert it at the right place, avoiding later sorting
		{
			if (_data.at(i) > t)
			{
				_data.insert(_data.begin()+i, t);
				return;
			}
		}

		_data.push_back(t);
		return;
	}

	//Removes the element if exists
	void remove(T t)
	{
		if (_data.empty())
		{
			return;
		}

		for (int i = 0; i < _data.size(); i++)
		{
			if (_data.at(i) == t) //Searches the vector for the element
			{
				_data.erase(_data.begin() + i);
				return;
			}
		}
		return;
	}

	class iterator
	{
	public:
		iterator(T* ptr) : ptr_(ptr) {} //Constructs an iterator and points to the memory assigned

		iterator operator++() //Post-increment
		{
			iterator i = *this;
			ptr_++;
			return i;
		}
		iterator operator++(int junk) //Pre-increment
		{
			ptr_++;
			return *this;
		}
		T& operator*() //Dereferencing the pointer
		{
			return *ptr_;
		}
		T* operator->() //Dereferencing the pointer
		{
			return ptr_;
		}
		bool operator==(const iterator& rhs) //Comparing the iterators pointers for equality
		{
			return ptr_ == rhs.ptr_;
		}
		bool operator!=(const iterator& rhs) //Comparing the iterators pointers for non equality
		{
			return ptr_ != rhs.ptr_;
		}
	private:
		T* ptr_;
	};

	//Returns an iterator pointing at the beginning of the vector
	iterator begin()
	{

		return iterator(&_data[0]);
	}

	//Returns an iterator pointing at the end of the vector
	iterator end()
	{
		return iterator(&_data.back() + 1);
	}

private:
	std::vector<T> _data;
};

