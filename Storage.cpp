#include "Storage.hpp"




 size_t size = 0;
 unsigned int* idArr = nullptr;
 std::string* nameArr = nullptr;
 unsigned int* countArr = nullptr;
 double* priceArr = nullptr;
 bool isStorageCreated = false;
 unsigned int maxStorageSize = 3000;
 unsigned int currentStorageSize = 0;


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


 


