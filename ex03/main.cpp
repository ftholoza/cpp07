/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:44:51 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/17 20:19:17 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int>	a(5);
	a[0] = 1;
	Array<int> b(10);
	b[1] = 2;
	b[0] = 1;
	b[2] = 3;
	a = b;
	std::cout << "size function: " << b.size() << "," << a.size() << std::endl;
	std::cout << b[0] << b[1] << b[2] << std::endl;
	std::cout << a[0] << std::endl;
	try
	{
		std::cout << a[11];
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}