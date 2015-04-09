/*
 * Graph.h
 *
 *  Created on: 29 Μαρ 2015
 *      Author: learn-hack
 */

#ifndef GRAPH_H_
#define GRAPH_H_


#include <vector>
#include <string>
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
	* 	 	 - Ένα string όπου περιέχει κάτι το οποίο θέλουμε να κώψουμε.
	* 	 	 - Ένα χαρακτήρα που αντιστοιχεί στο κριτήριο με το οποίο θα κόβει το string.
	* 	 	 Μόλις συναντάει αυτό τον χαρακτήρα θα κόβει το string που είχε διαβάσει.
	*
	* 	 - Επιστρέφει :
	* 	 	 - Ένα vector με τα διακεκομένα strings.
	*/


public:

	int eisagogi_korifis ( string onoma_korifis );
	int eisagogi_korifis_apo_sindesi ( string onoma_korifis, int bath, string sindeete_me_kapia_korifi );

	int sindesi_korifis_me_tin_korifi (string kapia_Korifi, string na_sindethi_me_tin_korifi );

	void print();

	void write_to_file();

	void read_from_file();

	int find_node(string node_name);
	bool find_connection_node(string from_node, string connecting_node_name);



	virtual ~Graph();
};










#endif /* GRAPH_H_ */


