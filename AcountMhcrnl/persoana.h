#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED
#include <iostream>
#include <string>
//#include "../Account/Account.h"
using namespace std;
class Persoana {
protected:
    string _nume;
    string _prenume;
public:
    /**
        Constructor
    */
    Persoana();
    /**
        get/set
    */
    string setNume(void);
    string setPrenume(void);
};

#endif // PERSOANA_H_INCLUDED
