#include <iostream>
#include <list>
#include "Graph.h"
using namespace std;
Graph::Graph(int _v)
{
	m_NofVertex = _v;
	adj = new list<int>[_v];
}
Graph::~Graph()
{
	if(adj)
		delete[] adj;
}
void Graph::AddEdge(int from, int to)
{
	cout<<__FUNCTION__<<" Called "<<endl;
	if(adj)
	{
		adj[from].push_back(to);
	}
	else
	{
		cout<<__FUNCTION__<<" Error :"<<__LINE__<<endl;
	}
}
void Graph::BFS(int start)
{
	if(adj)
	{
		list<int> toVisit;
		bool* visited = new bool[m_NofVertex];
		toVisit.push_back(start);
		for(int i = 0; i<m_NofVertex; i++)
		{
			visited[i] = false;
		}
		visited[start] = true;
		while(!toVisit.empty())
		{
			int node = toVisit.front();
			cout<<__FUNCTION__<<" visiting node: "<<node<<endl;
			toVisit.pop_front();
			
			for(int elt:adj[node])
			{
				if(!visited[elt])
				{
					toVisit.push_back(elt);
					visited[elt] = 1;
				}
			}
		}
	}
}
void Graph::DFS(int start)
{
	if(adj)
	{
		list<int> toVisit;
		bool* visited = new bool[m_NofVertex];
		toVisit.push_back(start);
		for(int i = 0; i<m_NofVertex; i++)
		{
			visited[i] = false;
		}
		visited[start] = true;
		while(!toVisit.empty())
		{
			int node = toVisit.back();
			cout<<"Visited "<<node<<endl;
			toVisit.pop_back();
			for(int i:adj[node])
			{
				if(!visited[i])
				{
					toVisit.push_back(i);
					visited[i] = true;
				}
			}
		}
	}
}