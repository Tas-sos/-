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


public:

	int eisagogi_korifis ( string onoma_korifis );

	int sindesi_korifis_me_tin_korifi (string kapia_Korifi, string na_sindethi_me_tin_korifi );

	void print();

	void write_to_file();




	virtual ~Graph();
};










#endif /* GRAPH_H_ */


