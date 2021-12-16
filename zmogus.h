#pragma once
#ifndef studentasss
#define studentasss
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

class zmogus {
private:
    string vardas;
    string pavarde;

public:
    zmogus();
    zmogus(const zmogus& kint);

    zmogus& operator=(const zmogus& kint);
   
    string getVardas(); // geteriai
    string getPavarde();
    


    void setVardas(string nvardas); // seteriai
    void setPavarde(string npavarde);
   

    void failo_nuskaitymasvp(std::ifstream& skaitymas);
   virtual void abstr() = 0;

   ~zmogus(); 

};



#endif