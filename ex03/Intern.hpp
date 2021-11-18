/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 23:28:14 by sikeda            #+#    #+#             */
/*   Updated: 2021/11/18 23:51:32 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "Form.hpp"

class Intern
{
public:
	// orthodox canonical form
	Intern();
	Intern(const Intern& other);
	Intern&	operator=(const Intern& other);
	~Intern();

	// methods
	Form*	makeForm(
		const std::string& form_name,
		const std::string& target);
};

#endif /* INTERN_HPP */
