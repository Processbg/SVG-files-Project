#include <iostream>
#include "Circle.h"

Circle::Circle () : Figure()
{
	this->centerAbsice = 0;
	this->centerOrdinate = 0;
	this->radius = 0;
}

Circle::Circle (double cX, double cY, double radius) : Figure()
{
	this->centerAbsice = cX;
	this->centerOrdinate = cY;
	this->radius = radius;
}

Circle::Circle(const Circle& other)
{
	copyElements(other);
}

Circle& Circle::operator=(const Circle& other)
{
	if (this != &other) 
	{
		copyElements(other);
	}

	return *this;
}

void Circle::copyElements(const Circle& other)
{
	this->centerAbsice = other.centerAbsice;
	this->centerOrdinate = other.centerOrdinate;
	this->radius = other.radius;
}

void Circle::create()
{
	std::cin >> this->centerAbsice >> this->centerOrdinate >> this->radius;
}

void Circle::erase(int index)
{
	std::cout << "Erased circle (" << index << ")" << std::endl;
}

void Circle::translate(const Vector& movingVector)
{
	this->centerAbsice += movingVector.getX();
	this->centerOrdinate += movingVector.getY();
}

bool Circle::withIn(double xCoord, double yCoord)
{ 
	if (xCoord >= this->centerAbsice && xCoord <= this->centerAbsice + this->radius && 
		yCoord >= this->centerOrdinate && yCoord <= this->centerOrdinate + this->radius)
	{
		return true;
	}

	return false;
}

void Circle::print()
{
	std::cout << "circle " <<
		"cx: " << this->centerAbsice <<
		" cy: " << this->centerOrdinate <<
		" r: " << this->radius << 
		std::endl;
}

Figure* Circle::clone() const
{
	return new Circle(*this);
}

double Circle::getHorizontalCoord()
{
	if(this->centerAbsice > (this->centerAbsice + this->radius))
	{
		return this->centerAbsice;
	}
	else if ((this->centerAbsice + this->radius) > this->centerAbsice)
	{
		return this->centerAbsice + this->radius;
	}

	return this->centerAbsice;
}

double Circle::getVerticalCoord()
{
	if (this->centerOrdinate > (this->centerOrdinate + this->radius))
	{
		return this->centerOrdinate;
	}
	else if ((this->centerOrdinate + this->radius) > this->centerOrdinate)
	{
		return this->centerOrdinate + this->radius;
	}

	return this->centerOrdinate;
}

void Circle::writeFigureInFile(const char* fileName)
{
	std::ofstream file(fileName, std::ios::out | std::ios::app);
	if(!file)
	{
		std::cerr << "There is a problem with file!" << std::endl;
		return;
	}

	if(file.good())
	{
		double width = getHorizontalCoord();
		double height = getVerticalCoord();

		file << "<svg width=\"" << width << "cm\" height=\"" << height << "cm\" viewBox=\"0 0 1200 400\"" << "\n" <<
			"	xm1ns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << "\n";

		file.seekp(file.tellp(), file.beg);
		file << 
			" <circle cx=\"" << this->centerAbsice <<
			"\" cy=\"" << this->centerOrdinate << 
			"\" r=\"" << this->radius << "\" />" << "\n"; 
	}
}