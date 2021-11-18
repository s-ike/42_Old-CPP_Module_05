/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:23:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 15:57:18 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name)
{
	if (grade < HIGHEST)
		throw GradeTooHighException();
	else if (LOWEST < grade)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: _name(other._name), _grade(other._grade)
{}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		if (other._grade < HIGHEST)
			throw GradeTooHighException();
		else if (LOWEST < other._grade)
			throw GradeTooLowException();
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

/* ************************************************************************** */
/*   accessor                                                                 */
/* ************************************************************************** */

const std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

void	Bureaucrat::incrementGrade()
{
	if (_grade <= HIGHEST)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= LOWEST)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs the " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " cannot sign because " << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*   exception classes                                                        */
/* ************************************************************************** */

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

/* ************************************************************************** */
/*   overload of operators                                                    */
/* ************************************************************************** */

// <name>, bureaucrat grade <grade>
std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat& rhs)
{
	return lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
}
