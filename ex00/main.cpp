/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:47:08 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 21:28:58 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_RED	"\033[31m"
#define COLOR_CYAN	"\033[36m"

void	print_header(const std::string &str)
{
	std::cout
		<< COLOR_CYAN
		<< "\n[ " << str << " ]"
		<< COLOR_RESET
		<< std::endl;
}

int	main()
{
	try
	{
		print_header("normal (1)");
		Bureaucrat	test("test0", 1);

		std::cout << test << std::endl;

		print_header("increment test (1)");
		test.incrementGrade();
		std::cout << test << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		print_header("normal (75)");
		Bureaucrat	test("test2", 75);

		std::cout << test << std::endl;

		print_header("increment test (75)");
		test.incrementGrade();
		std::cout << test << std::endl;

		print_header("decrement test (74)");
		test.decrementGrade();
		std::cout << test << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		print_header("normal (150)");
		Bureaucrat	test("test3", 150);

		std::cout << test << std::endl;

		print_header("decrement test (150)");
		test.decrementGrade();
		std::cout << test << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		print_header("too high (0)");
		Bureaucrat	test("error1", 0);

		std::cout << test << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		print_header("too low (151)");
		Bureaucrat	test("error2", 151);

		std::cout << test << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		print_header("Bureaucrat copy constructor test");
		Bureaucrat	test1("test1", 1);
		Bureaucrat	test2(test1);

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
