/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:30 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/28 21:01:35 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>

void	iter(T *array, size_t size, void (*function)(const T &))
{
	int	i;

	i = 0;
	while (i < size)
	{
		function(array[i]);
		i++;
	}
	return ;	
}

template<typename T>

void	iter(T *array, size_t size, void (*function)(T &))
{
	int	i;

	i = 0;
	while (i < size)
	{
		function(array[i]);
		i++;
	}
	return ;	
}

# endif