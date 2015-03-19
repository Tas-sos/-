#include <iostream>
#include "g_lts_team_lib.h"

using namespace std;



int main (void)
{


Graph a;
//cout << "Οκ δημιουργήθηκε το αντικείμενο." << endl;


a.eisagogi_korifis("tassos");
//cout << "Oκ, πρόσθεσα όνομα στο struct που περιέχει το αντικείμενο" << endl;
a.eisagogi_korifis("Aris");


//cout << "Προσθήκη τιμών στο struct του αντικειμένου." << endl;
a.sindesi_korifis_me_tin_korifi("tassos","a");
a.sindesi_korifis_me_tin_korifi("tassos","b");
a.sindesi_korifis_me_tin_korifi("tassos","c");

a.sindesi_korifis_me_tin_korifi("Aris","G-lts Team");
a.sindesi_korifis_me_tin_korifi("Aris","Aris Sec Network");

//cout << "Εμφάνιση τιμών του vector του struct που έχει το αντικείμενο." << endl;
a.print();

a.write_to_file();




return 0;
}





