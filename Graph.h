/*
 * Graph.h
 *
 *      Author: Tas-sos
 */

#ifndef GRAPH_H_
#define GRAPH_H_


#include <vector>
#include <string>
#include <queue> // Για τις ουρές.
#include <stack> // Για τις στοίβες.
#include <set> // Για τα σύνολα.
#include <list>


using namespace std;


class Graph {

	private :

	struct node
	{
	string name;
	vector <string> sindeete_me;
	unsigned int bathmos;
	};


	struct node korifi;

	vector <struct node> grafima; /* Λίστα γειτνίασης όπου εδώ αναπαριστάτε όλος ο γράφος.*/


	// Ιδιοτική συνάρτηση η οποία κόβει strings.
	vector <string> split (string &line_buffer, char split_to); /*
	* Συνάρτηση η οποία :
	* 	 - Παίρνει :
	* 	 	 - Ένα string όπου περιέχει κάτι το οποίο θέλουμε να κόψουμε.
	* 	 	 - Ένα χαρακτήρα που αντιστοιχεί στο κριτήριο με το οποίο θα κόβει το string.
	* 	 	 Μόλις συναντάει αυτό τον χαρακτήρα, θα κόβει το string σε δύο μέρη.
	* 	 	 Το πρώτο μέρος θα αποτελεί το υπο-string πριν τον ειδικό χαρακτήρα, και το δεύτερο μέρος, θα αποτελείτε από το υπο-string έπειτα του
	* 	 	 ειδικού χαρακτήρα.
	*
	* 	 - Επιστρέφει :
	* 	 	 - Ένα vector με τα διακεκομμένα strings.
	*/



	/* ================================================================================= *
	 * ========================= Αλγόριθμοι Τυφλής αναζήτησης. ========================= *
	 * ================================================================================= */

	vector <string> trexousa_katastasi; // Εδώ θα αποθηκεύω την εκάστοτε τρέχουσα κατάσταση.
	set <string> klisto_sinolo {}; // Ορίζω ένα σύνολο ως άδειο αρχικά.

	void Katharismos_domon_anazitiseon();

	void Prosthiki_Trexousas_katastasis_sto_Klisto_Sinolo();

	void Emfanisi_trexon_Metopou_Anazitisis( vector <string> );

	bool An_iparxi_sto_klisto_sinolo(string);

	bool Ftasame(string);


	/* ============================================================================================================= *
	 * ==================================================== BFS ====================================================  */

	queue < vector <string> > BFS_metopo_anazitisis; // Εδώ θα προστίθεντο κορυφές ΠΡΟΣ ΕΞΈΤΑΣΗ για BFS.  - F  I F O -

	void Arxikopiisi_BFS(string);

	void Prosthiki_trexousas_katastasis();

	bool Epektasi_Trexousas_katastasis_sto_metopo_anazitisis();

	void Emfanise_to_monopati_lisis_BFS();

	void Print_all_Queue();




	/* ============================================================================================================= *
	 * ==================================================== DFS ====================================================  */

	stack < vector <string> > DFS_metopo_anazitisis; // Εδώ θα προστίθενται κορυφές ΠΡΟΣ ΕΞΈΤΑΣΗ για DFS.  - L  I F O -

	void Arxikopiisi_DFS(string);

	void Prosthiki_trexousas_katastasis_DFS();

	bool Epektasi_Trexousas_katastasis_sto_metopo_anazitisis_DFS();

	void Emfanise_to_monopati_lisis_DFS();

	void Print_all_Stack();







public:

	int eisagogi_korifis ( string onoma_korifis );
	int eisagogi_korifis_apo_sindesi ( string onoma_korifis, int bath, string sindeete_me_kapia_korifi );

	int sindesi_korifis_me_tin_korifi (string kapia_Korifi, string na_sindethi_me_tin_korifi );

	void print();

	void write_to_file();

	int read_from_file();
	/*
	 * Επιστρέφει :
	 * 	- 	 1  : Αν όλα πήγαν καλά.
	 * 	-	-1  : Αν υπήρξε κάποιο πρόβλημα με το άνοιγμα του αρχείου.
	 * */

	int find_node(string node_name);
	bool find_connection_node(string from_node, string connecting_node_name);

	void Taksinomisis_ton_sindeseon_olou_tou_grafou();




	/* ================================================================================= *
	 * ========================= Αλγόριθμοι Τυφλής αναζήτησης. ========================= *
	 * ================================================================================= */

	void BFS(string arxi, string proorismo);
	void DFS(string arxi, string proorismo);




	virtual ~Graph();
};










#endif /* GRAPH_H_ */


