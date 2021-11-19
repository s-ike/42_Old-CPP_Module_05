/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:55:15 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/19 18:09:27 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

int	main()
{
	{
		print_header("unsigned error test");
		Bureaucrat				bureaucrat("TESTER(145)", 145);
		ShrubberyCreationForm	form("TARGET");

		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	{
		print_header("execute grade error test");
		Bureaucrat				bureaucrat("TESTER(145)", 145);
		ShrubberyCreationForm	form("TARGET");

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	{
		print_header("execute ShrubberyCreationForm normal test");
		Bureaucrat				bureaucrat("TESTER(137)", 137);
		ShrubberyCreationForm	form("NORMAL_TEST");

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	{
		print_header("execute RobotomyRequestForm normal test");
		Bureaucrat			bureaucrat("TESTER(45)", 45);
		RobotomyRequestForm	form("TARGET");

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	{
		print_header("execute PresidentialPardonForm normal test");
		Bureaucrat				bureaucrat("TESTER(5)", 5);
		PresidentialPardonForm	form("TARGET");

		bureaucrat.signForm(form);
		std::cout << form << std::endl;
		bureaucrat.executeForm(form);
	}

	{
		print_header("Derived Form copy constructor test");

		Bureaucrat				bureaucrat("ELITE(1)", 1);
		ShrubberyCreationForm	form1("TARGET");

		bureaucrat.signForm(form1);

		ShrubberyCreationForm	form2(form1);

		std::cout << "form2(form1); form2 =" << std::endl;
		std::cout << form2 << std::endl;
		std::cout << "form2's target: " << form2.getTarget() << std::endl;
	}

	{
		print_header("Derived Form assignment test");
		Bureaucrat				bureaucrat("ELITE(1)", 1);
		ShrubberyCreationForm	form1("TARGET");

		bureaucrat.signForm(form1);

		ShrubberyCreationForm	form2("@@@");
		std::cout << "form2's target: " << form2.getTarget() << std::endl;
		form2 = form1;

		std::cout << "form2 = form1; form2 =" << std::endl;
		std::cout << form2 << std::endl;
		std::cout << "form2's target: " << form2.getTarget() << std::endl;
	}
}
