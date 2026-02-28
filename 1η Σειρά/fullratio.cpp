#include <iostream>
#ifndef CONTEST
#include "fullratio.hpp"
#endif

using namespace std;

rational::rational(int n, int d) {
    nom = n;
    den = d; 
}

rational operator+(const rational &x, const rational &y) {
    int new_nom = x.nom * y.den + y.nom * x.den;
    int new_den = x.den * y.den;

    return rational(new_nom, new_den);
}

rational operator-(const rational &x, const rational &y) {
    int new_nom = x.nom * y.den - y.nom * x.den;
    int new_den = x.den * y.den;

    return rational(new_nom, new_den);
}

rational operator*(const rational &x, const rational &y) {
    int new_nom = x.nom * y.nom;
    int new_den = x.den * y.den;

    return rational(new_nom, new_den);
}

rational operator/(const rational &x, const rational &y) {
    int new_nom = x.nom * y.den;
    int new_den = x.den * y.nom;

    return rational(new_nom, new_den);
}

ostream &operator<<(ostream &out, const rational &x) {
    out << x.nom/rational::gcd(x.nom, x.den);
    if (x.den != 1)
        out << "/" << x.den/rational::gcd(x.nom, x.den);

    return out;
}

int rational::gcd(int a, int b) {
    while (a > 0 && b > 0)
        if (a > b) a = a % b; else b = b % a;
    return a+b;
}