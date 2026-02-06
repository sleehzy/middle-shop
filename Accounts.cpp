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
 unsigned int* userId = new unsigned int[userSize] {1, 2, 3};
 bool isSetCreated = false;



 //todo сделать сет для логина и пароля

 void ChangeAccounts()
 {
	 if (!isSetCreated)
	 {

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
			
		 }
		 else if (choose == "2")
		 {
			 
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


 void CreatNewUser()
 {

 }

 void CreatSet()
 {
	 // todo
 }
