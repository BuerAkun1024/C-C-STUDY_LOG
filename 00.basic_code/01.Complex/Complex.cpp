#ifndef _COMPLEX_
#define _COMPLEX_

class complex
{
public:
	complex (double r = 0, double i = 0) // pass by value
	  : re (r), im (i)                   // set initial column
	{ }
	complex& operator += (const complex&); // member function       operation reload
	double real () const { return re;	}  // only read   add const
	double imag () const { return im;	}
private:
	double re, im;
	friend complex& _doapl (complex* , const complex&) ; // friend function do assign pluss 直接去取实部和虚部 just like a friend 
}; 

inline complex& // as an inline function
_doapl(complex* ths, const complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

inline complex& // not local area therefore reference
complex::operator += (const complex& r) // right number only read so add const 
{  
	return _doapl (this,r);
}

// + 没有被设置为成员函数，是因为会涉及到复数加实数的操作。 globle function
inline complex  // return by value
operator + (const complex& x, const complex& y)
{
	return complex (x.real() + y.real(),
	                x.imag() + y.imag() );
} 

inline complex  // return by value
operator + (const complex& x, double y)
{
	return complex (x.real() + y, x.imag() );  // this is contemprary object
} 

inline complex
operator + (double x, const complex& y)
{
	return complex (x + y.real(), y.imag());
}

#endif

#include <iostream>
using namespace std;

ostream&  // agree to continuas input
operator << (ostream& os, const complex& x)  // ostream 是通过查手册获取的， left: change 
{
	return os << '(' << x.real() << ',' << x.imag() << ')';
}

int main(){
	complex c1(9,8);
	complex c2(1,2);
	
	cout << c1 << endl;
	cout << c2 + c1 << endl;
	
	c1 += c2;
	cout << c1 << endl;
	cout << c1 + 7 << endl;
	cout << 1 + c2 << endl;
	
	return 0;
}

