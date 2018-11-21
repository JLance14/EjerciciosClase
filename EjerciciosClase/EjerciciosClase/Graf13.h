#pragma once

#include <vector>
#include <string>

using namespace std;
class Graf13
{
public:
	Graf13();
	Graf13(vector<string>& nodes, vector<vector<int>>& parelles_nodes);
	~Graf13();
	int getNumNodes() { return m_numNodes; }
	void inserirAresta(int posNode1, int posNode2);
	void eliminarAresta(int posNode1, int posNode2);
	void afegirNode(string node);
	void eliminarNode(string node);
	void mostra();
	vector<vector<int>> cicles();
private:
	vector<string> m_nodes;
	vector<vector<int>> m_matriuAdj;
	int m_numNodes;
	int m_numArestes;
	void crearMatriu(vector<vector<int>>& parelles, vector<int>& pesos);
};
