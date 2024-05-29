/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:02:51 by ftholoza          #+#    #+#             */
/*   Updated: 2024/05/29 03:22:32 by francesco        ###   ########.fr       */
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
		bool	alloc;
	public:
		Array();
		Array(Array &to_copy);
		Array(unsigned int size);
		~Array();

		Array<T> &operator=(Array<T> &to_copy);
		T	&operator[](const unsigned int pos);
		T	&operator[](unsigned int pos);
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
	std::cout << "Array: default constructor called" << std::endl;
	this->array = NULL;
	this->lenght = 0;
	this->alloc = false;
}

template<typename T>

Array<T>::Array(unsigned int size)
{
	std::cout << "Array: constructor called" << std::endl;
	if (size == 0)
	{
		this->array = NULL;
		this->lenght = 0;
		this->alloc = false;
	}
	try
	{
		this->array = new	T[size];
		this->lenght = size;
		this->alloc = true;
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << e.what() << std::endl;
		this->array = NULL;
		this->alloc = false;
		this->lenght = 0;
		return ;
	}
	return ;
}

template<typename T>

Array<T>::~Array()
{
	std::cout << "Array: destructor called memory liberated" << std::endl;
	if (this->alloc == true)
		delete	[] this->array;
	return ;
}

template<typename T>

Array<T>::Array(Array &to_copy)
{
	std::cout << "copy constructor called" << std::endl;
	if (to_copy.lenght != 0)
	{
		try
		{
			this->array = new	T[to_copy.lenght];
			this->alloc = true;
			for (int i = 0; i < to_copy.lenght; i++)
				this->array[i] = to_copy.array[i];
			this->lenght = to_copy.lenght;	
			this->alloc = true;
		}
		catch (std::bad_alloc &e)
		{
			std::cerr << e.what();
			this->lenght = 0;
			this->array = NULL;
			this->alloc = false;
		}
	}
	this->lenght = 0;
	this->alloc = false;
	this->array = NULL;
	return ;
}

template<typename T>

Array<T>& Array<T>::operator=(Array<T> &to_copy)
{
	int	i;

	i = 0;
	if (this->alloc == true)
		delete [] this->array;
	if (to_copy.lenght != 0)
	{
		try
		{
			this->array = new T[to_copy.lenght];
		}
		catch (std::bad_alloc &e)
		{
			std::cerr << e.what() << std::endl;
			this->alloc = false;
			this->array = NULL;
			this->lenght = 0;
			return ;
		}
		while (i < to_copy.lenght)
		{
			this->array[i] = to_copy.array[i];
			i++;
		}
		this->lenght = to_copy.lenght;
		this->alloc = true;
		return (*this);
	}
	this->array = NULL;
	this->alloc = false;
	this->lenght = 0;
	return (*this);
}

template<typename T>

T	&Array<T>::operator[](unsigned int pos)
{
	if (pos >= this->lenght)
	{
		throw OutOfBandsException();
	}
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