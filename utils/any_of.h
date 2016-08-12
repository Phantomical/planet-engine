#pragma once

#include <tuple>

namespace planet_engine
{
	namespace util
	{

		namespace detail
		{
			template<typename... Ts>
			union utuple;

			template<typename T, typename... Ts>
			union utuple<T, Ts...>
			{
				utuple<Ts...> inner;
				T elem;

				utuple() { }
				~utuple() { };
			};

			template<>
			union utuple<>
			{
				utuple() { }
				~utuple() { }
			};

			template<size_t, typename>
			struct getter;

			template<size_t idx, typename... Ts>
			struct getter<idx, utuple<Ts...>>
			{
				static auto& get(utuple<Ts...>& t)
				{
					static_assert(idx < sizeof...(Ts), "utuple index out of range.");

					return getter<idx - 1, decltype(t.inner)>::get(t.inner);
				}
				static const auto& get_cst(const utuple<Ts...>& t)
				{
					static_assert(idx < sizeof...(Ts), "utuple index out of range.");

					return  getter<idx - 1, decltype(t.inner)>::get(t.inner);
				}
			};
			template<typename... Ts>
			struct getter<0, utuple<Ts...>>
			{
				static_assert(sizeof...(Ts) != 0, "Index out of bounds");
				typedef typename std::tuple_element<0, std::tuple<Ts...>>::type ret_type;

				static ret_type& get(utuple<Ts...>& t)
				{
					static_assert(sizeof...(Ts) != 0, "utuple index out of range.");

					return t.elem;
				}
				static const ret_type& get_cst(const utuple<Ts...>& t)
				{
					static_assert(sizeof...(Ts) != 0, "utuple index out of range.");

					return t.elem;
				}
			};

			template<typename T1, typename T2, bool val>
			struct _select
			{
				typedef T1 type;
			};

			template<typename T1, typename T2>
			struct _select<T1, T2, false>
			{
				typedef T2 type;
			};

			template<typename T1, typename T2, bool val>
			using select = typename _select<T1, T2, val>::type;

			template <class T, class Tuple>
			struct Index;

			template <class T, class... Types>
			struct Index<T, std::tuple<T, Types...>> {
				static const std::size_t value = 0;
			};

			template <class T, class U, class... Types>
			struct Index<T, std::tuple<U, Types...>> {
				static const std::size_t value = 1 + Index<T, std::tuple<Types...>>::value;
			};

			template<typename T, typename T2>
			using index_of = Index<T, T2>;
		}

		template<typename... Ts>
		struct any_of
		{
		private:
			typedef detail::utuple<Ts...> tuple_type;

			size_t active_element;
			tuple_type values;

			template<size_t idx>
			void delete_elem()
			{
				typedef typename std::tuple_element<Ts...>::type type;

				if (idx == active_element)
					detail::getter<idx>::get(values).~type();
				else
					delete_elem<idx - 1>();
			}

			template<size_t... idxs>
			void delete_elems(std::index_sequence<idxs...>)
			{
				delete_elem<idxs>()...;
			}

		public:
			template<typename T>
			any_of(const T& v) :
				active_element(detail::index_of<T, std::tuple<Ts...>>::value)
			{
				static constexpr size_t index = detail::index_of<T, std::tuple<Ts...>>::value;
				new (&detail::getter<index, tuple_type>::get(values)) T(v);
			}
			any_of(const any_of& v)
			{

			}
			~any_of()
			{
				delete_elems(std::index_sequence_for<Ts...>());
			}

			template<typename T>
			T& get()
			{
				static constexpr size_t index = detail::index_of<T, std::tuple<Ts...>>::value;
				return detail::getter<index, tuple_type>::get(values);
			}
			template<typename T>
			const T& get() const
			{
				static constexpr size_t index = detail::index_of<T, std::tuple<Ts...>>::value;
				return detail::getter<index, tuple_type>::get_cst(values);
			}

			size_t active_index() const
			{
				return active_element;
			}
		};
	}
}
