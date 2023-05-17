#include <iostream>

class Quard {

protected:

	virtual double area() const = 0;
	void virtual scale(const double);
	void virtual intersect(const Quard& );
	//virtual union(const Quard& );
};


class Rect : public Quard {

protected:

	double len;
	double wid;

public: 
	Rect(double l, double w);
	void scale(const Rect& l, Rect& w);
	void intersect(const Rect& l, const Rect& w);
};


class Square : public Quard {

protected:
	double len;
	double wid;

public:
	Square(double l, double w);
	void scale(const Square& l, Square& w);
	void intersect(const Square&l, const Square& w);
};

int main() {

}
