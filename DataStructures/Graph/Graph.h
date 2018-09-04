#include <iostream>
#include <list>
using namespace std;
class Graph
{
	int m_NofVertex;
	list<int>* adj;
	Graph(Graph& toCopy);
public:
	Graph(int _v);
	void AddEdge(int from, int to);
	void BFS(int start);
	void DFS(int start);
	~Graph();
};