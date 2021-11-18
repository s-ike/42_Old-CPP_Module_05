/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:08:00 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 17:52:33 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	const static int	GRADE_TO_SIGN = 145;
	const static int	GRADE_TO_EXEC = 137;

public:
	// orthodox canonical form
	ShrubberyCreationForm(const std::string& target = "Default");
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	virtual					~ShrubberyCreationForm();

	// methods
	virtual void	execute(Bureaucrat const & executor) const;
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
