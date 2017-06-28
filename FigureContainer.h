#ifndef _FIGURE_CONTAINER_H_
#define _FIGURE_CONTAINER_H_

#include "Figure.h"

class FigureContainer
{
public:

	FigureContainer();
	FigureContainer(const FigureContainer&);
	FigureContainer& operator=(const FigureContainer&);
	~FigureContainer();
	
	void putFigureInRegion(Figure*);
	void removeFigureFromRegion(int);
	void print();
	int getSize();
	void deleteAtIndex(int);
	void translateAtIndex(int, const Vector&);
	bool whitInAtIndex(int, double, double);

	double biggestHorizontalCoord();
	double biggestVerticalCoord();

	void saveInFile();
	void saveAsInDirectory(const char*);

private:

	void deleteElements();
	void copyElements(const FigureContainer&);

	void reSize(int);

	Figure** regionOfFigures;
	int capacity;
	int size;

};

#endif // !_FIGURE_CONTAINER_H_

