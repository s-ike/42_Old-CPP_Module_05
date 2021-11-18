/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:42:48 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 22:44:51 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	const static int	GRADE_TO_SIGN = 25;
	const static int	GRADE_TO_EXEC = 5;

public:
	// orthodox canonical form
	PresidentialPardonForm(const std::string& target = "Default");
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	virtual					~PresidentialPardonForm();

	// methods
	virtual void	execute(Bureaucrat const & executor) const;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */
