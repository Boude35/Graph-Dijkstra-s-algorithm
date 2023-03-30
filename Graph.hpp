#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class Graph
{
	//Created to store the adjency list
	unordered_map<string, vector<pair<string,int>>> graph; 
public:
	//constructor from a file
	Graph(istream &ifile);
	//addEdge function
	void addEdge(string from, string to, int weight);
	//Return the price of the shortest path
	int ShortestPath(string from, string to);
};

#endif
