#include <iostream>
#include "../Account/Account.h"
#include "persoana.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Account cont(50);

    cout<<cont.getBalance()<<endl;
    cont.credit(178);
    cout<<cont.getBalance()<<endl;
    cout << cont;
    cout<<cont.plata()<<endl;
    cout<<cont;
    //Persoana pers;
    //pers.getBalance(200);
    return 0;
}
