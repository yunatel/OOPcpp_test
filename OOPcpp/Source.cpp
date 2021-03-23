#include <iostream>
#include "MyContainer.h"

int main() {
	std::cout << "OOPcpp" << std::endl;
	Container<int> L;
	Container<int> T;
	Container<int> Pop_TEST;
	{ 
		const int n = 10;
		int a[n] = { 0,1,2,3,4,5,6,7,8,9 };
		// Добавляем элементы, стоящие на четных(не четных) индексах, в начало(конец).
		for (auto i = 0; i < n; i++) {
			Pop_TEST.AddTail(a[i]);
			if (i % 2 == 0)
				L.AddHead(a[i]);
			else
				L.AddTail(a[i]);
		}
	}
	// Распечатка списка
	std::cout << "Container L:\n";
	L.Print();
	std::cout<<std::endl;

	std::cout << "Container Pop_TEST:\n";
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "Pop_TEST.Del(1):\n";
	Pop_TEST.Del(1);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;
	
	std::cout << "Pop_TEST.Del(Pop_TEST.GetLenght()):\n";
	Pop_TEST.Del(Pop_TEST.GetLenght());
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 1 2\n";
	Pop_TEST.Swap(1, 2);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 2 1\n";
	Pop_TEST.Swap(2, 1);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 7 8\n";
	Pop_TEST.Swap(7, 8);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 8 7\n";
	Pop_TEST.Swap(8, 7);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 1 8\n";
	Pop_TEST.Swap(1, 8);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 8 1\n";
	Pop_TEST.Swap(8, 1);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 1 5\n";
	Pop_TEST.Swap(1, 5);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 5 1\n";
	Pop_TEST.Swap(5, 1);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 4 8\n";
	Pop_TEST.Swap(4, 8);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;

	std::cout << "swap test 8 4\n";
	Pop_TEST.Swap(8, 4);
	Pop_TEST.Print();	Pop_TEST.PrintRev();
	std::cout << std::endl;


	std::cout << "Pop_TEST.DelAll():\n";
	Pop_TEST.DelAll();
	Pop_TEST.Print();
	Pop_TEST.PrintRev();
	std::cout << std::endl; std::cout << std::endl;


	// Распечатка 2-го и 8-го элементов списка
	L.Print(2);
	L.Print(8);
	std::cout << std::endl; std::cout << std::endl;

	T = L;
	std::cout << "Container T:\n";
	T.Print();
	T.Reverse();
	std::cout << std::endl;

	std::cout << "Container L:\n";
	L.Print();
	std::cout << std::endl;
	std::cout << "Reversed T:\n";
	T.Print();
	std::cout << std::endl;




	system("pause");
	return 0;
}