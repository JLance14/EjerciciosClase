#pragma once

#include <string>
#include <vector>
#include <list>
#include <queue>

using namespace std;
class Graf14
{
public:
	Graf14();
	Graf14(vector<string>& nodes, vector<vector<int>>& parelles_nodes,bool m_dirigit);
	Graf14(vector<string>& nodes, vector<vector<int>>& parelles_nodes, vector<int>& pesos, bool m_dirigit);
	~Graf14();
	int getNumNodes() { return m_numNodes; }
	void inserirAresta(int posNode1, int posNode2);
	void inserirAresta(int posNode1, int posNode2, int pes);
	void eliminarAresta(int posNode1, int posNode2);
	void afegirNode(string node);
	void eliminarNode(string node);
	void mostra();
	int grauOutNode(string node);
	void DFS(string nodeInicial, queue<string>& recorregut);
	void DFSRec(int pos, queue<string>& recorregut, vector<bool>& visitat);
	void BFS(string nodeInicial, queue<string>& recorregut);

	void camins(string node1, string node2);
	void printTotsCaminsFins(int pos1, int pos2, vector<bool> visited, list<int> paths);
private:
	vector<list<pair<int, int>>> m_veins; //Per cada vei <index_node,pes>
	//(pes=1 si no ponderat)
	vector<string> m_nodes;
	vector<vector<int>> m_matriuAdj;
	int m_numNodes;
	int m_numArestes;
	void crearMatriu(vector<vector<int>> parelles);
	void crearMatriu(vector<vector<int>> parelles, vector<int> pesos);
};

