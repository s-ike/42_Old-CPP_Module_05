/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:09:11 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 23:00:43 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form
{
	const std::string	_name;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
	bool				_is_sign;

public:
	// orthodox canonical form
	Form(
		const std::string& name = "Default Form",
		int grade_to_sign = 150,
		int grade_to_execute = 150);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();

	// accessor
	const std::string	getName() const;
	bool				getIsSign() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// methods
	void	beSigned(const Bureaucrat& bureaucrat);

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
std::ostream&	operator<<(std::ostream& lhs, const Form& rhs);

#endif /* FORM_HPP */
