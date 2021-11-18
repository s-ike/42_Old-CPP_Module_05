/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:47:01 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 15:31:12 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "Form.hpp"

/* ************************************************************************** */
/*   orthodox canonical form                                                  */
/* ************************************************************************** */

Form::Form(
	const std::string& name,
	int grade_to_sign,
	int grade_to_execute)
	:
	_name(name),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute),
	_is_sign(false)
{
	if (_grade_to_sign < Bureaucrat::HIGHEST
		|| _grade_to_execute < Bureaucrat::HIGHEST)
		throw GradeTooHighException();
	else if (Bureaucrat::LOWEST < _grade_to_sign
		|| Bureaucrat::LOWEST < _grade_to_execute)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	:
	_name(other._name),
	_grade_to_sign(other._grade_to_sign),
	_grade_to_execute(other._grade_to_execute),
	_is_sign(other._is_sign)
{}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		_is_sign = other._is_sign;
	return *this;
}

Form::~Form()
{}

/* ************************************************************************** */
/*   accessor                                                                 */
/* ************************************************************************** */

const std::string	Form::getName() const
{
	return _name;
}

bool	Form::getIsSign() const
{
	return _is_sign;
}

int	Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int	Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

/* ************************************************************************** */
/*   methods                                                                  */
/* ************************************************************************** */

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _grade_to_sign)
		_is_sign = true;
	else
		throw GradeTooLowException();
}

/* ************************************************************************** */
/*   exception classes                                                        */
/* ************************************************************************** */

const char*	Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

/* ************************************************************************** */
/*   overload of operators                                                    */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs)
{
	std::string	bool_value = rhs.getIsSign() ? "true" : "false";
	lhs << std::setw(48) << std::setfill('-') << '-' << std::setfill(' ') << '\n'
		<< '|' << std::setw(46) << ' ' << "|\n"
		<< '|' << std::setw(19) << std::right << " name: "       << std::setw(27) << std::left << rhs.getName() << "|\n"
		<< '|' << std::setw(19) << std::right << " grade to sign: "   << std::setw(27) << std::left << rhs.getGradeToSign() << "|\n"
		<< '|' << std::setw(19) << std::right << " grade to execute: " << std::setw(27) << std::left << rhs.getGradeToExecute() << "|\n"
		<< '|' << std::setw(19) << std::right << " is signed: "  << std::setw(27) << std::left << bool_value << "|\n"
		<< '|' << std::setw(46) << ' ' << "|\n"
		<< std::setw(48) << std::setfill('-') << '-' << std::setfill(' ');
		// << "------------------------------------------------";
	return lhs;
}
