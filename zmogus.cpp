#include "zmogus.h"

zmogus::zmogus() {}
zmogus::zmogus(const zmogus& kint) {
    *this = kint;
} 
zmogus& zmogus::operator=(const zmogus& kint) {
   
    vardas = kint.vardas;
    pavarde = kint.pavarde;
    
    return *this; }

string zmogus:: getVardas() { return vardas; }
string zmogus::getPavarde() { return pavarde; }

void zmogus::setVardas(string nvardas) { vardas = nvardas; }
void zmogus::setPavarde(string npavarde) { pavarde = npavarde; }

void zmogus::failo_nuskaitymasvp(std::ifstream& skaitymas) {
    skaitymas >> vardas; skaitymas >> pavarde;
}

zmogus::~zmogus() {}


