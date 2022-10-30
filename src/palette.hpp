/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszurkow <wszurkow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:36:21 by wszurkow          #+#    #+#             */
/*   Updated: 2022/08/28 00:38:03 by wszurkow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifdef COLOR
#define CLEAR std::cout << "\033c";

#define _KO "\e[0;31mKO"
#define _OK "\e[0;32mOK"

# define RCol    "\e[0m"

# define Bla     "\e[0;30m"
# define BBla    "\e[1;30m"
# define UBla    "\e[4;30m"
# define IBla    "\e[0;90m"
# define BIBla   "\e[1;90m"
# define On_Bla  "\e[40m"
# define On_IBla "\e[0;100m"

# define Red     "\e[0;31m"
# define BRed    "\e[1;31m"
# define URed    "\e[4;31m"
# define IRed    "\e[0;91m"
# define BIRed   "\e[1;91m"
# define On_Red  "\e[41m"
# define On_IRed "\e[0;101m"

# define Gre     "\e[0;32m"
# define BGre    "\e[1;32m"
# define UGre    "\e[4;32m"
# define IGre    "\e[0;92m"
# define BIGre   "\e[1;92m"
# define On_Gre  "\e[42m"
# define On_IGre "\e[0;102m"

# define Yel     "\e[0;33m"
# define BYel    "\e[1;33m"
# define UYel    "\e[4;33m"
# define IYel    "\e[0;93m"
# define BIYel   "\e[1;93m"
# define On_Yel  "\e[43m"
# define On_IYel "\e[0;103m"

# define Blu     "\e[0;34m"
# define BBlu    "\e[1;34m"
# define UBlu    "\e[4;34m"
# define IBlu    "\e[0;94m"
# define BIBlu   "\e[1;94m"
# define On_Blu  "\e[44m"
# define On_IBlu "\e[0;104m"

# define Pur     "\e[0;35m"
# define BPur    "\e[1;35m"
# define UPur    "\e[4;35m"
# define IPur    "\e[0;95m"
# define BIPur   "\e[1;95m"
# define On_Pur  "\e[45m"
# define On_IPur "\e[0;105m"

# define Cya     "\e[0;36m"
# define BCya    "\e[1;36m"
# define UCya    "\e[4;36m"
# define ICya    "\e[0;96m"
# define BICya   "\e[1;96m"
# define On_Cya  "\e[46m"
# define On_ICya "\e[0;106m"

# define Whi     "\e[0;37m"
# define BWhi    "\e[1;37m"
# define UWhi    "\e[4;37m"
# define IWhi    "\e[0;97m"
# define BIWhi   "\e[1;97m"
# define On_Whi  "\e[47m"
# define On_IWhi "\e[0;107m"

#else
#define CLEAR std::cout << "\033c";

# define RCol    ""
# define Bla     ""
# define BBla    ""
# define UBla    ""
# define IBla    ""
# define BIBla   ""
# define On_Bla  ""
# define On_IBla ""
# define Red     ""
# define BRed    ""
# define URed    ""
# define IRed    ""
# define BIRed   ""
# define On_Red  ""
# define On_IRed ""
# define Gre     ""
# define BGre    ""
# define UGre    ""
# define IGre    ""
# define BIGre   ""
# define On_Gre  ""
# define On_IGre ""
# define Yel     ""
# define BYel    ""
# define UYel    ""
# define IYel    ""
# define BIYel   ""
# define On_Yel  ""
# define On_IYel ""
# define Blu     ""
# define BBlu    ""
# define UBlu    ""
# define IBlu    ""
# define BIBlu   ""
# define On_Blu  ""
# define On_IBlu ""
# define Pur     ""
# define BPur    ""
# define UPur    ""
# define IPur    ""
# define BIPur   ""
# define On_Pur  ""
# define On_IPur ""
# define Cya     ""
# define BCya    ""
# define UCya    ""
# define ICya    ""
# define BICya   ""
# define On_Cya  ""
# define On_ICya ""
# define Whi     ""
# define BWhi    ""
# define UWhi    ""
# define IWhi    ""
# define BIWhi   ""
# define On_Whi  ""
# define On_IWhi ""
#endif
