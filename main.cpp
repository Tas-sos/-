/*
 * main.cpp
 *
 *  Created on: 29 Μαρ 2015
 *      Author: learn-hack
 */



#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;



int main (void)
{


Graph a;
//cout << "Οκ δημιουργήθηκε το αντικείμενο." << endl;


a.eisagogi_korifis("1");
//cout << "Oκ, πρόσθεσα όνομα στο struct που περιέχει το αντικείμενο" << endl;
a.eisagogi_korifis("2");


//cout << "Προσθήκη τιμών στο struct του αντικειμένου." << endl;
a.sindesi_korifis_me_tin_korifi("1","3");
a.sindesi_korifis_me_tin_korifi("1","2");

a.sindesi_korifis_me_tin_korifi("2","5");
a.sindesi_korifis_me_tin_korifi("2","4");

//cout << "Εμφάνιση τιμών του vector του struct που έχει το αντικείμενο." << endl;
a.print();

a.write_to_file();




return 0;
}
