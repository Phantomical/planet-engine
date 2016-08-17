#pragma once

namespace planet_engine
{
	namespace util
	{
		namespace detail
		{
			template<size_t N, size_t val, size_t base>
			struct _log_n : _log_n<N + 1, (val + base - 1) / base, base>
			{

			};
			template<size_t N, size_t base>
			struct _log_n<N, 1, base>
			{
				static constexpr size_t value = N;
			};
		}

		template<size_t val, size_t base>
		using log = detail::_log_n<0, val, base>;
	}
}
