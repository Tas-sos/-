/*
 * Graph.cpp
 *
 *  Created on: 29 Μαρ 2015
 *      Author: Tas-sos
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> /* Για το stringstream */
#include <string>
#include "Graph.h"


using namespace std;



int Graph::eisagogi_korifis ( string onoma_korifis )
{

int node = find_node(onoma_korifis); /* Έλεγχος αν το όνομα που δίνει υπάρχει και αν ναι, σε πια θέση. */

if ( node>= 0) // Αν βρει την θέση της κορυφής αυτής
	{
		cout << "Η κορυφή υπάρχει ηδη φιλαράκο." << endl;
		return 0; // Βγες με false.

	}/* Τέλος ελέγχου. */

/* Αλλιώς οκ προσθέτουμε την νέα κορυφή στο γράφο μας ( στην λίστα γειτνίασης ). */
korifi.name = onoma_korifis;
korifi.bathmos = 0; /* Αρχικά ο βαθμός του κόβμου είναι 0.*/

grafima.push_back(korifi); // Προσθήκη του κόμβου - κορυφής στον γράφο.

return 1; /* Όλα πήγαν οκ. ;) */
}




int Graph::eisagogi_korifis_apo_sindesi ( string onoma_neas_korifis, int bath, string sindeete_me_kapia_korifi )
{

int node = find_node(onoma_neas_korifis); /* Έλεγχος αν το όνομα που δίνει υπάρχει και αν ναι, σε πια θέση. */

if ( node>= 0) // Αν βρει πουθενά το ίδιο όνομα σε κάποιο κόμβο - κορυφή του γράφου.
	{

	if ( (find_connection_node(onoma_neas_korifis,sindeete_me_kapia_korifi)) == false ) // Αν ΔΕΝ υπάρχει η σύνδεση αυτής της κορυφής, με αυτό τον κόμβο..
		{
		grafima[node].bathmos = bath;
		grafima[node].sindeete_me.push_back(sindeete_me_kapia_korifi); /* με ποιον κόμβο συνδέετε.. */

		return 1;
		}

	return 0; // Αλλιώς είναι συνδεδεμένος αυτός ο κόμβος με αυτή την κορυφή ρε! Άσε με ίσυχο.. :P

	}

else // Αλλιώς, αν δεν υπάρχει ΟΎΤΕ η ΚΟΡΥΦΉ αυτή στον γράφο.
	korifi.name = onoma_neas_korifis;
	korifi.bathmos = bath; /* Εδώ λέμε και τον βαθμό τώρα που θα έχει.. */

	korifi.sindeete_me.clear(); // Καθαρίζω το βέκτορ πρώτα ΜΗΠΩΣ έχει ξεμήνει τίποτα..
	korifi.sindeete_me.push_back(sindeete_me_kapia_korifi); /* ΚΑΙ με ποιον κόμβο συνδέετε,
	εφόσον προφανώς για να δημιουρφούμε τώρα αυτό τον κόμβο, δε συνδέετε και με κανένα άλλο.*/

	grafima.push_back(korifi); // Προσθήκη του κόμβου στο γράφο ( στην λίστα γειτνίασης ).

return 1; /* Όλα πήγαν οκ. ;) */
}







