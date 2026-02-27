#ifndef CONTEST
#include "babyratio.hpp"
#endif
#include <iostream>

using namespace std;

rational::rational(int n, int d) {
    nom = n;
    den = d; 
}

rational rational::add(rational r) {
    int new_nom = nom * r.den + r.nom * den;
    int new_den = den * r.den;

    return rational(new_nom, new_den);
}

rational rational::sub(rational r) {
    int new_nom = nom * r.den - r.nom * den;
    int new_den = den * r.den;

    return rational(new_nom, new_den);
}

rational rational::mul(rational r) {
    int new_nom = nom * r.nom;
    int new_den = den * r.den;

    return rational(new_nom, new_den);
}

rational rational::div(rational r) {
    int new_nom = nom * r.den;
    int new_den = den * r.nom;

    return rational(new_nom, new_den);
}

void rational::print() {
    cout << nom/gcd(nom, den);
    if (den != 1)
        cout << "/" << den/gcd(nom, den);
    cout << endl;
}

int rational::gcd(int a, int b) {
    while (a > 0 && b > 0)
        if (a > b) a = a % b; else b = b % a;
    return a+b;
}

