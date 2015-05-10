/*
 * Graph.cpp
 *
 *      Author: Tas-sos
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> /* Για το stringstream */
#include <string>
#include <queue> // Για τις ουρές.
#include <set> // Για τα σύνολα.
#include <algorithm> // Για την ταξινόμηση.
#include <iterator> // Για την find.
#include "Graph.h"


using namespace std;



int Graph::eisagogi_korifis ( string onoma_korifis )
{

int node = find_node(onoma_korifis); /* Έλεγχος αν το όνομα που δίνει υπάρχει και αν ναι, σε πια θέση. */

if ( node>= 0) // Αν βρει την θέση της κορυφής αυτής
	{
		cout << "Η κορυφή υπάρχει ήδη φιλαράκο." << endl;
		return 0; // Βγες με false.

	}/* Τέλος ελέγχου. */

/* Αλλιώς οκ προσθέτουμε την νέα κορυφή στο γράφο μας ( στην λίστα γειτνίασης ). */
korifi.name = onoma_korifis;
korifi.bathmos = 0; /* Αρχικά ο βαθμός του κόμβου είναι 0.*/

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

	return 0; // Αλλιώς είναι συνδεδεμένος αυτός ο κόμβος με αυτή την κορυφή ρε! Άσε με ήσυχο.. :P

	}

else // Αλλιώς, αν δεν υπάρχει ΟΎΤΕ η ΚΟΡΥΦΉ αυτή στον γράφο.
	korifi.name = onoma_neas_korifis;
	korifi.bathmos = bath; /* Εδώ λέμε και τον βαθμό τώρα που θα έχει.. */

	korifi.sindeete_me.clear(); // Καθαρίζω το βέκτορ πρώτα ΜΗΠΩΣ έχει ξεμείνει τίποτα..
	korifi.sindeete_me.push_back(sindeete_me_kapia_korifi); /* ΚΑΙ με ποιον κόμβο συνδέετε,
	εφόσον προφανώς για να δημιουργούμε τώρα αυτό τον κόμβο, δε συνδέετε και με κανένα άλλο.*/

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


cout << "Η κορυφή που θέλεις να συνδέσεις, δε βρέθηκε." << endl;
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
	return -1; // Αν διασχίσει όλο τον γράφο και δε βρει κορυφή με το όνομα που είπαμε,τότε... ΑΝΤΕ ΓΕΙΑ!

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

ofstream edges_fl( edges_filename.c_str() ); // Για το .c_str() :-> http://stackoverflow.com/a/6323624/3922124
ofstream nodes_fl( nodes_filename.c_str() );



edges_fl << "Source,Target,Weight,Label,Type" << endl;
nodes_fl << "ID,Label" << endl;

for ( unsigned int node = 0; node < grafima.size(); node++ )
	{

	/*  */
	nodes_fl << grafima[node].name << "," << grafima[node].name << endl;


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



int	Graph::read_from_file()
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
	{
		cout << "Υπήρξε πρόβλημα κατά το άνοιγμα του αρχείου." << endl;
		return -1;
	}







	edge_file.close(); // Κλείσιμο του ρεύματος - αρχείου.

	return 1; // Όλα πήγαν καλά.
}



void	Graph::Taksinomisis_ton_sindeseon_olou_tou_grafou()
{
	unsigned int i = 0;

	for ( i = 0 ; i < grafima.size(); i++ )
	{
		sort(grafima[i].sindeete_me.begin(), grafima[i].sindeete_me.end());

	}

}
















































/* ============================================================================================================================= *
 *
 *								Αλγόριθμοι Αναζήτησης Τεχνητής Νοημοσύνης.														 *
 *
 * ============================================================================================================================= */





/* ===================================================     =================================================== *
 * =================================================== BFS =================================================== *
 * ===================================================     =================================================== */

void	Graph::BFS(string arxi, string proorismo)
{
	Arxikopiisi_BFS(arxi); // Αυτά τα κάνω μονάχα για την παρθενική του φορά...


	while ( !Ftasame(proorismo) ) // Όσο ΔΕΝ έφτασε στον προορισμό.

	{
		Epektasi_Trexousas_katastasis_sto_metopo_anazitisis(); // Βάζω -ΚΑΤΆΛΛΗΛΑ- στο μέτωπο αναζήτησης της κορυφές που συνδέετε η τρέχουσα κατάσταση.
		Prosthiki_Trexousas_katastasis_sto_Klisto_Sinolo(); // Βάζω την τρέχουσα κατάσταση στο κλειστό σύνολο.
		Prosthiki_trexousas_katastasis(); // Προσθήκη ΝΈΑΣ τρέχουσας κατάστασης.
	}

	Emfanise_to_monopati_lisis_BFS();
	//Print_all_Queue(); // Αν θέλω να εμφανίσω και όλα τα μονοπάτια της δομής μου. :)


}


