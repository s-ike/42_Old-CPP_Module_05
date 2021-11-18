/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:25:23 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 22:40:49 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>	// time
#include <cstdlib>	// srand,rand
#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("Robotomy Request Form", GRADE_TO_SIGN, GRADE_TO_EXEC, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other)
{}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		Form::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

// Makes some drilling noises,
// and tell us that has been robotomized successfully 50% of the time.
// Otherwise, tell us it’s a failure.
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	std::cout << "Whirrr...Whirrrrrr...Whirrrrrrrrrrrrrrr" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized" << std::endl;
}