int Graph::sindesi_korifis_me_tin_korifi (string kapia_Korifi, string na_sindethi_me_tin_korifi )
{

int node = find_node(kapia_Korifi);/* Έλεγχος αν το όνομα που δίνει υπάρχει. */

//cout << "prin node position : " << node << endl;

if ( node>=0 ) // Αν βρει την κορυφή που θέλει να συνδέσει ( με κάποια άλλη ).
		{

		//cout << "οκ υπάρχει η κορυφή '" << kapia_Korifi << "' στην θέση " << node << endl;

		if ( (find_connection_node(kapia_Korifi,na_sindethi_me_tin_korifi)) == false ) // Αν ΔΕΝ υπάρχει η σύνδεση αυτής της κορυφής, με αυτό τον κόμβο..
			{ // Τότε γίνεται μονάχα σύδενση μεταξύ τους.

			//cout << "Den yparxi sindesi meta3i tis " << kapia_Korifi << " me tin " << na_sindethi_me_tin_korifi << endl;
			grafima[node].sindeete_me.push_back(na_sindethi_me_tin_korifi);
			grafima[node].bathmos++; /* Αυξάνω τον βαθμό του κόβμου. */

			}

		else if ( find_connection_node(kapia_Korifi,na_sindethi_me_tin_korifi) )
		{
			cout << "Είναι ήδη συνδεδεμένες οι κορυφές αυτές." << endl;
			return -1;
		}


		int conecting_node = find_node(na_sindethi_me_tin_korifi);/* Έλεγχος αν το όνομα που δίνει υπάρχει. */

		// Για την κορυφή σύνδεσης...
		if ( conecting_node < 0 ) // Αν η κορυφή ΠΡΟΣ σύνδεση, ΔΕΝ υπάρχει στον γράφο..
			{
		//	cout << "Η κορυφή " << na_sindethi_me_tin_korifi << " ΔΕΝ υπάρχει στο γράφο, άρα θα την προσθέσω ΤΩΡΑ. " << endl;
			eisagogi_korifis_apo_sindesi(na_sindethi_me_tin_korifi,1,kapia_Korifi);
			/* Βάζουμε ΚΑΙ την κορυφή αυτή ( αν δεν υπάρχει ) στο γράφο.
			Με βαθμός κιόλας ( αντί 0 της προεπιλογής για νέα κορυφή ) 1.
			ΚΑΙ στέλνουμε και το όνομα της κορυφής με την οποία την συνδέσαμε τώρα. */
			}

		else if ( conecting_node >= 0 ) // Ενώ αν υπάρχει.. :
		{	// Συνδέω και αυτή με αυτή που ζήτησε να συνδεθή μαζί της.
			grafima[conecting_node].sindeete_me.push_back(kapia_Korifi);
			grafima[conecting_node].bathmos++;
		}

		// ----------------------------------------------------------------------------------------------

		return 1;
		}
/* Τέλος ελέγχου. */


cout << "Η κορυφή που θέλεις να συνδέσεις, δε βρέθυκε." << endl;
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



int Graph::find_node(string node_name)
{
	for ( unsigned int node = 0; node < grafima.size(); node++ ) // Από την αρχή μέχρι το τέλος του γράφου
		{

		if ( grafima[node].name == node_name ) // Αν βρει μέσα στον γράφο κορυφή με το ίδιο όνομα..
				{
				//cout << "yes";
				return node; // Οκ την βρήκα ρε!
				}
		}

	//cout << "NO";
	return -1; // Αν διασχήσει όλο τον γράφο και δε βρει κορυφή με το ονομα που είπάμε,τότε... ΑΝΤΕ ΓΕΙΑ!

}




bool Graph::find_connection_node(string from_node, string connecting_node_name)
{
	for ( unsigned int node = 0; node < grafima.size(); node++ )

		if ( grafima[node].name == from_node ) // Αν βρει μέσα στον γράφο κορυφή με το ίδιο όνομα..

			for ( unsigned int connecting_node = 0; connecting_node < grafima[node].sindeete_me.size(); connecting_node++ )

				if ( grafima[node].sindeete_me[connecting_node] == connecting_node_name )
					return true;

	return false;

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



/* ================================  Split Function  ================================ */



vector <string> Graph::split (string &line_buffer, char split_to)
{


	/* Δημιουργούμε ενός νέου ρεύματος και αρχικοποίηση του με το "line_buffer" . */
	istringstream SS(line_buffer);

	/* Δημιουργία νέου προσωρινού string. */
	string split_buffer;



	vector <string> temp_vec ; /* Δημιουργία προσωρινού vector . */


	// by http://stackoverflow.com/questions/13035674/how-to-read-line-by-line-or-a-whole-text-file-at-once
	while ( getline ( SS, split_buffer, split_to ) )

		temp_vec.push_back( split_buffer ); /* Εκχωρώ την ακέραια τιμή του string στο ακέραιων vector μου. */



	return temp_vec;
}
/* =========================================  Τέλος split  ========================================= */




//edgefile :
//Source,Target,Weight,Label,Type
//1,3,,,Undirected
//
//nodesfile :
//ID,Label
//1,Κορυφή1
//2,Κορυφή2



void	Graph::read_from_file()
{

	ifstream edge_file; // Δημιουργία ρεύμα εισόδου.


	edge_file.open("edges_table.csv"); // Ανοίγει το αρχείο.


	string output;
	vector <string> temp_vec;

	if ( edge_file.is_open() ) // Αν το αρχείο κατάφερε να ανοίξει.
		{
		bool first_line = true;

		while ( getline(edge_file,output) ) // Όσο το αρχείο δεν έχει τελειώσει.
			{

			if ( first_line ) // Αν είναι στην πρώτη γραμμή του αρχείου..
				{ //  δε θέλω την πληροφορία από αυτή τη γραμμή.
				first_line = false;
				continue;
				}

			temp_vec = split(output,',');

			/* For tested :
			for (unsigned int i = 0 ; i < temp_vec.size(); i++ )
				{
				cout << temp_vec[i] << "!";
				//cout << "a?" ;
				}
			cout << endl;
			___________________________________________
			Output :
			Source!Target!Weight!Label!Type!
			1!3!!!Undirected!
			1!2!!!Undirected!
			___________________________________________
			*/


			// Για το Source ( 1η θέση (0) ).
			eisagogi_korifis( temp_vec[0] ); // Η θέση 1 περιέχει την πηγή - κορυφή (Source).

			// Για το Τarget ( 2η θέση (1) ).
			sindesi_korifis_me_tin_korifi(temp_vec[0],temp_vec[1]); // Η θέση 2 περιέχει τon προορισμό (Target).

			}

		}

	else
		cout << "Υπήρξε πρόβλημα κατά το άνοιγμα του αρχείου." << endl;







	edge_file.close(); // Κλείσιμο του ρεύματος - αρχείου.


}





Graph::~Graph() {

}