void	Graph::Arxikopiisi_BFS(string arxi)
{
	Katharismos_domon_anazitiseon();

	cout << "Τρέχουσα κατάσταση \t|\tΝέα μονοπάτια που προστέθηκαν στο μέτωπο αναζήτησης " << endl;

	trexousa_katastasi.push_back(arxi); // Βάζω κατευθείαν την κορυφή που μου δίνει ως τρέχουσα - ΔΕΝ ΤΗΝ ΈΛΕΓΞΑ ΌΜΩΣ ! -
	vector <string> arxiko;
	arxiko.push_back(arxi);
	BFS_metopo_anazitisis.push( arxiko ); // Προσθήκη του αρχικού "μονοπατιού" αυτού στο μέτωπο αναζήτησης.
	cout << arxi[0];

}






bool	Graph::Epektasi_Trexousas_katastasis_sto_metopo_anazitisis()
{

	vector <string> temp = BFS_metopo_anazitisis.front(); // Παίρνω το πρώτο μονοπάτι από το μέτωπο αναζήτησης.

	BFS_metopo_anazitisis.pop(); // & διαγράφω το πρώτο μονοπάτι αυτό από το μέτωπο αναζήτησης.

	string trexon = temp[ temp.size()-1 ]; /* Παίρνω την τελευταία ΚΟΡΥΦΉ από το πρώτο μονοπάτι &

	Πάω να την επεκτείνω στο μέτωπο αναζήτησης. */
	int kombos = find_node( trexon ); //  Υπάρχει καταρχήν η τρέχουσα κατάσταση και ΑΝ ναι ΠΟΥ ;;

	cout << "\t\t\t|\t";

	for (unsigned int i = 0 ; i < grafima[kombos].sindeete_me.size(); i++ ) // Από την αρχή μέχρι το τέλος της λίστας που περιέχει τις κορυφές που συνδέετε.
	{
		temp.push_back( grafima[kombos].sindeete_me[i] );  // Προσθήκη της κορυφής αυτής στο νέο μονοπάτι.
		Emfanisi_trexon_Metopou_Anazitisis(temp);

		BFS_metopo_anazitisis.push( temp ); // Προσθήκη του μονοπατιού αυτού στο μέτωπο αναζήτησης.

		temp.erase(temp.end()); // Διαγραφή της τελευταία κορυφής που πρόσθεσα.. ώστε να μπει στην θέση της η επόμενη - το επόμενο παιδί...
	}

	cout << endl;
	return true;

}




void	Graph::Emfanisi_trexon_Metopou_Anazitisis( vector <string> Metopo )
{
	cout << "(";

	for ( unsigned int j = 0; j < Metopo.size(); j++ )  // Για κάθε μονοπάτι του μετώπου.
	{
		if ( j < Metopo.size()-1 )
			cout << Metopo[j][0] << "-" ;

		else if ( j == (Metopo.size()-1) )
			cout << Metopo[j][0];
	}

	cout << ")";

}






void	Graph::Prosthiki_trexousas_katastasis()
{
	vector <string> temp = BFS_metopo_anazitisis.front(); // Παίρνω το πρώτο μονοπάτι από το μέτωπο αναζήτησης.

	string trexon = temp[ temp.size()-1 ]; // Παίρνω την τελευταία κορυφή από το πρώτο μονοπάτι.

	while ( An_iparxi_sto_klisto_sinolo( trexon ) ) // Για όσο βρίσκει κορυφές που ΥΠΆΡΧΟΥΝ στο κλειστό σύνολο.
	{
		cout << trexon[0] << "\t-LOOP-\t\t| " << endl ;

		BFS_metopo_anazitisis.pop(); // & διαγράφω το μονοπάτι αυτό από το μέτωπο αναζήτησης.

		temp = BFS_metopo_anazitisis.front(); // παίρνω το επόμενο τώρα πλέον πρώτο μονοπάτι από το μέτωπο αναζήτησης

		trexon = temp[ temp.size()-1 ]; // και από το μονοπάτι αυτό την τελευταία του κορυφή.
	}

	// Αν κάποιος κόμβος από το μέτωπο αναζήτησης, ΔΕΝ έχει ξανά ελεγχθεί

	trexousa_katastasi.push_back( trexon ); // ΤΌΤΕ, τώρα θα τον βάλω ως τρέχουσα κατάσταση..
	cout << trexon[0];

}




