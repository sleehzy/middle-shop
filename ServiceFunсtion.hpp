#ifndef _SERVICEFUNCTION_HPP
#define _SERVICEFUNCTION_HPP
#include <iostream>
#include <string>
#include <windows.h>

bool IsNumber(const std::string& str);
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}
inline void Err(int mode = 0)
{
	std::cout << "Некорректный ввод\n";
	if (mode == 1)
	{
		system("cls");
	}


}

#endif //!_SERVICEFUNCTION_HPP_
