/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:02:51 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 19:13:07 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "iostream"

template<typename T>

class	Array
{
	private:
		T *array;
		size_t	lenght;
	public:
		Array();
		Array(Array &to_copy);
		Array(unsigned int size);
		~Array();

		Array<T> &operator=(Array<T> &to_copy);
		T	&operator[](const unsigned int pos) const;
		size_t	size(void) const;
		class OutOfBandsException : public std::exception
        {
            public:
                const char *what() const throw ();
        };
};

template<typename T>

Array<T>::Array()
{
	std::cout << "\033[1;32mDEFAULT ARRAY CONSTRUCTOR\033[0m" << std::endl;
	this->array = NULL;
	this->lenght = 0;
}

template<typename T>

Array<T>::Array(unsigned int size)
{
	std::cout << "\033[1;32mARRAY CONSTRUCTOR\033[0m" << std::endl;
	if (size == 0)
	{
		this->array = new T[0]();
		this->lenght = 0;
	}
	try
	{
		this->array = new T[size]();
		this->lenght = size;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << "\033[1;31mError: MALLOC\033[0m" << std::endl;
		this->array = NULL;
		this->lenght = 0;
	}
	return ;
}

template<typename T>

Array<T>::~Array()
{
	std::cout << "\033[1;31mARRAY DESTRUCTOR\033[0m" << std::endl;
	if (this->array != NULL)
		delete	[] this->array;
	return ;
}

template<typename T>

Array<T>::Array(Array &to_copy)
{
	std::cout << "\033[1;32mARRAY COPY CONSTRUCTOR\033[0m" << std::endl;
	if (to_copy.lenght != 0)
	{
		try
		{
			this->array = new	T[to_copy.lenght]();
			for (size_t i = 0; i < to_copy.lenght; i++)
				this->array[i] = to_copy.array[i];
			this->lenght = to_copy.lenght;	
			return ;
		}
		catch (std::bad_alloc &e)
		{
			std::cerr << "\033[1;31mError: MALLOC\033[0m" << std::endl;
			this->lenght = 0;
			this->array = NULL;
			return ;
		}
	}
	this->lenght = 0;
	this->array = new T[0]();
	return ;
}

template<typename T>

Array<T>& Array<T>::operator=(Array<T> &to_copy)
{
	if (this->array != NULL)
		delete [] this->array;
	if (to_copy.lenght != 0)
	{
		try
		{
			this->array = new T[to_copy.lenght]();
			for (size_t i = 0; i < to_copy.lenght; i++)
				this->array[i] = to_copy.array[i];
			this->lenght = to_copy.lenght;
			return (*this);
		}
		catch (std::bad_alloc &e)
		{
			std::cerr << "\033[1;31mError: MALLOC\033[0m" << std::endl;
			this->array = NULL;
			this->lenght = 0;
			return (*this);
		}
	}
	this->array = new T[0]();
	this->lenght = 0;
	return (*this);
}

template<typename T>

T	&Array<T>::operator[](unsigned int pos) const
{
	if (pos >= this->lenght)
		throw OutOfBandsException();
	else
		return (this->array[pos]);
}

template<typename T>

size_t	Array<T>::size() const
{
	return (this->lenght);
}

template<typename T>

const char *Array<T>::OutOfBandsException::what() const throw()
{   
    return ((char *)"\033[1;31mError: index out of bands\033[0m");
}

#endif