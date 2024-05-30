/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:44:51 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/30 16:18:44 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "time.h"
#include "cstdlib"

/*int	main(void)
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
}*/

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    Array<int> empty(0);
    Array<int> empty2(empty);
    Array<int> empty3 = empty2;
    std::cout << empty2.size() << std::endl;
    std::cout << empty.size() << std::endl;
    std::cout << empty3.size() << std::endl;
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    Array<int> tmp = numbers;
    Array<int> test(tmp);
    for (int i = 0; i < MAX_VAL; i++)
    {
        if ((mirror[i] != tmp[i]) || (test[i] != mirror[i]) || (numbers[i] != mirror[i]))
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete [] mirror;
            return 1;
        }
    }
    std::cout << "GOOD" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

