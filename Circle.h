#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Figure.h"

class Circle : public Figure
{
public:

	Circle();
	Circle(double, double, double);
	Circle(const Circle&);
	Circle& operator=(const Circle&);
	~Circle() {};

	void create() override;
	void erase(int) override;
	void print() override;
	bool withIn(double, double) override;
	void translate(const Vector&) override;
	Figure*clone() const override;
	double getHorizontalCoord() override;
	double getVerticalCoord() override;
	void writeFigureInFile(const char*) override;

private:

	void copyElements(const Circle&);

	double centerAbsice;
	double centerOrdinate;
	double radius;
};

#endif // !_CIRCLE_H_

