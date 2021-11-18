/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:09:11 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 13:29:45 by sikeda           ###   ########.fr       */
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
	Form(
		const std::string& name,
		int grade_to_sign,
		int grade_to_execute);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();

	const std::string	getName() const;
	bool				getIsSign() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	void	beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs);

#endif /* FORM_HPP */
