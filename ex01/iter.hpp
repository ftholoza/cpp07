/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:30 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 15:17:14 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>

void	iter(T *array, size_t size, void (*function)(const T&))
{
	int	i = 0;

	if (array == NULL || function == NULL)
	{
		std::cout << "\033[1;31mError: null param\033[0m" << std::endl;
		return ;
	}
	while (i < size)
	{
		function(array[i]);
		i++;
	}
	return ;	
}

template<typename T>

void	iter(T *array, size_t size, void (*function)(T&))
{
	int	i = 0;

	if (array == NULL || function == NULL)
	{
		std::cout << "\033[1;31mError: null param\033[0m" << std::endl;
		return ;
	}
	while (i < size)
	{
		function(array[i]);
		i++;
	}
	return ;	
}

# endif