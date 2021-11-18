/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:34:30 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/19 00:17:33 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "debug" << std::endl;
	return *this;
}

Intern::~Intern()
{}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

namespace
{
	Form*	make_ShrubberyCreationForm(const std::string& target)
	{
		return new ShrubberyCreationForm(target);
	}

	Form*	make_RobotomyRequestForm(const std::string& target)
	{
		return new RobotomyRequestForm(target);
	}

	Form*	make_PresidentialPardonForm(const std::string& target)
	{
		return new PresidentialPardonForm(target);
	}
}

// It will print something like "Intern creates <form>" to the standard output.
// If the requested form is not known, print an explicit error message.
Form*	Intern::makeForm(
	const std::string& form_name,
	const std::string& target)
{
	const std::string	form_names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	Form*	(* const fs[])(const std::string& target) = {
		make_ShrubberyCreationForm,
		make_RobotomyRequestForm,
		make_PresidentialPardonForm};
	for (unsigned i = 0; i < sizeof(form_names) / sizeof(form_names[0]); i++)
	{
		if (form_name == form_names[i])
		{
			std::cout << "Intern creates " << form_names[i] << std::endl;
			return fs[i](target);
		}
	}
	std::cout << "Intern cannot create " << form_name << std::endl;
	return NULL;
}
