#include "Storage.hpp"




 size_t size = 0;
 unsigned int* idArr = nullptr;
 std::string* nameArr = nullptr;
 unsigned int* countArr = nullptr;
 double* priceArr = nullptr;
 bool isStorageCreated = false;


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
	  }
	 
 }


 void ShowStorage(int mode)
 {
	 if(mode == 0)
	 {
		 std::cout << "ID\t" << std::left << std::setw(40) << "Название товара\t" << "Кол-во\t" << "Цена\t" << "\n";
		 for (size_t i = 0; i < size; i++)
		 {
			 std::cout << idArr[i] << "\t" << std::left << std::setw(20) << nameArr[i] << "\t\t" << countArr[i]
				 << "\t" << priceArr[i] << "\n";
		 }


	 }

 }






 template<typename ArrType>
 inline void FillArray(ArrType* dynamicArr, ArrType* staticArr)
 {
	 for (size_t i = 0; i < size; i++)
	 {
		 dynamicArr[i] = staticArr[i];
	 }

 }


