/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:43:11 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 23:03:36 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Form;

class Bureaucrat
{
	const std::string	_name;
	int					_grade;	// that ranges from 1 (highest possible) to 150 (lowest possible)

public:
	// orthodox canonical form
	Bureaucrat(const std::string& name = "default", int grade = LOWEST);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	//public constant values
	const static int	HIGHEST = 1;
	const static int	LOWEST = 150;

	// accessor
	const std::string	getName() const;
	int					getGrade() const;

	// methods
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(Form& form);

	// exception classes
	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};
};

// overload of operators
std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif /* BUREAUCRAT_HPP */
