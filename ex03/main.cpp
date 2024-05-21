/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:44:51 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/21 11:03:15 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

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
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
		std::cout << "nbrs: " << numbers[i] << " " ;
		std::cout << "mirror: " << mirror[i] << std::endl;
    }
    //SCOPE
    {
		//std::cout << "ok" << std::endl;
        Array<int> tmp = numbers;
		//std::cout << "ok" << std::endl;
        Array<int> test(tmp);
    }
	//std::cout << "here" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
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
    delete [] mirror;//
    return 0;
}