bool Graph::An_iparxi_sto_klisto_sinolo(string korifi)
{
	bool  a  { klisto_sinolo.find( korifi ) != klisto_sinolo.end() };
	return a;
}





void	Graph::Prosthiki_Trexousas_katastasis_sto_Klisto_Sinolo()
{	klisto_sinolo.insert( trexousa_katastasi.back() ) ;	}





bool	Graph::Ftasame(string stoxos)
{	return ( trexousa_katastasi.back() == stoxos ); /* Αν η τρέχουσα κατάσταση συμπίπτει με τον προορισμό! ;) */ }





void	Graph::Emfanise_to_monopati_lisis_BFS()
{
	unsigned int i = 0;

	vector <string> temp = BFS_metopo_anazitisis.front();


	cout << endl << endl << "Η λύση είναι [ ";

	for (i = 0 ; i < temp.size(); i++ )
	{

		if ( i != temp.size()-1 ) // Για ομορφιά το κάνω αυτό, για να εμφανίζονται π.χ. -> (C-P-B)
			cout << temp[i] << "-";

		else if ( i == temp.size()-1 )
			cout << temp[i] << "";


	}

	cout << " ]";

}


void	Graph::Print_all_Queue()
{
	cout << endl;
	while ( !BFS_metopo_anazitisis.empty() ) // Όσο δεν έχει αδειάσει όλη η ουρά..
	{
		Emfanisi_trexon_Metopou_Anazitisis( BFS_metopo_anazitisis.front() );
		BFS_metopo_anazitisis.pop();

	}
}






/* ===================================================     =================================================== *
 * =================================================== DFS =================================================== *
 * ===================================================     =================================================== */






void	Graph::DFS(string arxi, string proorismo)
{

	Arxikopiisi_DFS(arxi);// Αυτά τα κάνω μονάχα για την παρθενική του φορά...


	while ( !Ftasame(proorismo) ) // Όσο ΔΕΝ φτάσαμε στον προορισμό μας.

	{
		Epektasi_Trexousas_katastasis_sto_metopo_anazitisis_DFS(); // Βάζω -ΚΑΤΆΛΛΗΛΑ- στο μέτωπο αναζήτησης της κορυφές που συνδέετε η τρέχουσα κατάσταση.
		Prosthiki_Trexousas_katastasis_sto_Klisto_Sinolo(); // Βάζω την τρέχουσα κατάσταση στο κλειστό σύνολο.
		Prosthiki_trexousas_katastasis_DFS(); // Προσθήκη τρέχουσας κατάστασης.
	}

	Emfanise_to_monopati_lisis_DFS();
	//Print_all_Stack(); // Για επιβεβαίωση.


}


void	Graph::Arxikopiisi_DFS(string arxi)
{
	Katharismos_domon_anazitiseon();

	cout << "Τρέχουσα κατάσταση \t|\tΝέα μονοπάτια που προστέθηκαν στο μέτωπο αναζήτησης " << endl;
	trexousa_katastasi.push_back(arxi); // Βάζω κατευθείαν την κορυφή που μου δίνει ως τρέχουσα - ΔΕΝ ΤΗΝ ΈΛΕΓΞΑ ΌΜΩΣ! -

	vector <string> arxiko;
	arxiko.push_back(arxi);
	DFS_metopo_anazitisis.push( arxiko ); // Προσθήκη του μονοπατιού αυτού στο μέτωπο αναζήτησης.
	cout << arxi[0];

}






