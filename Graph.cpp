/*
 * Graph.cpp
 *
 *  Created on: 29 Μαρ 2015
 *      Author: learn-hack
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include "Graph.h"


using namespace std;



int Graph::eisagogi_korifis ( string onoma_korifis )
{

/* Έλεγχος αν το όνομα που δίνει υπάρχει. */
for ( unsigned int node = 0; node < grafima.size(); node++ )
	if ( grafima[node].name == onoma_korifis ) /* Αν βρει πουθενά το ίδιο όνομα σε κάποιο κόμβο - κορυφή του γράφου. */
		{
		//cout << "Το όνομα υπάρχει." << endl;
		return 0; /* Βγες με false. - Δε το δεχόμαστε ρε. - */
		}
/* Τέλος ελέγχου. */

/* Αλλιώς οκ προσθέτουμε την νένα κορυφή στο γράφο μας ( στην λίστα γειτνίασης ). */
korifi.name = onoma_korifis;
korifi.bathmos = 0; /* Αρχικά ο βαθμός του κόβμου είναι 0.*/
grafima.push_back(korifi);

return 1; /* Όλα πήγαν οκ. ;) */
}







int Graph::sindesi_korifis_me_tin_korifi (string kapia_Korifi, string na_sindethi_me_tin_korifi )
{

/* Έλεγχος αν το όνομα που δίνει υπάρχει. */
for ( unsigned int node = 0; node < grafima.size(); node++ )
	if ( grafima[node].name == kapia_Korifi ) /* Αν βρει την κορυφή που θέλει να συνδέσει. */
		{
		grafima[node].sindeete_me.push_back(na_sindethi_me_tin_korifi);
		grafima[node].bathmos++; /* Αυξάνω τον βαθμό του κόβμου. */
		eisagogi_korifis(na_sindethi_me_tin_korifi); /* Βάζουμε και την κορυφή αυτή ( αν δεν υπάρχει ) στο γράφο. */
		return 1;
		}
/* Τέλος ελέγχου. */

cout << "Η κορυφή δε βρέθυκε." << endl;
return 0; /* Βγες με false. */


}






void Graph::print()
{
for ( unsigned int node = 0; node < grafima.size(); node++ )
	{
	if ( grafima[node].sindeete_me.empty() ) /* Αν ο κόμβος - κορυφή δεν συνδέετε με καμία άλλη κορυφή - κόμβο. */
		continue; /* Τότε δεν θα τον εμφανίσεις..απλώς συνέχισε με την επόμενη εκτέλεση της λούπας
				δηλαδή με τον επόμενο κόμβο. ;) */

	cout << "Ο κόμβος " << grafima[node].name << " (έχει βαθμό " << grafima[node].bathmos <<") και συνδέετε με την/τις κορυφές : " ;

	for ( unsigned int j = 0; j < grafima[node].sindeete_me.size(); j++ )

		if ( j == (grafima[node].sindeete_me.size()-1) ) /* Αν έχει φτάσει στο τέλος τις λίστας να βάλει . και όχι , .*/
			cout << grafima[node].sindeete_me[j] << ". ";
		else
			cout << grafima[node].sindeete_me[j] << ", ";

	cout << endl;
	}
}




/*
Παράδειγμα για το edges_table.csv αρχείο :
Source,	Target,	Weight,	Label,	Type
1,	3,	10,	"1->3",	Directed

Παράδειγμα για το nodes_table.csv αρχείο :
ID  , Label
1   , nod1
*/

void Graph::write_to_file(void)
{
string edges_filename = "edges_table.csv";
string nodes_filename = "nodes_table.csv";

ofstream edges_fl(edges_filename);
ofstream nodes_fl(nodes_filename);



edges_fl << "Source,Target,Weight,Label,Type" << endl;
nodes_fl << "ID,Label" << endl;

for ( unsigned int node = 0; node < grafima.size(); node++ )
	{

	/*  */
	nodes_fl << grafima[node].name << "," << "Κορυφή" << grafima[node].name << endl;


	for ( unsigned int j = 0; j < grafima[node].sindeete_me.size(); j++ )
			{
			/* Δίνω μόνο source, target και type τα υπόλοιπα τα αφήνω κενά. */
			edges_fl << grafima[node].name << "," << grafima[node].sindeete_me[j] << ",,,Undirected" << endl;
			}
	}


edges_fl.close();
nodes_fl.close();
}






Graph::~Graph() {

}

