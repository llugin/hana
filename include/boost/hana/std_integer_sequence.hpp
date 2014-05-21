/*!
 * @file
 * Adapts `std::integer_sequence`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_STD_INTEGER_SEQUENCE_HPP
#define BOOST_HANA_STD_INTEGER_SEQUENCE_HPP

#include <boost/hana/comparable.hpp>
#include <boost/hana/core.hpp>
#include <boost/hana/detail/comparable_from_iterable.hpp>
#include <boost/hana/detail/foldable_from_iterable.hpp>
#include <boost/hana/foldable.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/iterable.hpp>

#include <utility>


namespace boost { namespace hana {
    template <typename T, T ...v>
    struct Iterable<std::integer_sequence<T, v...>> : defaults<Iterable> {
        template <T x, T ...xs>
        static constexpr auto head_impl(std::integer_sequence<T, x, xs...>)
        { return std::integral_constant<T, x>{}; }

        template <T x, T ...xs>
        static constexpr auto tail_impl(std::integer_sequence<T, x, xs...>)
        { return std::integer_sequence<T, xs...>{}; }

        static constexpr auto is_empty_impl(std::integer_sequence<T, v...>)
        { return bool_<sizeof...(v) == 0>; }
    };

    template <typename T, T ...v>
    struct Foldable<std::integer_sequence<T, v...>>
        : detail::foldable_from_iterable
    { };

    template <typename X, X ...xs, typename Y, Y ...ys>
    struct Comparable<std::integer_sequence<X, xs...>,
                      std::integer_sequence<Y, ys...>>
        : detail::comparable_from_iterable
    { };
}} // end namespace boost::hana

#endif // !BOOST_HANA_STD_INTEGER_SEQUENCE_HPP
