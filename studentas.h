#pragma once
#include "zmogus.h"

class studentas : public zmogus {
	vector <int> paz;
	double gal;
	double egz;

public:
	studentas();
	studentas(const studentas& kint);
	studentas& operator=(const studentas& kint);

	const vector<int>& getPaz() const; //geteriai
	double getGal() const;
	double getEgz() const;

	void setPaz(vector<int> npaz); // seteriai
	void setGal(double ngal);
	void setEgz(double negz);


	void failo_nuskaitymas(std::ifstream& skaitymas);
	void abstr();


	~studentas();
};

