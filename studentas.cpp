#include "studentas.h"

studentas::studentas() {}
studentas::studentas(const studentas& kint) :zmogus(kint){ *this = kint; }
studentas& studentas::operator=(const studentas& kint)  {
    zmogus::operator=(kint);
    paz = kint.paz;
    egz = kint.egz;
    gal = kint.gal;

    return *this;
}

const vector<int>& studentas::getPaz() const { return paz; }
double studentas::getGal() const { return gal; }
double studentas::getEgz() const { return egz; }

void studentas::setPaz(vector<int> npaz) { paz = npaz; }
void studentas::setGal(double ngal) { gal = ngal; }
void studentas::setEgz(double negz) { egz = negz; }

void studentas::failo_nuskaitymas(std::ifstream& skaitymas) {
   
    for (auto& p : paz) { skaitymas >> p; }
    skaitymas >> gal;
   

}

studentas::~studentas() {}

void studentas::abstr() {}