#pragma once

#include "gl_core.h"

#include <set>
#include <queue>
#include <functional>

namespace planet_engine
{
	class free_list
	{
	private:
		std::priority_queue<GLuint, std::vector<GLuint>, std::greater<GLuint>> _free_list;
		std::set<GLuint> _used;

		GLuint _next;

	public:
		free_list() :
			_next(0)
		{

		}

		GLuint alloc()
		{
			GLuint result;
			if (_free_list.empty())
			{
				result = _next++;
			}
			else
			{
				result = _free_list.top();
				_free_list.pop();
			}
			_used.insert(result);
			return result;
		}
		void dealloc(GLuint idx)
		{
			_used.erase(idx);
			_free_list.push(idx);
		}

		GLuint next_index() const
		{
			return _next;
		}
		GLuint current_max() const
		{
			return *std::max_element(_used.begin(), _used.end());
		}
	};
}
