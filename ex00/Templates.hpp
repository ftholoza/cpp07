/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:25:57 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 14:35:13 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

# include <iostream>
# include <string>
# include <iomanip>

template<typename T>

void	swap(T &first,T &second)
{
	T	temp;

	temp = first;
	first = second;
	second = temp;
}

template<typename T>

T	min(const T &first, const T &second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

template<typename T>

T	max(T &first, T &second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

#endif