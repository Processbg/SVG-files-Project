#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Figure.h"

class Rectangle : public Figure
{
public:

	Rectangle();
	Rectangle(double, double, double, double);
	Rectangle(const Rectangle&);
	Rectangle& operator=(const Rectangle&);
	~Rectangle() {};

	void print() override;
	void create() override;
	void erase(int) override;
	bool withIn(double, double) override;
	void translate(const Vector&) override;
	Figure* clone() const override;
	double getHorizontalCoord() override;
	double getVerticalCoord() override;
	void writeFigureInFile(const char*) override;

private:

	void copyElements(const Rectangle&);

	double xCoordinate;
	double yCoordinate;
	double width;
	double height;
};

#endif // !_RECTANGLE_H_

