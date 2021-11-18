/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:18:58 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/19 00:34:30 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"

#define COLOR_RESET	"\033[m"
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
	{
		print_header("subject test (RobotomyRequestForm)");
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
			std::cout << *rrf << std::endl;
		else
			std::cout << "makeForm() failed" << std::endl;
		delete rrf;
	}
	{
		print_header("ShrubberyCreationForm test");
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
			std::cout << *rrf << std::endl;
		else
			std::cout << "makeForm() failed" << std::endl;
		delete rrf;
	}
	{
		print_header("PresidentialPardonForm test");
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
			std::cout << *rrf << std::endl;
		else
			std::cout << "makeForm() failed" << std::endl;
		delete rrf;
	}
	{
		print_header("unknown form test");
		Intern	someRandomIntern;
		Form*	rrf;

		rrf = someRandomIntern.makeForm("unknown", "Bender");
		if (rrf)
			std::cout << *rrf << std::endl;
		else
			std::cout << "makeForm() failed" << std::endl;
		delete rrf;
	}
}
