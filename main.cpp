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

int epilogi;

cout << "Θέλετε να δημιουργήσετε εσείς τον γράφο ή να τον φορτώσετε από κάποιο αρχείο;" << endl;
cout << "1. Θέλω να δημιουργήσω εγώ τους κόμβους και τις συνδέσεις τους." << endl;
cout << "2. Φόρτωση γράφου από αρχείο." << endl;
cout << "3. Έξοδος." << endl;
cout << "Επιλογή : "; cin >> epilogi;

if ( epilogi == 1 )
{

	a.eisagogi_korifis("1");
	//cout << "Oκ, πρόσθεσα όνομα στο struct που περιέχει το αντικείμενο" << endl;
	a.eisagogi_korifis("2");


	a.sindesi_korifis_me_tin_korifi("1","3");
	a.sindesi_korifis_me_tin_korifi("1","2");


	a.sindesi_korifis_me_tin_korifi("2","5");
	a.sindesi_korifis_me_tin_korifi("2","4");
	a.sindesi_korifis_me_tin_korifi("4","34");

	a.eisagogi_korifis("5");

	a.sindesi_korifis_me_tin_korifi("5", "444");
	a.sindesi_korifis_me_tin_korifi("5", "888");

	cout << "Εμφάνιση τιμών στο vector του struct που έχει το αντικείμενο |=>" << endl;
	a.print();





	cout << "Θέλετε να αποθηκεύσετε το γράφο σε ένα αρχείο;" << endl;
	cout << "1. Ναι." << endl;
	cout << "2. Όχι." << endl;
	cout << "Επιλογή : "; cin >> epilogi;
	if ( epilogi == 1 )
	{
		a.write_to_file();
		cout << "Ο γράφος αποθηκεύτηκε στα αρχεία." << endl;
	}

}


else if ( epilogi == 2 )
{
	a.read_from_file();
	a.print();
}

else
	cout << "Bey bey Love.. :D " << endl;









return 0;
}
