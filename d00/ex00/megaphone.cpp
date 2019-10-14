// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: istalevs <istalevs@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 21:52:13 by istalevs          #+#    #+#             //
//   Updated: 2018/10/02 21:52:14 by istalevs         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int line = 1; line < argc; line++)
        for (int letter = 0; argv[line][letter]; letter++)
            std::cout << char(toupper(argv[line][letter]));
    std::cout << std::endl;
    return (0);
}
