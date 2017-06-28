#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Figure.h"
#include "FigureContainer.h"

class Command 
{
public:

	bool open();
	void save();
	void saveAs(const char*);
	void close();
	bool exit(const char*);

	void erase(int);
	void print();
	void translate(int, double, double);
	void withIn(int,double,double);
	void create(const char*);

private:

	double charToInt(char);

	FigureContainer container;
};

#endif // !_COMMAND_H_

