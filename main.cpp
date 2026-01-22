#include <Windows.h>
#include <type_traits>
#include <string>
#include <iostream>

/*
 Система продажи товаров
 Учёьные записи: сотрудник, администратор, супер администратор
 Система авторизации
 Основное меню: показать склад, продажи, пополнить склад, списать со склада
 изменить цену,редактирование склада (изменение названия товара, удаления товара из списка,
 добавления товара)
 Редактор учетных записей: добавление сотрудника, редоктирование сотрудника (пароль логин),
   удалить сотрудника
 Отчёт о прибыли. Премии
 Закрытие смены
 Счётчик покупателей
 Cистема штрафов
 NoIntJanuyary
 Нейминг, деление на файлы и функции, проверка на ввод




 Файлы cpp/hpp
 1)main
 2)Storage.cpp
 3)Accounts.cpp
 4)Sellings.cpp
 5)ServiceFunctions.cpp
 6)Login.cpp


 iostream,Windows.h, iomanip, string, cstdlib



*/

size_t userSize = 3;
std::string currentStatus;
unsigned int currentId = 0;
std::string* loginArr = new std::string[userSize]{"admin", "user1", "user2"};
std::string * passArr = new std::string[userSize]{ "admin", "user1", "user2" };
std::string* userStatus = new std::string[userSize]{ "superAdministrator"
  ,"Administrator", "User" };
double* awardArr = new double[userSize] {};
double* fineArr = new double[userSize] {};
unsigned int* userId = new unsigned int[userSize] {1, 2, 3};

void Start();
bool Login();
void SuperAdminMenu();


int main()
{
	Start();


	delete[] loginArr; 
	delete[] passArr;
	delete[] userStatus;
	delete[] awardArr;
	delete[] fineArr;
	delete[] userId;




	return 0;
}

bool Login()
{
	std::string login, pass;

	while(true)
	{
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Введите пароль: ";
		std::getline(std::cin, pass, '\n');
		
		for(size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "приветствуем вас" << loginArr[i] << "\n";
				std::cout << "Ваш статус: " << userStatus[i] << "\n";
				currentStatus = userStatus[i];
				currentId = i;
				return true;
			}

		}

		std::cout << "Неверный логин или пароль. Повторите попытку\n\n";
		//sleep
		// to do exit from the programm

	}
	
}




void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\n\n\n\t\t\t Добро пожаловать!\n\n\t\t\t Дефицит оперативной памяти\n\n\n";
	if(Login())
	{
		if(currentStatus == userStatus[0])
		{
			SuperAdminMenu();
		}
		else if (currentStatus == userStatus[1])
		{

		}
		else if (currentStatus == userStatus[2])
		{

		}
		else
		{
			std::cerr << "CURRENT_STATUS_LOGIN_ERROR_";
		}
	}
	else
	{
		// exit
	}

}

void SuperAdminMenu()
{
	std::string choose;
	while(true)
	{
		std::cout << "1) Начать продажу\n";
		std::cout << "2) Показать склад\n";
		std::cout << "3) Попольнить товары\n";
		std::cout << "4) Списать товары\n";
		std::cout << "5) Изменить цены\n";
		std::cout << "6) Редактировать склад\n";
		std::cout << "7) Редактировать сотрудников\n";
		std::cout << "8) Отчёт о прибыли\n";
		std::cout << "0) Выход\n";
		std::getline(std::cin, choose, '\n');
		if(choose == "1")
		{

		}
		if (choose == "2")
		{

		}
		if (choose == "3")
		{

		}
		if (choose == "4")
		{

		}
		if (choose == "5")
		{

		}
		if (choose == "6")
		{

		}
		if (choose == "7")
		{

		}
		if (choose == "8")
		{

		}
		if (choose == "0")
		{

		}
		else
		{

		}








	}



}


