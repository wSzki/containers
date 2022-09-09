/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers_definitions.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:09:33 by wszurkow          #+#    #+#             */
/*   Updated: 2022/08/29 16:10:20 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_DEFINITION_HPP
#define CONTAINERS_DEFINITION_HPP

#define PRINT(input)  std::cout << input << RCol << std::endl
#define PRINTR(input) PRINT(Red << input)
#define PRINTB(input) PRINT(Blu << input)
#define PRINTG(input) PRINT(Gre << input)
#define PRINTY(input) PRINT(Yel << input)
#define NEWLINE       PRINT("")
#define CONTINUE      NEWLINE; PRINT("Press ENTER to continue"); PRINT("---------------------------"); getchar()

#define RAI           random_access_iterator

#endif
