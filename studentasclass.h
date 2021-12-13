#pragma once
#ifndef v1_1
#define v1_1
#include <iostream>
#include <iomanip>
#include <string>
#include<cmath>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include<chrono> 
#include <random>
#include<list>
#include<deque>

using std::string;
using std::vector;
using std::list;
using std::deque;

class studentas {
private:
    string vardas;
    string pavarde;
    vector<double> paz;
    double egz;
    float gal;

public:
    studentas() : egz(0), vardas(" "), pavarde(" "), paz(5), gal(0) {}

    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    inline vector<double> getPaz() const { return paz; }// geteriai
    inline double getEgz() const { return egz; }
    inline float getGal() const { return gal; }


    inline void setVardas(string nvardas) { vardas = nvardas; } // seteriai
    inline void setPavarde(string npavarde) { pavarde = npavarde; }
    inline void setPaz(vector<double> npaz) { paz = npaz; }
    inline void setEgz(double negz) { egz = negz; }
    inline void setGal(float ngal) { gal = ngal; }


    void failo_nuskaitymas(std::ifstream& skaitymas) {
        skaitymas >> vardas; skaitymas >> pavarde;
        for (auto& p : paz) { skaitymas >> p; }
        skaitymas >> gal;

    }
    ~studentas() {}

};




void failo_skaitymas(list<studentas>& kint, int kiek);
void failo_skaitymas(deque<studentas>& kint, int kiek);
void failo_skaitymas(vector<studentas>& kint, int kiek);

#endif