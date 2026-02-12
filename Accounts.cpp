#include "Accounts.hpp"


 size_t userSize = 3;
 std::string currentStatus;
 unsigned int currentId = 0;
 std::string* loginArr = new std::string[userSize]{ "admin", "user1", "user2" };
 std::string* passArr = new std::string[userSize]{ "admin", "user1", "user2" };
 std::string* userStatus = new std::string[userSize]{ "superAdministrator"
  ,"Administrator", "User" };
 double* awardArr = new double[userSize] {};
 double* fineArr = new double[userSize] {};
 unsigned int* userId = new unsigned int[userSize] {0, 1, 2};
 bool isSetCreated = false;


  std::unordered_set<char> loginSymbols;
  std::unordered_set<char> passSymbols;
  unsigned int maxLogin = 15;
  unsigned int maxPass = 25;
  unsigned int minLogin = 5;
  unsigned int minPass = 8;

 void ChangeAccounts()
 {
	 if (!isSetCreated)
	 {
		 CreateSet();
	 }

	 std::string choose;
	 while (true)
	 {
		 system("cls");
		 std::cout << "1 - Создать новый аккаунт\n";
		 std::cout << "2 - Показать всех сотрудников\n";
		 std::cout << "3 - Изменить логин\n";
		 std::cout << "4 - изменить пароль\n";
		 std::cout << "5 - Изменить уровни доступа\n";
		 std::cout << "6 - Редактировать профиль сотрудника\n";
		 std::cout << "7 - Удали аккаунт\n";
		 std::cout << "0 - Выход\n";
		 std::cout << "Ввод: ";
		 Getline(choose);
		 if (choose == "1")
		 {
			 CreateNewUser();
		 }
		 else if (choose == "2")
		 {
			 if (currentStatus == userStatus[1])
			 {
				 ShowUsers();
			 }
			 else if (currentStatus == userStatus[0])
			 {
				 ShowUsers(1);
			 }
			 system("pause");
		 }
		 else if (choose == "3")
		 {
			 
		 }
		 else if (choose == "4")
		 {
			 
		 }
		 else if (choose == "5")
		 {

		 }
		 else if (choose == "6")
		 {

		 }
		 else if (choose == "7")
		 {

		 }
		 else if (choose == "0")
		 {
			 std::cout << "Выходи из редактора склада\n";
			 Sleep(1500);
			 break;
		 }
		 else
		 {
			 Err();
		 }
	 }
 }


 void CreateNewUser()
 {
	 std::string choose, chooseLogin, choosePass, chooseStatus;
	 bool isExit = true;

	 while (true)
	 {
		 
		 while (true)
		 {
			 isExit = true;
			 system("cls");
			 std::cout << "Введите логин или \"exit\" для выхода \nВвод: ";
			 Getline(chooseLogin);
			 if (chooseLogin == "exit")
			 {
				 std::cout << "отмена создания нового пользователя\n";
				 isExit = false;
				 Sleep(1500);
				 break;
			 }
			 if(CheckLogin(chooseLogin))
			 {
				 break;
			 }
			
		 }

		 while (isExit)
		 {
			 system("cls");
			 std::cout << "Введите пароль или \"exit\" для выхода \nВвод: ";
			 Getline(choosePass);
			 if (choosePass == "exit")
			 {
				 std::cout << "отмена создания нового пользователя\n";
				 isExit = false;
				 Sleep(1500);
				 break;
			 }
			 if (true)
			 {


			 }
		 }

		 while (isExit)
		 {
			 system("cls");
			 isSame = false;
			 std::cout << "Введите цену нового товара или \"exit\" для выхода \nВвод: ";
			 Getline(choosePrice);
			 if (choosePrice == "exit")
			 {
				 std::cout << "отмена создания новой цены\n";
				 isExit = false;
				 Sleep(1500);
				 break;
			 }

			 if (IsNumber(choosePrice))
			 {
				 price = std::stod(choosePrice);
				 if (price < 0 || price > maxPrice)
				 {
					 std::cout << "Ошибка! максимальная цена: " << maxPrice << "рублей\n\n";
					 Sleep(1500);
				 }
				 else
				 {
					 break;
				 }

			 }
			 else
			 {
				 Err();
			 }
		 }

		 if (!isExit)
		 {
			 break;
		 }

		 else
		 {
			 std::cout << "Новый товар: " << chooseName << "\n";
			 std::cout << "Кол-во: " << count << "\n";
			 std::cout << "Цена: " << price << "\n";
			 std::cout << "Подтвердить? \n1 - Да\n2 - Отмена\nВвод: ";
			 Getline(choose);
			 if (choose == "1")
			 {
				 ArrPushBack(idArr, size);
				 ArrPushBack(nameArr, size);
				 ArrPushBack(priceArr, size);
				 ArrPushBack(countArr, size);
				 size++;
				 idArr[size - 1] = size;
				 nameArr[size - 1] = chooseName;
				 countArr[size - 1] = count;
				 priceArr[size - 1] = price;
				 currentStorageSize += count;
				 CheckExpensiveItem();
				 std::cout << "Товар успешно добавлен\n\n";
				 Sleep(1700);
				 break;
			 }
			 else if (choose == "2")
			 {
				 std::cout << "Отмена добовление товара!\n";
				 Sleep(1500);
			 }
			 else
			 {
				 Err();
			 }

		 }
	 }


 }

 void ShowUsers(int mode)
 {
	 system("cls");
	 std::cout << "ID" << "   Логин" << std::left << std::setw(maxLogin + 10)
		 << "\t\tПароль \n";
	 if (mode == 0)
	 {
		 

		 for (size_t i = 1; i < userSize; i++)
		 {
			 std::cout << userId[i]<< "\t" << std::left << std::setw(maxLogin) << loginArr[i]
				 << "\t" << passArr[i] << "\n";

		 }


	 }
	 else if (mode == 1)
	 {

		 for (size_t i = 0; i < userSize; i++)
		 {
			 std::cout << userId[i] << "\t" << std::left << std::setw(maxLogin) << loginArr[i]
				 << "\t" << passArr[i] << "\n";

		 }

	 }

 }

 bool CheckLogin(const std::string& chooseLogin)
 {
	
	 if (chooseLogin.size() < minLogin || chooseLogin.size() > maxLogin)
	 {
		 std::cout << "Ошибка длины логина! от " << minLogin << " до " << maxLogin << "\n";
		 Sleep(1500);
		 return false;
	 }
	 else
	 {
		 for (size_t i = 0; i < chooseLogin.size(); i++)
		 {
			 if (!loginSymbols.count(chooseLogin[i]))
			 {
				 std::cout << "Некорректные символы логина. Только Допустимые символы A-Z, a-z, 0-9\n\n";
				 Sleep(2000);
				 return false;
			 }
		 }
	 }



	 for (size_t i = 0; i < userSize; i++)
	 {
		 if (chooseLogin == loginArr[i])
		 {
			 std::cout << "Такой пользователь уже создан\n";
			 Sleep(1500);
			 return false;
		 }

	 }
	 return true;
 }

 bool CheckPass(const std::string& choosePass)
 {
	 int symbolCount = 0, maxSymbols = 3, numberCount = 0, maxNumber = 3, letterCount = 0, maxletter = 3;
	 if (choosePass.size() < minPass || choosePass.size() > maxPass)
	 {

		 std::cout << "Ошибка длины пароля! от " << minPass << " до " << maxPass << "\n";
		 Sleep(1500);
		 return false;
	 }
	 else 
	 {
		 for (size_t i = 0; i < choosePass.size(); i++)
		 {
			 if (!passSymbols.count(choosePass[i]))
			 {
				 std::cout << "Некорректный пароль. Допустимые символы: A-Z, a-z, 0-9 и стандартные символы\n\n";
				 Sleep(2000);
				 return false;
			 }
			 else if (std::isdigit(choosePass[i]))
			 {
				 numberCount++;
			 }
			 else if (choosePass[i] >='A' && choosePass[i] <= 'Z' || choosePass[i] >= 'a' && choosePass[i] <= 'z')
			 {
				 letterCount++;
			 }
			 else 
			 {
				 symbolCount++;
			 }
		 }

	 }
	


 }

 void CreateSet()
 {
	 if (isSetCreated)
	 {
		 return;
	 }
	 else 
	 {
		 isSetCreated = true;
		 for (char i = '0'; i <= '9'; i++)
		 {
			 loginSymbols.insert(i);
		 }

		 for (char i = 'A'; i <= 'Z'; i++)
		 {
			 loginSymbols.insert(i);
		 }
		 for (char i = 'a'; i <= 'z'; i++)
		 {
			 loginSymbols.insert(i);
		 }
		 for (char i = '!'; i < '}'; i++)
		 {
			 passSymbols.insert(i);
		 } 



	 }

 }
