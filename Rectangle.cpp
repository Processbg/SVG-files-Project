#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle() : Figure()
{
	this->xCoordinate = 0;
	this->yCoordinate = 0;

	this->height = 0;
	this->width = 0;
}

Rectangle::Rectangle(double xCoord, double yCoord, double width, double height) : Figure()
{
	this->xCoordinate = xCoord;
	this->yCoordinate = yCoord;

	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(const Rectangle& other)
{
	copyElements(other);
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this != &other)
	{
		copyElements(other);
	}

	return *this;
}

void Rectangle::copyElements(const Rectangle& other)
{
	this->xCoordinate = other.xCoordinate;
	this->yCoordinate = other.yCoordinate;

	this->height = other.height;
	this->width = other.width;
}

void Rectangle::create()
{
	std::cin >> this->xCoordinate >> this->yCoordinate >> this->width >> this->height;
}

void Rectangle::translate(const Vector& movingVector)
{
	this->xCoordinate += movingVector.getX();
	this->yCoordinate += movingVector.getY();
}

bool Rectangle::withIn(double xCoord , double yCoord)
{
	if(xCoord >= this->xCoordinate && xCoord <= this->xCoordinate + this ->width && 
		yCoord >= this->yCoordinate && yCoord <= this->yCoordinate + height)
	{
		return true;
	}

	return false;
}

void Rectangle::erase(int index)
{
	std::cout << "erased rectangle (" << index << ")" << std::endl;
}

void Rectangle::print()
{
	std::cout << "rectangle " <<
		"x: " << this->xCoordinate <<
		" y: " << this->yCoordinate <<
		" width: " << this->width <<
		" height: " << this->height <<
		std::endl;
}

Figure* Rectangle::clone() const
{
	return new Rectangle(*this);
}

double Rectangle::getHorizontalCoord()
{
	if (this->xCoordinate > (this->xCoordinate + this->width))
	{
		return this->xCoordinate;
	}
	else if ((this->xCoordinate + this->width) > this->xCoordinate)
	{
		return this->xCoordinate + this->width;
	}

	return this->xCoordinate;
}

double Rectangle::getVerticalCoord()
{
	if (this->yCoordinate > (this->yCoordinate + this->height))
	{
		return this->yCoordinate;
	}
	else if ((this->yCoordinate + this->height) > this->yCoordinate)
	{
		return this->yCoordinate + this->height;
	}

	return this->yCoordinate;
}

void Rectangle::writeFigureInFile(const char* fileName)
{
	std::ofstream file(fileName, std::ios::out | std::ios::app);
	if (!file)
	{
		std::cerr << "There is a problem with file!" << std::endl;
		return;
	}

	if (file.good())
	{
		double width = getHorizontalCoord();
		double height = getVerticalCoord();

		file << "<svg width=\"" << width << "cm\" height=\"" << height << "cm\" viewBox=\"0 0 1200 400\"" << "\n" <<
			"	xm1ns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << "\n";

		file.seekp(file.tellp(), file.beg);
		file <<
			" <rect x=\"" << this->xCoordinate <<
			"\" y=\"" << this->yCoordinate <<
			"\" width=\"" << this->width << 
			"\ height=\"" << this->height << "\" />"<< "\n";
	}
}