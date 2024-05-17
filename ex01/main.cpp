/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:08:43 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/17 16:59:15 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	print(int	n)
{
	n += 10;
	std::cout << n << std::endl;
}

void	printc(const char c)
{
	std::cout << c << std::endl;
}

int	main( void )
{
	int	list[4] = {1, 2, 3, 4};
	std::string	str = "hello world";
	char	*array = (char *) str.c_str();

	std::cout << list << std::endl;
	std::cout << &array << std::endl;
	iter(list, 4, print);
	std::cout << std::endl;
	iter(array, str.size(), printc);
}