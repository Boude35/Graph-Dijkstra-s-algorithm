#include "Graph.hpp"



#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char *argv[])
{
	string myFile;//string that will store the file name
	cout<< "Enter input file containing flight data: ";//ask the user for the name of the file
	cin >> myFile;//ask for the name
	ifstream theReader(myFile);//create the reader
	Graph grafica(theReader);//create the graph from a reader
	string one, two;
	cout << "Enter departing airport: "; //ask for the departure airport
	cin >> one;
	cout <<"Enter arriving airport: ";//ask for the destination
	cin >> two;
	cout <<"The cheapest itinerary would be $"; //return the costr of the minimum path
	cout << grafica.ShortestPath(one, two) << endl;
	
}

