/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:43:11 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 11:44:38 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
private:
	const static int	HIGHEST = 1;
	const static int	LOWEST = 150;

	const std::string	_name;
	int					_grade;	// that ranges from 1 (highest possible) to 150 (lowest possible)

public:
	Bureaucrat(const std::string& name = "default", int grade = LOWEST);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string	getName() const;
	int					getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	class GradeTooHighException : public std::exception
	{
		virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat& rhs);

#endif /* BUREAUCRAT_HPP */
