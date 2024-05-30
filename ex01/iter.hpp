/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:30 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/30 16:04:49 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T, typename F>

void	iter(T *array, size_t size, F f)
{
	if (array == NULL || f == NULL)
	{
		std::cout << "\033[1;31mError: null param\033[0m" << std::endl;
		return ;
	}
	for (size_t i = 0; i < size; i++)
		f (array[i]);
	return ;	
}

# endif