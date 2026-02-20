#include "Sellings.hpp"
 size_t checkSize = 0;
 unsigned int* idArrCheck;
 std::string* nameArrCheck;
 unsigned int* countArrCheck;
 double* priceArrCheck;
 double* totalPriceArrCheck;

 double cashIncome = 0.0;
 double nonCashIncome = 0.0;
 double cashBox = rand() % 30000 + 25000;


void Sellings()
{
	std::string choose, chooseId, chooseCount, chooseCash;
	int id = 0, count;
	double totalSum = 0.0;
	checkSize = 0;

	while (true)
	{
		ShowStorage();
		std::cout << "\n Введите ID товара для покупки или \"exit\" для выхода \nВвод: ";
		Getline(chooseId);
		if (chooseId == "exit")
		{
			//продажа

		}

		if(IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > size)
			{
				std::cout << "Ошибка ID\n";
				Sleep(1500);
				continue;
			}

		}
		else
		{
			continue;
		}

		std::cout << "\nВведите кол-во товара или \"exit\" для выбора другого товара";
		Getline(chooseCount);
		if (IsNumber(chooseCount))
		{
			count = std::stoi(chooseCount) - 1;
			if (count < 1 || count > countArr[id])
			{
				std::cout << "Ошибка кол-во. Максимум: " << countArr[id] << "\n";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			continue;
		}
		//TO DO======================================================>

	}



}
