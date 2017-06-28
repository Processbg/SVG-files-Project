#include <iostream>
#include "Line.h"

Line::Line() : Figure()
{
	this->leftAbcise = 0;
	this->leftOrdinate = 0;
	this->rightAbcise = 0;
	this->rightOrdinate = 0;
}

Line::Line(double leftX, double leftY, double rightX, double rightY) : Figure()
{
	this->leftAbcise = leftX;
	this->leftOrdinate = leftY;

	this->rightAbcise = rightX;
	this->rightOrdinate = rightY;
}

Line::Line(const Line& other)
{
	copyElements(other);
}

Line& Line::operator=(const Line& other)
{
	if(this != &other)
	{
		copyElements(other);
	}

	return *this;
}

void Line::copyElements(const Line& other)
{
	this->leftAbcise = other.leftAbcise;
	this->leftOrdinate = other.leftOrdinate;
	this->rightAbcise = other.rightAbcise;
	this->rightOrdinate = other.rightOrdinate;
}

void Line::print()
{
	std::cout << "line " 
		<< "x1 = " << this->leftAbcise 
		<< " y1 = " << this->leftOrdinate 
		<< " x2 = " << this->rightAbcise 
		<< " y2 = " << this->rightOrdinate << std::endl;
}

void Line::create()
{
	std::cin >> this->leftAbcise >> this->leftOrdinate >> this->rightAbcise >> this->rightOrdinate;
}

bool Line::withIn(double xCoord, double yCoord)
{
	if(xCoord >= this->leftAbcise && xCoord <= this->rightAbcise && 
		yCoord >= this->leftOrdinate && yCoord <= this->rightOrdinate)
	{
		return true;
	}

	return false;
}

void Line::translate(const Vector& movingVector)
{
	this->leftAbcise += movingVector.getX();
	this->leftOrdinate += movingVector.getY();

	this->rightAbcise += movingVector.getX();
	this->rightOrdinate += movingVector.getY();
}

void Line::erase(int index)
{
	std::cout << "erased line (" << index << ")" << std::endl;
}

Figure* Line::clone() const
{
	return new Line(*this);
}

double Line::getHorizontalCoord()
{
	if (this->leftAbcise > this->rightAbcise)
	{
		return this->leftAbcise;
	}
	else if (this->rightAbcise > this->leftAbcise)
	{
		return this->rightAbcise;
	}

	return this->leftAbcise;
}

double Line::getVerticalCoord()
{

	if (this->leftOrdinate > this->rightOrdinate)
	{
		return this->leftOrdinate;
	}
	else if (this->rightOrdinate > this->leftOrdinate)
	{
		return this->rightOrdinate;
	}

	return this->leftOrdinate;
}

void Line::writeFigureInFile(const char* fileName)
{
	std::ofstream file(fileName, std::ios::out, std::ios::app);
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
			" <rect x1=\"" << this->leftAbcise <<
			"\" y1=\"" << this->leftOrdinate <<
			"\" x2=\"" << this->rightAbcise << 
			"\ y2=\"" << this->rightOrdinate << "\" />" << "\n";
	}
}