bool	Graph::Epektasi_Trexousas_katastasis_sto_metopo_anazitisis_DFS()
{

	vector <string> temp = DFS_metopo_anazitisis.top(); // Παίρνω το πρώτο μονοπάτι από το μέτωπο αναζήτησης.

	DFS_metopo_anazitisis.pop(); // & διαγράφω το πρώτο μονοπάτι αυτό από το μέτωπο αναζήτησης.

	string trexon = temp[ temp.size()-1 ]; 	/* Παίρνω την τελευταία ΚΟΡΥΦΉ από το πρώτο μονοπάτι &

	Πάω να την επεκτείνω  στο μέτωπο αναζήτησης. */
	int kombos = find_node( trexon ); //  Υπάρχει καταρχήν η τρέχουσα κατάσταση και ΑΝ ναι ΠΟΥ ;;

	cout << "\t\t\t|\t";

	int plithos = grafima[kombos].sindeete_me.size(); /* Τα βάζω εδώ ΑΝΆΠΟΔΑ για χατήρι του καθηγητή, ώστε να τα βλέπουμε αλφαβητικά..
	Δεν παίζει πρόβλημα όμως αν η for ήταν και έτσι : for (unsigned int i = 0 ; i < grafima[kombos].sindeete_me.size(); i++ ) */
	for (int i = plithos-1 ; i >= 0; --i ) // Έτσι..από το ΤΈΛΟΣ τώρα, μέχρι την ΑΡΧΉ της λίστας ( επειδή το πάμε ανάποδα τώρα :P ) που περιέχει τις κορυφές που συνδέετε.
	{
		temp.push_back( grafima[kombos].sindeete_me[i] );  // Προσθήκη της κορυφής αυτής στο νέο μονοπάτι.

		Emfanisi_trexon_Metopou_Anazitisis(temp);

		DFS_metopo_anazitisis.push( temp ); // Προσθήκη του μονοπατιού αυτού στο μέτωπο αναζήτησης.

		temp.erase(temp.end()); // Διαγραφή της τελευταία κορυφής που πρόσθεσα.. ώστε να μπει στην θέση της η επόμενη κορυφή που συνδέετε η τρέχων...
	}

	cout << endl;
	return true;

}





void	Graph::Prosthiki_trexousas_katastasis_DFS()
{
	vector <string> temp = DFS_metopo_anazitisis.top();

	string trexon = temp[ temp.size()-1 ];

	while ( An_iparxi_sto_klisto_sinolo( trexon ) ) // Για όσο βρίσκει κορυφές που ΥΠΆΡΧΟΥΝ στο κλειστό σύνολο.
	{
		cout << trexon[0] << "\t-LOOP-\t\t| " << endl ;

		DFS_metopo_anazitisis.pop(); // διαγράφω το μονοπάτι αυτό από το μέτωπο αναζήτησης.

		temp = DFS_metopo_anazitisis.top(); // & παίρνω το επόμενο μονοπάτι..

		trexon = temp[ temp.size()-1 ]; // και από αυτό το μονοπάτι, παίρνω κλασικά την τελευταία του κορυφή..
	}

	// Αν κάποιος κόμβος από το μέτωπο αναζήτησης, ΔΕΝ έχει ξανά ελεγχθεί

	trexousa_katastasi.push_back( trexon ); // ΤΌΤΕ, τώρα θα τον βάλω ως τρέχουσα κατάσταση..
	cout << trexon[0];

}




void	Graph::Emfanise_to_monopati_lisis_DFS()
{
	unsigned int i = 0;

	vector <string> temp = DFS_metopo_anazitisis.top();


	cout << endl << endl << "Η λύση είναι [ ";

	for (i = 0 ; i < temp.size(); i++ )
	{

		if ( i != temp.size()-1 ) // Για ομορφιά το κάνω αυτό, για να εμφανίζονται π.χ. -> (C-P-B)
			cout << temp[i] << "-";

		else if ( i == temp.size()-1 )
			cout << temp[i] << "";


	}

	cout << " ]";

}



void	Graph::Print_all_Stack()
{
	cout << endl;
	while ( !DFS_metopo_anazitisis.empty() ) // Όσο δεν έχει αδειάσει όλη η ουρά
	{
		Emfanisi_trexon_Metopou_Anazitisis( DFS_metopo_anazitisis.top() );
		DFS_metopo_anazitisis.pop();
	}

}









































void	Graph::Katharismos_domon_anazitiseon()
{
	trexousa_katastasi.clear(); // Καθαρισμός δομής τρέχουσας κατάστασης.
	klisto_sinolo.clear(); // Καθαρισμός δομής κλειστού συνόλου.
	//BFS_metopo_anazitisis.
	//DFS_metopo_anazitisis
}








Graph::~Graph() {

}

