/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:48:03 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 22:52:57 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("Presidential Pardon Form", GRADE_TO_SIGN, GRADE_TO_EXEC, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: Form(other)
{}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		Form::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

// Tells us has been pardoned by Zafod Beeblebrox.
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
