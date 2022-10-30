/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_map.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:53:05 by wszurkow          #+#    #+#             */
/*   Updated: 2022/10/30 13:53:32 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
			while (first1!=last1)
			{
				if (first2 == last2 || first2->second < first1->second) return false;
				else if (first1->second < first2->second) return true;
				++first1; ++first2;
			}
			return (first2 != last2);
		}

	template <class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
			while (first1!=last1) {
				if (comp(first1->second, first2->second)) return true;
				if (comp(first2->second, first1->second)) return false;
				++first1; ++first2;
			}
			return (first2 != last2);
		}
}
