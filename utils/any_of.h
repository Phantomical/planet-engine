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
				typedef utuple<Ts...> inner_type;
				typedef T elem_type;

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
				typedef typename getter<idx - 1, typename utuple<Ts...>::inner_type>::ret_type ret_type;

				static ret_type& get(utuple<Ts...>& t)
				{
					static_assert(idx < sizeof...(Ts), "utuple index out of range.");

					return getter<idx - 1, decltype(t.inner)>::get(t.inner);
				}
				static const ret_type& get_cst(const utuple<Ts...>& t)
				{
					static_assert(idx < sizeof...(Ts), "utuple index out of range.");

					return getter<idx - 1, typename utuple<Ts...>::inner_type>::get_cst(t.inner);
				}
			};
			template<typename... Ts>
			struct getter<0, utuple<Ts...>>
			{
				static_assert(sizeof...(Ts) != 0, "Index out of bounds");
				typedef typename utuple<Ts...>::elem_type ret_type;

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

			template<size_t, typename T>
			struct type_at;
			template<size_t idx, template<typename...> typename C, typename... Ts>
			struct type_at<idx, C<Ts...>>
			{
				typedef typename std::tuple_element<idx, std::tuple<Ts...>>::type type;
			};

		}

		template<size_t idx, typename T>
		using type_at = typename detail::type_at<idx, T>::type;

		template<typename... Ts>
		struct any_of
		{
		private:
			typedef detail::utuple<Ts...> tuple_type;

			size_t active_element;
			tuple_type values;

			template<typename T>
			static bool util_function(T&) { return false; }

			template<typename T>
			void delete_elem(T& v)
			{
				if (index_of<T>::value == active_element)
					v.~T();
			}
			template<typename T>
			void copy_elem(const T& v, any_of* dest) const
			{
				if (index_of<T>::value == active_element)
					new (&dest->get<T>()) T(v);
			}

			template<size_t... idxs>
			void delete_elems(std::index_sequence<idxs...>)
			{
				auto l = { (delete_elem(get<idxs>()), 0)... };
			}
			template<size_t... idxs>
			void copy_elems(any_of* dest, std::index_sequence<idxs...>) const
			{
				auto l = { (copy_elem(get<idxs>(), dest), 0)... };
			}

		public:
			template<size_t idx>
			using type_at = typename detail::type_at<idx, any_of<Ts...>>::type;
			template<typename T>
			using index_of = typename detail::index_of<T, std::tuple<Ts...>>;

			template<typename T>
			any_of(const T& v) :
				active_element(detail::index_of<T, std::tuple<Ts...>>::value)
			{
				new (&get<T>()) T(v);
			}
			any_of(const any_of& o) :
				active_element(o.active_element)
			{
				o.copy_elems(this, std::index_sequence_for<Ts...>());
			}
			~any_of()
			{
				delete_elems(std::index_sequence_for<Ts...>());
			}

			any_of& operator=(const any_of& o)
			{
				delete_elems(std::index_sequence<sizeof...(Ts)>());

				active_element = v.active_element;

				o.copy_elems(this, std::index_sequence<sizeof...(Ts)>());

				return *this;
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

			template<size_t idx>
			type_at<idx>& get()
			{
				static_assert(idx < sizeof...(Ts), "any_of index out of bounds.");
				return get<type_at<idx>>();
			}
			template<size_t idx>
			const type_at<idx>& get() const
			{
				static_assert(idx < sizeof...(Ts), "any_of index out of bounds.");
				return get<type_at<idx>>();
			}

			size_t active_index() const
			{
				return active_element;
			}

			template<typename T>
			bool is() const
			{
				return index_of<T>::value == active_element;
			}
		};

	}
}
