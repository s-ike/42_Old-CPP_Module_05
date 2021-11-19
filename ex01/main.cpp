/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:47:08 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/19 16:46:14 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define COLOR_RESET	"\033[m"
#define COLOR_RED	"\033[31m"
#define COLOR_CYAN	"\033[36m"

#define CATCH_ERR (std::cout << COLOR_RED << e.what() << COLOR_RESET << std::endl)

void	print_header(const std::string &str)
{
	std::cout
		<< COLOR_CYAN
		<< "\n[ " << str << " ]"
		<< COLOR_RESET
		<< std::endl;
}

void	test_signForm(Form& form, Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;
}

int	main()
{
	print_header("error test");
	try
	{
		Form	err_form("Error Form", 0, 1);
	}
	catch (std::exception & e)
	{
		CATCH_ERR;
	}

	try
	{
		Form	err_form("Error Form", 151, 150);
	}
	catch (std::exception & e)
	{
		CATCH_ERR;
	}

	try
	{
		Form	err_form("Error Form", 1, 0);
	}
	catch (std::exception & e)
	{
		CATCH_ERR;
	}

	try
	{
		Form	err_form("Error Form", 150, 151);
	}
	catch (std::exception & e)
	{
		CATCH_ERR;
	}

	print_header("normal test 1");
	try
	{
		Form		form("Presidential Pardon Form", 25, 5);
		Bureaucrat	bureaucrat("bureaucrat-1", 1);
		test_signForm(form, bureaucrat);
	}
	catch (std::exception & e)
	{
		CATCH_ERR;
	}

	print_header("normal test 2");
	try
	{
		Form		form("Presidential Pardon Form", 25, 5);
		Bureaucrat	bureaucrat("bureaucrat-2", 150);
		test_signForm(form, bureaucrat);
	}
	catch (std::exception & e)
	{
		CATCH_ERR;
	}

	print_header("normal test 3");
	try
	{
		Form		form("Presidential Pardon Form", 25, 5);
		Bureaucrat	bureaucrat("bureaucrat-3", 25);
		test_signForm(form, bureaucrat);
	}
	catch (std::exception & e)
	{
		CATCH_ERR;
	}
}
