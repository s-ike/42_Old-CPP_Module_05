/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:21:24 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 22:24:09 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	const static int	GRADE_TO_SIGN = 72;
	const static int	GRADE_TO_EXEC = 45;

public:
	// orthodox canonical form
	RobotomyRequestForm(const std::string& target = "Default");
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	virtual					~RobotomyRequestForm();

	// methods
	virtual void	execute(Bureaucrat const & executor) const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
