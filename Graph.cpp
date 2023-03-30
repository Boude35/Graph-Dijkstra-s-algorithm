#include "Graph.hpp"
using namespace std;

//constructor from a file
Graph::Graph(istream &ifile)
{
	//store the number
	int nodeNumber;
	ifile >> nodeNumber;
	
	//store the name 
	string nodeName;
	
	for(int i = 1; i<=nodeNumber; i++)
	{
		ifile >> nodeName;
	}
	
	//store the number of conections
	int connNumber;
	ifile >> coneccNumber;
	
	//store the conections
	string iniNode;
	string finNode;
	int weight;

	//loop over the conections and add an edge with that info
	for(int i = 1; i<=d; i++)
	{
		ifile >> iniNode >> finNode >> weight;
		addEdge(iniNode,finNode,weight);
	}
	
}
//Add Edges to the adjacency list
void 
Graph::addEdge(string from,string to,int weight)
{   
	//since it is an undirected graph it will store the info of the conection in the adjency list
	graph[from].push_back({to,weight});
	graph[to].push_back({from,weight});
}

//return the price of the shortest path
int 
Graph::ShortestPath(string dep,string des)
{
		string s=dep;
		
		//create an unordered map to store distance
		unordered_map<string,int> dist;
		
		//inizializate the unordered map with every value of the graph
		for(auto x:graph)
		dist[x.first]=INT_MAX;
		
		//create an unordered map to store nodes visited
		unordered_map<string,bool> processed;
		
		//inizializate all the values as false
		for(auto x:graph)
		processed[x.first]=false;
		
		dist[s]=0;
		
		priority_queue<pair<int,string> > q;
		
		
		q.push({0,s});
		
		//while has values
		while(!q.empty())
		{
			// a equals the string at the top of qeue
			string a=q.top().second;
			
			//remove the top value from q
			q.pop();
			
			if(processed[a])
			continue; 
			
			//is processed
			processed[a]=true;
			
			for(auto u:graph[a])
			{
				string b=u.first;
				int w=u.second;
				
				if(dist[a]+w<dist[b])
				{
					dist[b]=dist[a]+w;
					q.push({-1*dist[b],b}); //multiply by -1 because deafault priorty queue finds max distance 
				}
			}
			
		}
		return dist[des];
}

