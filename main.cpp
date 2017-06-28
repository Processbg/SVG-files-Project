#include <iostream>
#include "Figure.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Command.h"

int main()
{
	int lenght = 200;

	char* name = new(std::nothrow) char[lenght];
	if (!name)
	{
		std::cerr << "Can't allocate memory!" << std::endl;
		return 0;
	}

	Command command;

	bool flag = true;
	while (flag)
	{
		std::cin.getline(name, lenght);
		
		if (!strcmp(name, "Open"))
		{
			if (command.open())
			{
				std::cout << "Sucessfully opened file!" << std::endl;
			}
		}
		else if (!strcmp(name, "Close"))
		{
			command.close();
		}
		else if (!strcmp(name, "Save"))
		{
			command.save();
			std::cout << "Successfully saved changes in file!" << std::endl;
		}
		else if (!strcmp(name, "SaveAs"))
		{
			char* directory = new(std::nothrow) char[20000000];
			if (!directory)
			{
				std::cerr << "Can't allocate memory!" << std::endl;
				flag = false;;
			}
			std::cin.clear();
			std::cin.getline(directory, 20000000);
			command.saveAs(directory);
		}
		else if (command.exit(name))
		{
			flag = false;
		}
		else if (!strcmp(name, "Print"))
		{
			command.print();
		}
		else if (!strcmp(name, "Create"))
		{
			char* figureName = new(std::nothrow) char[15];
			if (!figureName)
			{
				std::cout << "Can't allocate memory!" << std::endl;
				flag = false;
			}
			std::cin.clear();
			std::cin.getline(figureName, 15);

			command.create(figureName);
		}
		else if (!strcmp(name, "Erase"))
		{
			std::cin.clear();
			int index;
			std::cin >> index;

			command.erase(index);
		}
		else if (!strcmp(name, "Translate"))
		{
			std::cin.clear();
			int index;
			std::cin >> index;
			double x, y;
			std::cin >> x >> y;

			command.translate(index, x, y);
		}
		else if(!strcmp(name, "WithIn"))
		{
			char* figureName = new(std::nothrow) char[15];
			if (!figureName)
			{
				std::cout << "Can't allocate memory!" << std::endl;
				flag = false;
			}

			std::cin.clear();
			std::cin.getline(figureName, 15);

			int index;
			std::cin >> index;

			double x, y;
			std::cin >> x >> y;

			if (figureName != nullptr)
			{
				command.withIn(index, x, y);
			}
			else
			{
				command.withIn(-1, x, y);
			}
		}
	}
	
	delete[] name;
	name = nullptr;

	return 0;
}
