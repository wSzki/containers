/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:43:58 by wszurkow          #+#    #+#             */
/*   Updated: 2022/09/16 16:44:05 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {
	template<typename _Iterator>
	class reverse_iterator {
		public:
			typedef					_Iterator										iterator_type;
			typedef	typename		iterator_traits<_Iterator>::iterator_category	category;
			typedef	typename		iterator_traits<_Iterator>::value_type			value_type;
			typedef	typename		iterator_traits<_Iterator>::difference_type		difference_type;
			typedef	typename		iterator_traits<_Iterator>::pointer				pointer;
			typedef	typename 		iterator_traits<_Iterator>::reference			reference;

			/****************/
			/* CONSTRUCTEUR */
			/****************/
			//reverse_iterator() : _current() {}

			//explicit reverse_iterator(iterator_type it) : _current(it) {}

			//template<typename _It>
			//reverse_iterator(const reverse_iterator<_It> &rev_it) : _current(rev_it.base()) {}

			//template<typename _It>
			//reverse_iterator &operator=(reverse_iterator const &rhs) {
				//if (this != &rhs) {
					//_current = rhs._current;
				//}


			//virtual ~reverse_iterator() {};

			/****************/
			/***** BASE *****/
			/****************/

			iterator_type base() const {
				return (this->_current);
			}

			/****************/
			/**** OPERATOR **/
			/****************/

			reference operator*() const {
				_Iterator newref(this->_current);
				newref--;
				return *(newref);
			};

			reverse_iterator operator+ (difference_type n) const {
				return(reverse_iterator<_Iterator>(_current - n));
			}

			reverse_iterator& operator++() {
				--_current;
				return (*this);
			}
			reverse_iterator  operator++(int) {
				reverse_iterator<_Iterator>	temp = *this;
				_current--;
				return (temp);
			}

			reverse_iterator& operator+= (difference_type n) {
				_current -= n;
				return (*this);
			}

			reverse_iterator operator- (difference_type n) const {
				return (reverse_iterator<_Iterator>(_current + n));
			}

			reverse_iterator& operator--() {
				++_current;
				return (*this);
			}
			reverse_iterator  operator--(int) {
				reverse_iterator<_Iterator> temp = *this;
				_current++;
				return (temp);
			}

			reverse_iterator& operator-= (difference_type n) {
				_current += n;
				return (*this);
			}

			pointer operator->() const {
				return &(operator*());
			}

			reference operator[] (difference_type n) const {
				return (_current[-n-1]);
			}

			template <class _It>
			friend bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_It> &rhs);
			template <class _It>
			friend bool operator!= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator<  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator<= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator>  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend bool operator>= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It>
			friend reverse_iterator<_It> operator+ (typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_It>& rev_it);
			template <class _It, class _Iter>
			friend reverse_iterator<_It> operator+(typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_Iter> &rev_it);
			template <class _It>
			friend typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs);
			template <class _It, typename _Iter>
			friend typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs);

			difference_type substract(const reverse_iterator<_Iterator> rhs) const {
				return (rhs.base() - this->_current);
			}

			protected:
				_Iterator				_current;
	};

	/****************/
	/** OVERLOADS ***/
	/****************/

	template <class _It>
	bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_It> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class _It>
	bool operator!= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class _It>
	bool operator<  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
		return (rhs.base() < lhs.base());
	}

	template <class _It>
	bool operator<= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
		return (rhs.base() <= lhs.base());
	}

	template <class _It>
	bool operator>  (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
		return (rhs.base() > lhs.base());
	}

	template <class _It>
	bool operator>= (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
		return (rhs.base() >= lhs.base());
	}

	template <class _It, class _Iter>
	bool operator==(const reverse_iterator<_It> &lhs, const reverse_iterator<_Iter> &rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class _It, class _Iter>
	bool operator!= (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class _It, class _Iter>
	bool operator<  (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() < lhs.base());
	}

	template <class _It, class _Iter>
	bool operator<= (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() <= lhs.base());
	}

	template <class _It, class _Iter>
	bool operator>  (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() > lhs.base());
	}

	template <class _It, class _Iter>
	bool operator>= (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (rhs.base() >= lhs.base());
	}

	template <class _It>
	reverse_iterator<_It> operator+ (typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_It>& rev_it) {
		return (rev_it + n);
	}

	template <class _It, class _Iter>
	reverse_iterator<_It> operator+(typename reverse_iterator<_It>::difference_type n, const reverse_iterator<_Iter>& rev_it) {
		return (rev_it + n);
	}

	template <class _It>
	typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_It>& rhs) {
		return (lhs.substract(rhs));
	}

	template <class _It, typename _Iter>
	typename reverse_iterator<_It>::difference_type operator- (const reverse_iterator<_It>& lhs, const reverse_iterator<_Iter>& rhs) {
		return (lhs.substract(rhs));
	}
}
#endif
