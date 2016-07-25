#pragma once

#include <deque>

namespace planet_engine
{
	template<typename vTy, typename vContainer = std::deque<vTy>>
	class contig_vector
	{
	public:
		typedef vContainer container_type;
		typedef typename vContainer::value_type value_type;
		typedef typename vContainer::pointer pointer;
		typedef typename vContainer::reference reference;
		typedef typename vContainer::const_pointer const_pointer;
		typedef typename vContainer::const_reference const_reference;
		typedef typename vContainer::size_type size_type;

		typedef typename vContainer::iterator iterator;
		typedef typename vContainer::const_iterator const_iterator;

	private:
		vContainer _values;

	public:
		contig_vector() = default;
		contig_vector(size_type sz) :
			_values(sz)
		{

		}
		template<typename vIt>
		contig_vector(vIt start, vIt end) :
			_values(start, end)
		{

		}
		contig_vector(std::initializer_list<value_type> lst) :
			_values(lst)
		{

		}

		iterator begin()
		{
			return std::begin(_values);
		}
		const_iterator begin() const
		{
			return std::begin(_values);
		}
		const_iterator cbegin() const
		{
			return begin();
		}
		iterator end()
		{
			return std::end(_values);
		}
		const_iterator end() const
		{
			return std::end(_values);
		}
		const_iterator cend() const
		{
			return end();
		}

		reference operator[](size_type idx)
		{
			return _values[idx];
		}
		const_reference operator[](size_type idx) const
		{
			return _values[idx];
		}
		reference at(size_type idx)
		{
			return _values.at(idx);
		}
		const_reference at(size_type idx) const
		{
			return _values.at(idx);
		}

		auto rbegin()
		{
			return std::rbegin(_values);
		}
		auto rend()
		{
			return std::rend(_values);
		}
		auto crbegin() const
		{
			return std::crbegin(_values);
		}
		auto crend() const
		{
			return std::crend(_values);
		}

		bool empty() const
		{
			return _values.empty();
		}
		size_type size() const
		{
			return _values.size();
		}
		void clear()
		{
			_values.clear();
		}

		reference front()
		{
			return _values.front();
		}
		const_reference front() const
		{
			return _values.front();
		}
		reference back()
		{
			return _values.back();
		}
		const_reference back() const
		{
			return _values.back();
		}

		iterator insert(iterator it, const_reference v)
		{
			return _values.insert(it, v);
		}
		void erase(iterator it)
		{
			if (it == end())
				return;
			*it = std::move(_values.back());
			_values.pop_back();
		}

		void push_back(const_reference v)
		{
			_values.push_back(v);
		}
		void pop_back()
		{
			_values.pop_back();
		}
		template<typename... vArgs>
		void emplace_back(vArgs&&... args)
		{
			_values.emplace_back(args...);
		}
	};
}
