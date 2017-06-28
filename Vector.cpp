#include <cmath>
#include "Vector.h"

Vector::Vector()
{
	this->xCoordinate = 0;
	this->yCoordinate = 0;
}

Vector::Vector(double x, double y)
{
	this->xCoordinate = x;
	this->yCoordinate = y;
}

Vector::Vector(const Vector& other) 
{
	copyElements(other);
}

Vector& Vector::operator=(const Vector& other) 
{
	if (this != &other) 
	{
		copyElements(other);
	}

	return *this;
}

void Vector::copyElements(const Vector& other) 
{
	this->xCoordinate = other.xCoordinate;
	this->yCoordinate = other.yCoordinate;
}

double Vector::getX() const
{
	return this->xCoordinate;
}

double Vector::getY() const
{
	return this->yCoordinate;
}



