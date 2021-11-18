/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:23:35 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 22:32:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("Shrubbery Creation Form", GRADE_TO_SIGN, GRADE_TO_EXEC, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		Form::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

// Create a file called _shrubbery,
// and write ASCII trees inside it, in the current directory.
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	std::ofstream	ofs(this->getTarget() + "_shrubbery");
	if (!ofs)
		std::cout << "Could not open the shrubbery file" << std::endl;
	else
		ofs << "       _-_\n"
			<< "    /~~   ~~\\\n"
			<< " /~~         ~~\\\n"
			<< "{               }\n"
			<< " \\  _-     -_  /\n"
			<< "   ~  \\\\ //  ~\n"
			<< "       | |     \n"
			<< "       | |     \n"
			<< "      // \\\\\n";
}
