#ifndef _VECTOR_H_
#define _VECTOR_H_

class Vector
{
public:
	
	Vector();
	Vector(double, double);
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	~Vector() {};

	double getX() const;
	double getY() const;

private:
	
	void copyElements(const Vector&);

	double xCoordinate;
	double yCoordinate;
};

#endif
