#include <iostream>
#include "FigureContainer.h"

FigureContainer::FigureContainer()
{
	this->regionOfFigures = nullptr;
	this->capacity = 0;
	this->size = 0;
}

FigureContainer::FigureContainer(const FigureContainer& other)
{
	this->regionOfFigures = nullptr;
	copyElements(other);
}

FigureContainer& FigureContainer::operator=(const FigureContainer& other)
{
	if(this != &other)
	{
		deleteElements();
		copyElements(other);
	}

	return *this;
}

FigureContainer::~FigureContainer()
{
	deleteElements();
}

void FigureContainer::deleteElements()
{
	for (int i = 0; i < this->size; i++)
	{
		delete this->regionOfFigures[i];
	}

	delete[] this->regionOfFigures;
}

void FigureContainer::copyElements(const FigureContainer& other)
{
	this->capacity = other.capacity;
	this->size = other.size;

	delete[] this->regionOfFigures;

	this->regionOfFigures = new(std::nothrow) Figure*[this->size];
	if (!this->regionOfFigures)
	{
		std::cerr << "Can't allocate memory!" << std::endl;
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		this->regionOfFigures[i] = other.regionOfFigures[i]->clone();
	}
}

void FigureContainer::reSize(int newSize)
{
	Figure** temperaryRegion = new(std::nothrow) Figure*[newSize];
	if (!temperaryRegion)
	{
		std::cerr << "Can't allocate memory!" << std::endl;
		return;
	}

	for (int i = 0; i < this->size; i++)
	{
		temperaryRegion[i] = this->regionOfFigures[i];
	}
	
	delete[] regionOfFigures;

	this->regionOfFigures = temperaryRegion;
	temperaryRegion = nullptr;

	this->capacity = newSize;
}

void FigureContainer::putFigureInRegion(Figure* figureToPutInRegion)
{
	if (this->capacity == 0)
	{
		reSize(1);
	}
	else if (this->capacity >= this->size)
	{
		reSize(this->capacity * 2);
	}

	this->regionOfFigures[this->size] = figureToPutInRegion;
	++this->size;
}

void FigureContainer::removeFigureFromRegion(int index)
{
	if (this->size == 0)
	{
		return;
	}

	for (int i = index; i < this->size; i++)
	{
		this->regionOfFigures[i] = nullptr;
		if(i == this->size - 1)
		{
			--this->size;
			break;
		}
		this->regionOfFigures[i] = this->regionOfFigures[i + 1];
	}

	if (this->size == 0)
	{
		deleteElements();
		this->regionOfFigures = nullptr;
		this->capacity = 0;
	}
	else if (this->size <= this->capacity / 4)
	{
		reSize(this->capacity / 2);
	}

}

void FigureContainer::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << i << ". ";
		this->regionOfFigures[i]->print();
	}
}

int FigureContainer::getSize()
{
	return this->size;
}

void FigureContainer::deleteAtIndex(int index)
{
	this->regionOfFigures[index]->erase(index);

	delete this->regionOfFigures[index];	
	removeFigureFromRegion(index);
}

void FigureContainer::translateAtIndex(int index, const Vector& movingVector)
{	
	this->regionOfFigures[index]->translate(movingVector);
	this->regionOfFigures[index]->print();
}

bool FigureContainer::whitInAtIndex(int index, double xCoord, double yCoord)
{
	this->regionOfFigures[index]->print();
	return this->regionOfFigures[index]->withIn(xCoord, yCoord);
}

double FigureContainer::biggestHorizontalCoord()
{
	double biggestCoord = 0.0;

	for (int i = 0; i < this->size; i++)
	{
		if(biggestCoord <= this->regionOfFigures[i]->getHorizontalCoord())
		{
			biggestCoord = this->regionOfFigures[i]->getHorizontalCoord();
		}
	}

	return biggestCoord;
}

double FigureContainer::biggestVerticalCoord()
{
	double biggestCoord = 0.0;

	for (int i = 0; i < this->size; i++)
	{
		if (biggestCoord <= this->regionOfFigures[i]->getVerticalCoord())
		{
			biggestCoord = this->regionOfFigures[i]->getVerticalCoord();
		}
	}

	return biggestCoord;
}

void FigureContainer::saveInFile()
{
	for (int i = 0; i < this->size; i++)
	{
		this->regionOfFigures[i]->writeFigureInFile("SvgFile.svg");
	}
}

void FigureContainer::saveAsInDirectory(const char* directory)
{
	for (int i = 0; i < this->size; i++)
	{
		this->regionOfFigures[i]->writeFigureInFile(directory);
	}
}