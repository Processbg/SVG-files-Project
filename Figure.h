#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <fstream>
#include "Vector.h"

class Figure
{
public:

	Figure() {}
	virtual ~Figure() {}

	virtual void print() = 0;
	virtual void create() = 0;
	virtual bool withIn(double,double) = 0;
	virtual void erase(int) = 0;
	virtual void translate(const Vector&) = 0;

	virtual Figure* clone() const = 0;
	virtual double getHorizontalCoord() = 0;
	virtual double getVerticalCoord() = 0;
	virtual void writeFigureInFile(const char*) = 0;
};

#endif // !_FIGURE_H_

