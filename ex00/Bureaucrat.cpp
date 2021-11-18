/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:23:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 11:59:15 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
/*   methods                                                                  */
/* ************************************************************************** */

const std::string	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

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
