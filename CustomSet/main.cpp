#include <iostream>
#include <string>
#include "Set.h"

int main()
{
	Set<std::string> names;
	std::cout << "Adding the following names: Jack, Emily, Johnson, Johnson(duplicate), Richard, Venessa" << std::endl;
	names.insert("Jack");
	names.insert("Emily");
	names.insert("Johnson");
	names.insert("Johnson");
	names.insert("Richard");
	names.insert("Venessa");

	for (Set<std::string>::iterator i = names.begin(); i != names.end(); i++)
	{
		std::cout << *i << " ";
	}

	std::cout << "\nRemoving Richard..." << std::endl;
	names.remove("Richard");

	for (Set<std::string>::iterator i = names.begin(); i != names.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << "\n" << std::endl;
	Set<int> numbers;
	std::cout << "Adding the following numbers: 50, 14, 20, 20(duplicate), 44" << std::endl;
	numbers.insert(50);
	numbers.insert(14);
	numbers.insert(20);
	numbers.insert(20);
	numbers.insert(44);

	for (Set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "Inserting 5 and 14 and Removing 44" << std::endl;
	numbers.insert(5);
	numbers.insert(14);
	numbers.remove(44);

	for (Set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << "\t";
	}

	std::cin.get();
	return 0;
}