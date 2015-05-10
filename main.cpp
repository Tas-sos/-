/*
 * main.cpp
 *
 *      Author: Tas-sos
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
cout << "3. BFS." << endl;
cout << "4. DFS." << endl;
cout << "5. Έξοδος." << endl;
cout << "Επιλογή : "; cin >> epilogi;


while (epilogi != 5)
{

	if ( epilogi == 1 )
	{

		// Πρώτα θα προσθέσω όλες τις πόλλεις.
		a.eisagogi_korifis("Drobeta");
		a.eisagogi_korifis("Mehadia");
		a.eisagogi_korifis("Lugoj");
		a.eisagogi_korifis("Timisoara");
		a.eisagogi_korifis("Arad");
		a.eisagogi_korifis("Zerind");
		a.eisagogi_korifis("Oradea");
		a.eisagogi_korifis("Sibiu");
		a.eisagogi_korifis("Rimnicu Vilcea");
		a.eisagogi_korifis("Craiova");
		a.eisagogi_korifis("Pitesti");
		a.eisagogi_korifis("Fagaras");
		a.eisagogi_korifis("Bucharest");
		a.eisagogi_korifis("Giurgiu");
		a.eisagogi_korifis("Urzieeni");
		a.eisagogi_korifis("Hirsova");
		a.eisagogi_korifis("Eforie");
		a.eisagogi_korifis("Vaslui");
		a.eisagogi_korifis("Iasi");
		a.eisagogi_korifis("Neamt");
		a.eisagogi_korifis("Mehadia");


		// Έπειτα θα συνδέσω τις πόλοις μια μια μεταξύ τους.

		a.sindesi_korifis_me_tin_korifi("Drobeta","Mehadia");
		a.sindesi_korifis_me_tin_korifi("Drobeta","Craiova");

		a.sindesi_korifis_me_tin_korifi("Mehadia","Drobeta");
		a.sindesi_korifis_me_tin_korifi("Mehadia","Lugoj");

		a.sindesi_korifis_me_tin_korifi("Lugoj","Mehadia");
		a.sindesi_korifis_me_tin_korifi("Lugoj","Timisoara");

		a.sindesi_korifis_me_tin_korifi("Timisoara","Lugoj");
		a.sindesi_korifis_me_tin_korifi("Timisoara","Arad");

		a.sindesi_korifis_me_tin_korifi("Arad","Timisoara");
		a.sindesi_korifis_me_tin_korifi("Arad","Sibiu");
		a.sindesi_korifis_me_tin_korifi("Arad","Zerind");

		a.sindesi_korifis_me_tin_korifi("Zerind","Oradea");
		a.sindesi_korifis_me_tin_korifi("Zerind","Arad");

		a.sindesi_korifis_me_tin_korifi("Oradea","Zerind");
		a.sindesi_korifis_me_tin_korifi("Oradea","Sibiu");

		a.sindesi_korifis_me_tin_korifi("Sibiu","Oradea");
		a.sindesi_korifis_me_tin_korifi("Sibiu","Fagaras");
		a.sindesi_korifis_me_tin_korifi("Sibiu","Rimnicu Vilcea");

		a.sindesi_korifis_me_tin_korifi("Rimnicu Vilcea","Sibiu");
		a.sindesi_korifis_me_tin_korifi("Rimnicu Vilcea","Pitesti");
		a.sindesi_korifis_me_tin_korifi("Rimnicu Vilcea","Craiova");

		a.sindesi_korifis_me_tin_korifi("Craiova","Rimnicu Vilcea");
		a.sindesi_korifis_me_tin_korifi("Craiova","Drobeta");
		a.sindesi_korifis_me_tin_korifi("Craiova","Pitesti");

		a.sindesi_korifis_me_tin_korifi("Pitesti","Rimnicu Vilcea");
		a.sindesi_korifis_me_tin_korifi("Pitesti","Craiova");
		a.sindesi_korifis_me_tin_korifi("Pitesti","Bucharest");

		a.sindesi_korifis_me_tin_korifi("Fagaras","Sibiu");
		a.sindesi_korifis_me_tin_korifi("Fagaras","Bucharest");

		a.sindesi_korifis_me_tin_korifi("Bucharest","Fagaras");
		a.sindesi_korifis_me_tin_korifi("Bucharest","Pitesti");
		a.sindesi_korifis_me_tin_korifi("Bucharest","Giurgiu");
		a.sindesi_korifis_me_tin_korifi("Bucharest","Urzieeni");

		a.sindesi_korifis_me_tin_korifi("Urzieeni","Bucharest");
		a.sindesi_korifis_me_tin_korifi("Urzieeni","Hirsova");
		a.sindesi_korifis_me_tin_korifi("Urzieeni","Vaslui");

		a.sindesi_korifis_me_tin_korifi("Hirsova","Urzieeni");
		a.sindesi_korifis_me_tin_korifi("Hirsova","Eforie");

		a.sindesi_korifis_me_tin_korifi("Eforie","Hirsova");

		a.sindesi_korifis_me_tin_korifi("Vaslui","Urzieeni");
		a.sindesi_korifis_me_tin_korifi("Vaslui","Iasi");

		a.sindesi_korifis_me_tin_korifi("Iasi","Vaslui");
		a.sindesi_korifis_me_tin_korifi("Iasi","Neamt");

		a.sindesi_korifis_me_tin_korifi("Neamt","Iasi");

		// Ένας μιρκός γράφος για πειραματισμούς :
//		a.eisagogi_korifis("A");
//		a.eisagogi_korifis("B");
//		a.eisagogi_korifis("D");
//		a.eisagogi_korifis("C");
//		a.eisagogi_korifis("E");
//		a.eisagogi_korifis("F");
//		a.eisagogi_korifis("G");
//
//		a.sindesi_korifis_me_tin_korifi("A","B");
//		a.sindesi_korifis_me_tin_korifi("A","D");
//
//		a.sindesi_korifis_me_tin_korifi("B","A");
//		a.sindesi_korifis_me_tin_korifi("B","E");
//		a.sindesi_korifis_me_tin_korifi("B","C");
//
//		a.sindesi_korifis_me_tin_korifi("E","B");
//		a.sindesi_korifis_me_tin_korifi("E","F");
//
//		a.sindesi_korifis_me_tin_korifi("D","A");
//		a.sindesi_korifis_me_tin_korifi("D","F");
//		a.sindesi_korifis_me_tin_korifi("D","C");
//
//		a.sindesi_korifis_me_tin_korifi("F","D");
//		a.sindesi_korifis_me_tin_korifi("F","E");
//		a.sindesi_korifis_me_tin_korifi("F","G");
//
//		a.sindesi_korifis_me_tin_korifi("G","F");


		a.Taksinomisis_ton_sindeseon_olou_tou_grafou();
		cout << "Εμφάνιση τιμών στο vector του struct που έχει το αντικείμενο |=>" << endl;
		a.print();





//		cout << "Θέλετε να αποθηκεύσετε το γράφο σε ένα αρχείο;" << endl;
//		cout << "1. Ναι." << endl;
//		cout << "2. Όχι." << endl;
//		cout << "Επιλογή : "; cin >> epilogi;
//
//
//		if ( epilogi == 1 )
//		{
//			a.write_to_file();
//			cout << "Ο γράφος αποθηκεύτηκε στα αρχεία." << endl;
//		}

	}


	else if ( epilogi == 2 )
	{
		a.read_from_file();
		a.print();
	}


	else if ( epilogi == 3 )
	{
		a.Taksinomisis_ton_sindeseon_olou_tou_grafou(); // πρώτα ταξινομώ
		cout << "Θέλω να πάω από Craiova -> Bucharest ." << endl;
		a.BFS("Craiova", "Bucharest");
	}

	else if ( epilogi == 4 )
	{
		a.Taksinomisis_ton_sindeseon_olou_tou_grafou(); // πρώτα ταξινομώ
		cout << "Θέλω να πάω από Craiova -> Bucharest ." << endl;
		a.DFS("Craiova", "Bucharest");
	}


	cout << endl << endl << "3. BFS." << endl;
	cout << "4. DFS" << endl;
	cout << "5. Έξοδος." << endl;
	cout << "Επιλογή : "; cin >> epilogi;

}

cout << "Bey bey Love.. :D " << endl;








return 0;
}
