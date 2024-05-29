/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:30 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 02:44:54 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>

void	iter(T *array, size_t size, void (*function)(const T&))
{
	int	i = 0;

	if (array == NULL || function == NULL)
		return ;
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
		return ;	
	while (i < size)
	{
		function(array[i]);
		i++;
	}
	return ;	
}

# endif