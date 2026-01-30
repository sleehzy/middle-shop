#include "Storage.hpp"




 size_t size = 0;
 unsigned int* idArr = nullptr;
 std::string* nameArr = nullptr;
 unsigned int* countArr = nullptr;
 double* priceArr = nullptr;
 bool isStorageCreated = false;
 unsigned int maxStorageSize = 3000;
 unsigned int currentStorageSize = 0;
 double maxPrice = 300000;

 void CreateStorage()
 {
	 const size_t staticSize = 10;

	 unsigned int staticIdArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	 std::string staticNameArr[staticSize]
	 {
		 "Team Group T-Force Delta RGB", "ADATA XPG Lancer Blade", "Kingston FURY Beast Black",
			 "ADATA XPG Lancer Blade RGB", "AMD Ryzen 5 7500F OEM", "MSI B650M GAMING PLUS WIFI",
			 "Palit GeForce RTX 5060 Ti White OC", "1000 ГБ M.2 NVMe накопитель Kingston NV3",
			 " Cougar GEC SNOW 650 ", "Корпус MONTECH KING 95 PRO"
	 };
	  unsigned int staticCountArr[staticSize]{ 4,2,6,7,15,17,23,30,12,5 };
	  double staticPriceArr[staticSize]{ 41999.0,32980.0,36566.0,47999.0,13499.0,11543.0,40999.0,12865.0,
		 6499.0,7500.0 };
	  if (!isStorageCreated)
	  {
		  size = staticSize;
		  idArr = new unsigned int[size];
		  nameArr = new std::string[size];
		  countArr = new unsigned int[size];
		  priceArr = new double[size];
		  FillArray(idArr, staticIdArr);
		  FillArray(nameArr, staticNameArr);
		  FillArray(countArr, staticCountArr);
		  FillArray(priceArr, staticPriceArr);
		  for (size_t i = 0; i < size; i++)
		  {
			  currentStorageSize += countArr[i];
		  }

	  }
	 
 }

 void ShowStorage(int mode)
 {
	 if(mode == 0)
	 {
		 system("cls");
		 std::cout << "ID\t" << std::left << std::setw(50) << "Название товара\t" << "Кол-во\t" << "Цена\t" << "\n";
		 for (size_t i = 0; i < size; i++)
		 {
			 std::cout << idArr[i] << "\t" << std::left << std::setw(40) << nameArr[i] << "\t\t" << countArr[i]
				 << "\t" << priceArr[i] << "\n";
		 }
		 system("pause");

	 }
	 else if (mode == 1)
	 {
		 system("cls");
		 std::cout << "ID\t" << std::left << std::setw(50) << "Название товара\t" << "Кол-во\t" << "Цена\t" << "\n";
		 for (size_t i = 0; i < size; i++)
		 {
			 std::cout << idArr[i] << "\t" << std::left << std::setw(50) << nameArr[i] << "\t\t" << countArr[i] << "\n";
		 }
		 std::cout << "\nЗаполненость склада: " << currentStorageSize << "/" << maxStorageSize << "\n\n";
	 }
	 else if (mode == 2)
	 {
		 system("cls");
		 std::cout << "ID\t" << std::left << std::setw(65) << "Название товара\t" << "Цена\t" << "\n";
		 for (size_t i = 0; i < size; i++)
		 {
			 std::cout << idArr[i] << "\t" << std::left << std::setw(50) << nameArr[i] << "\t\t" << priceArr[i] << "\n";
		 }
		 

	 }

 }

 void AddProduct()
 {
	 std::string chooseId, chooseCount, choose;
	 int id = 0;
	 unsigned int count = 0;
	 
	 while (true)
	 {
		 ShowStorage(1);
		 std::cout << "Введите ID товара или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Завернешине операции пополнения товара\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId) - 1;
			 if (id < 0 || id > size - 1)
			 {
				 Err();
			 }
			 else 
			 {
				 std::cout << "Введите количество товара для пополнения: ";
				 Getline(chooseCount);
				 if (IsNumber(chooseCount))
				 {
					 count = std::stoi(chooseCount);
					 if (count < 0 || count >= maxStorageSize - currentStorageSize)
					 {
						 std::cout << "Некорректное кол-во! на складе осталось"
							 << maxStorageSize - currentStorageSize << "мест для товаров\n\n";
						 Sleep(3000);
					 }
					 else 
					 {
						 while (true)
						 {
							 std::cout << nameArr[id] << "\t" << countArr[id] << "------> "
								 << countArr[id] + count << "\n\n";
							 std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
							 Getline(choose);
							 if (choose == "1")
							 {
								 std::cout << "Товар успешно добавлен\n";
								 countArr[id] += count;
								 currentStorageSize += count;
								 Sleep(1500);
								 break;
							 }
							 else if (choose == "2")
							 {
								 std::cout << "Отмена пополнения " << nameArr[id] << "\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err(1);
							 }
						 }
						 
					 }

				 }


			 }

		 }
		 

	 }


 }

 void RemoveProduct()
 {
	 std::string chooseId, chooseCount, choose;
	 int id = 0;
	 unsigned int count = 0;

	 while (true)
	 {
		 ShowStorage(1);
		 std::cout << "Введите ID товара или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Завернешине операции списание товара\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stoi(chooseId) - 1;
			 if (id < 0 || id > size - 1)
			 {
				 Err();
			 }
			 else
			 {
				 std::cout << "Введите количество товара для списания: ";
				 Getline(chooseCount);
				 if (IsNumber(chooseCount))
				 {
					 count = std::stoi(chooseCount);
					 if (count < 0 || count >countArr[id])
					 {
						 std::cout << "Некорректное кол-во! на складе осталось"
							 << countArr[id] << " выбранного товара\n\n";
						 Sleep(3000);
					 }
					 else
					 {
						 while (true)
						 {
							 std::cout << nameArr[id] << "\t" << countArr[id] << "------> "
								 << countArr[id] - count << "\n\n";
							 std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
							 Getline(choose);
							 if (choose == "1")
							 {
								 std::cout << "Товар успешно списан\n";
								 countArr[id] -= count;
								 currentStorageSize -= count;
								 Sleep(1500);
								 break;
							 }
							 else if (choose == "2")
							 {
								 std::cout << "Отмена списание " << nameArr[id] << "\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err(1);
							 }
						 }

					 }

				 }


			 }

		 }


	 }


 }

 void ChangePrice()
 {
	 std::string chooseId, choosePrice, choose;
	 int id = 0;
	 double price = 0;

	 while (true)
	 {
		 ShowStorage(2);
		 std::cout << "Введите ID товара или \"exit\" для выхода \nВвод: ";
		 Getline(chooseId);
		 if (chooseId == "exit")
		 {
			 std::cout << "Завернешине операции изменения цен\n\n";
			 Sleep(1500);
			 break;
		 }
		 else if (IsNumber(chooseId))
		 {
			 id = std::stod(chooseId) - 1;
			 if (id < 0 || id > size - 1)
			 {
				 Err();
			 }
			 else
			 {
				 std::cout << "Введите новую цену товара: ";
				 Getline(choosePrice);
				 if (IsNumber(choosePrice))
				 {
					 price = std::stod(choosePrice);
					 if (price < 0 || price > maxPrice)
					 {
						 std::cout << "Некорректная цена! Максимально возможная цена: "
							 << maxPrice << " рублей\n\n";
						 Sleep(3000);
					 }
					 else
					 {
						 while (true)
						 {
							 std::cout << nameArr[id] << "\t" << priceArr[id] << "------> "
								 << price << "\n\n";
							 std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВвод: ";
							 Getline(choose);
							 if (choose == "1")
							 {
								 std::cout << "Успешное изменение цены\n";
								 priceArr[id] = price;
								
								 Sleep(1500);
								 break;
							 }
							 else if (choose == "2")
							 {
								 std::cout << "Отмена изменения цены " << priceArr[id] << "\n";
								 Sleep(1500);
								 break;
							 }
							 else
							 {
								 Err(1);
							 }
						 }

					 }

				 }


			 }

		 }


	 }
 }
 
 void ChangeStorage()
 {
	 std::string choose;
	 while (true)
	 {
		 system("cls");
		 std::cout << "1 - Добавить новый товар\n";
		 std::cout << "2 - Изменить название товара\n";
		 std::cout << "3 - Удалить товар\n";
		 std::cout << "4 - Изминить лимиты склада\n";
		 std::cout << "0 - Выход\n";
		 std::cout << "Ввод: ";
		 Getline(choose);
		 if (choose == "1")
		 {
			 AddNewItem();
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

 void AddNewItem()
 {
	 
	 std::string choose, chooseName, choosePrice, chooseCount;
	 double price = 0;
     unsigned int count = 0;
	 bool isExit = true, isSame = false;
	 while (true)
	 {
		 isExit = true;
		 while (true)
		 {
			 system("cls");
			 isSame = false;
			 std::cout << "Введите название нового товара или \"exit\" для выхода \nВвод: ";
			 Getline(chooseName);
			 if (chooseName == "exit")
			 {
				 std::cout << "отмена создания нового товара\n";
				 isExit = false;
				 Sleep(1500);
			 }
			 
			 if (chooseName.size() < 1 || chooseName.size() > 60)
			 {
					 std::cout << "Ошибка длины названия товара\n";
					 Sleep(1500);
					 continue;
			 }

			 for (size_t i = 0; i < size; i++)
			 {
				 if (chooseName == nameArr[i])
				 {
					 std::cout << "Такой товар уже есть на складе\n";
					 isSame = true;
					 Sleep(1500);
					 break;
				 }

			 }

			 if (isSame)
			 {
				 continue;
			 }

			 else 
			 {
				 break;
			 }
		 }

		 while (isExit)
		 {
			 system("cls");
			 std::cout << "Введите количество товара или \"exit\" для выхода \nВвод: ";
			 Getline(chooseCount);
			 if (chooseName == "exit")
			 {
				 std::cout << "отмена создания количества товара\n";
				 isExit = false;
				 Sleep(1500);
				 break;
			 }
			 if (IsNumber(chooseCount))
			 {
				 count = std::stoi(chooseCount);
				 if (count < 0 || count > maxStorageSize - currentStorageSize)
				 {
					 std::cout << "Ошибка! наскладе осталось " << maxStorageSize - currentStorageSize << "мест\n\n";
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

