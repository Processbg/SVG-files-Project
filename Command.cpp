#include <iostream>
#include <fstream>
#include <cstring>
#include "Command.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"


void Command::withIn(int index, double xCoord, double yCoord)
{
	if (index < 0 || index > this->container.getSize())
	{
		std::cerr << "There is no figure number: " << index << std::endl;
		return;
	}

	bool result = this->container.whitInAtIndex(index, xCoord, yCoord);
}

void Command::translate(int index, double vertical, double horizontal)
{
	Vector movingVector(horizontal, vertical);

	if (index <= 0 || index >= this->container.getSize())
	{
		std::cout << "Translated all figures" << index << std::endl;

		for (int i = 0; i < this->container.getSize(); i++)
		{
			this->container.translateAtIndex(i, movingVector);
		}

		return;
	}

	this->container.translateAtIndex(index, movingVector);
}

void Command::create(const char* figureName)
{
	if(!strcmp(figureName, "line"))
	{
		Line createdLine;
		createdLine.create();
		this->container.putFigureInRegion(createdLine.clone());
	}
	else if(!strcmp(figureName,"circle"))
	{
		Circle createdCircle;
		createdCircle.create();
		this->container.putFigureInRegion(createdCircle.clone());
	}
	else if(!strcmp(figureName, "rectangle"))
	{
		Rectangle createdRectnagle;
		createdRectnagle.create();
		this->container.putFigureInRegion(createdRectnagle.clone());
	}
}

void Command::erase(int index)
{
	if(index < 0 || index > this->container.getSize())
	{
		std::cerr << "There is no figure number: " << index << std::endl;
		return;
	}

	this->container.deleteAtIndex(index);
}

void Command::print()
{
	this->container.print();
}

bool Command::open()
{
	std::ifstream file("SvgFile.svg", std::ios::in);
	if (!file.is_open())
	{
		std::ofstream openFile("SvgFile.svg", std::ios::out);
		if (!openFile.is_open())
		{
			std::cerr << "There is a problem with the fail! Fail is either broken or in a different directory!Please check fail directory!" << std::endl;
			return false;
		}
		else if (!openFile)
		{
			std::cerr << "There is a problem with the file!" << std::endl;
			return false;
		}

		if (openFile.good())
		{
			openFile << "<?xml version=\"1.0\" standalone=\"no\"?>" << "\n" <<
				"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << "\n" <<
				"	\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << "\n";

			return true;
		}
	}
	else if (!file)
	{
		std::cerr << "There is a problem with the file!" << std::endl;
		return false;
	}
	else
	{
		if (file.good())
		{
			file.seekg(0, file.end);

			int lenghtOfSvg = file.tellg();

			char* svgString = new(std::nothrow) char[lenghtOfSvg];
			if (!svgString)
			{
				std::cerr << "Can't allocate memory!" << std::endl;
				return false;
			}

			for (int i = 0; i < lenghtOfSvg; i++)
			{
				file >> svgString[i];
				
				char* line = strstr(svgString, "line");
				if (line != nullptr)
				{
					double x1Coord = 0;
					char* leftAbcise = strstr(svgString, "x1=\"");

					if (leftAbcise != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> x1Coord;
					}

					double y1Coord = 0;
					char* leftOrdinate = strstr(svgString, "y1=\"");

					if (leftOrdinate != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> y1Coord;
					}

					double x2Coord = 0;
					char* rightAbcise = strstr(svgString, "x2=\"");

					if (rightAbcise != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> x2Coord;
					}

					double y2Coord = 0;
					char* rightOrdinate = strstr(svgString, "y2=\"");

					if (rightOrdinate != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> y2Coord;
					}

					Line line(x1Coord, y1Coord, x2Coord, y2Coord);
					this->container.putFigureInRegion(line.clone());

				}

				char* circle = strstr(svgString, "circle");
				if (circle != nullptr)
				{
					double cXCoord = 0;
					char* centerAbcise = strstr(svgString, "cx=\"");

					if (centerAbcise != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> cXCoord;
					}

					double cYCoord = 0;
					char* centerOrdinate = strstr(svgString, "cy=\"");

					if (centerOrdinate != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> cYCoord;
					}

					double r = 0;
					char* radius = strstr(svgString, "r=\"");

					if (radius != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> r;
					}

					Circle circle(cXCoord, cYCoord, r);
					this->container.putFigureInRegion(circle.clone());
				}


				char* rectangle = strstr(svgString, "rect");
				if (rectangle != nullptr)
				{
					double xCoord = 0;
					char* Abcise = strstr(svgString, "x=\"");

					if (Abcise != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> xCoord;
					}

					double yCoord = 0;
					char* Ordinate = strstr(svgString, "cy=\"");

					if (Ordinate != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> yCoord;
					}

					double w = 0;
					char*  width = strstr(svgString, "width=\"");

					if (width != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> w;
					}

					double h = 0;
					char*  height = strstr(svgString, "height=\"");

					if (height != nullptr);
					{
						file.seekg(file.gcount(), file.beg);
						file >> h;
					}

					Rectangle rect(xCoord, yCoord, w, h);
					this->container.putFigureInRegion(rect.clone());
				}
			}
		}
	}
	return true;
}

double Command::charToInt(char a)
{
	double result = a - '0';

	return result;
}

void Command::save()
{
	this->container.saveInFile();
}

void Command::saveAs(const char* directory)
{
	this->container.saveAsInDirectory(directory);
}

void Command::close()
{
	std::ofstream openFile("SvgFile.svg", std::ios::out | std::ios::app);
	if (!openFile)
	{
		std::cerr << "There is a problem with the fail!" << std::endl;
		return;
	}

	if (openFile.good())
	{
		openFile << "</svg>" << "\n";
	}
	
	std::ifstream file("SvgFile.svg", std::ios::in);
	if(!file)
	{
		std::cerr << "There is a problem with the fail!" << std::endl;
		return;
	}
	
	if(file.is_open())
	{
		std::cout << "Succesfully closed file!" << std::endl;
		file.close();
	}
}

bool Command::exit(const char* exit)
{
	if(!strcmp(exit, "Exit"))
	{
		return true;
	}

	return false;
}