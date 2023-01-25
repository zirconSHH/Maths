#pragma once
#include <iostream>
using namespace std;

class complex
{
public:
	complex(double a = 0, double b = 0) :re(a), im(b) {};

	//print
	void print_complex() const;

	//get complex
	double get_re() const;
	double get_im() const;

	//chanege complex
	void change_re(double target);
	void change_im(double target);
	void change_complex(double a = 0,double b = 0);

	//operate
	complex& operator+= (const complex& c);
	complex& operator-= (const complex& c);
	complex& operator*= (const complex& c);
	complex& operator/= (const complex& c);

	complex conjunction();
	

private:
	double re;//Êµ²¿
	double im;//Ðé²¿

};

double get_re(const complex& c);
double get_im(const complex& c);

complex conjunction(const complex& c);

//reload +
complex operator+ (const complex& c);
complex operator+ (const complex& c1, const complex& c2);
complex operator+ (const complex& c, const double& d);
complex operator+ (const double& d, const complex& c);

//reload -
complex operator- (const complex& c);
complex operator- (const complex& c1, const complex& c2);
complex operator- (const complex& c, const double& d);
complex operator- (const double& d, const complex& c);

//reload ==
bool operator== (const complex& c1, const complex& c2);
bool operator== (const double& d, const complex& c);
bool operator== (const complex& c, const double& d);

//reload *
complex operator* (const complex& c1, const complex& c2);
complex operator* (const complex& c, const double& d);
complex operator* (const double d, const complex& c);

//reload /
complex operator/ (const complex& c1, const complex& c2);
complex operator/ (const complex& c, const double& d);
complex operator/ (const double& d, const complex& c);

//reload <<
ostream& operator<< (ostream& os, const complex& c);