#ifndef _LINE_H_
#define _LINE_H_

#include "Command.h"
#include "Figure.h"

class Line : public Figure
{
public:

	Line();
	Line(double, double, double, double);
	Line(const Line&);
	Line& operator=(const Line&);
	~Line() {};

	void print() override;
	void create() override;
	bool withIn(double, double) override;
	void erase(int) override;
	void translate(const Vector&) override;
	double getHorizontalCoord() override;
	double getVerticalCoord() override;
	Figure*clone() const override;
	void writeFigureInFile(const char*) override;

private:


	void copyElements(const Line&);

	double leftAbcise;
	double leftOrdinate;
	double rightAbcise;
	double rightOrdinate;

};

#endif // !_LINE_H_

