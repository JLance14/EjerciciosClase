#include "Graf14.h"

#include <iostream>

Graf14::Graf14()
{
}


Graf14::~Graf14()
{
}

int Graf14::grauOutNode(string node) {
	int grau = 0;
	vector<string>::iterator it;

	it = find(m_nodes.begin(), m_nodes.end(), node);

	if (it != m_nodes.end()) {
		int pos = distance(m_nodes.begin(), it);
		for (int i = 0; i < m_numNodes; i++) {
			if (m_matriuAdj[pos][i] != 0)
				grau++;
		}
	}
	return grau;
}

void Graf14::camins(string node1, string node2) {
	vector<string>::iterator it1, it2;
	vector<int> ruta;
	vector<bool> visited(m_numNodes, false);
	list<int> paths;

	it1 = find(m_nodes.begin(), m_nodes.end(), node1);
	it2 = find(m_nodes.begin(), m_nodes.end(), node2);

	if ((it1 != m_nodes.end()) && (it2 != m_nodes.end())) {
		int pos1 = distance(m_nodes.begin(), it1);
		int pos2 = distance(m_nodes.begin(), it2);

		
	}
}

void Graf14::printTotsCaminsFins(int pos1, int pos2, vector<bool> visited, list<int> paths) {
	visited[pos1] = true;
	paths.push_back(pos1);
	if (pos1 == pos2) {
		for (list<int>::iterator it = paths.begin(); it != paths.end(); it++) {
			cout << m_nodes[(*it)] << "";
			cout << endl;
		}
	}

	else {
		for (int i = 0; i < m_numNodes; i++) {
			if (m_matriuAdj[pos1][i] != 0) {
				if (!visited[i])
					printTotsCaminsFins(i, pos2, visited, paths);
			}
		}
	}

	paths.pop_back();
	visited[pos1] = false;

}

void Graf14::DFS(string nodeInicial, queue<string>& recorregut) {
	vector<string>::iterator itNode = find(m_nodes.begin(), m_nodes.end(), nodeInicial);

	if (itNode != m_nodes.end()) {
		vector<bool> visitat;
		visitat.resize(m_numNodes, false);

		int pos = distance(m_nodes.begin(), itNode);
		DFSRec(pos, recorregut, visitat);
	}
}

void Graf14::DFSRec(int pos, queue<string>& recorregut, vector<bool>& visitat) {
	visitat[pos] = true;
	recorregut.push(m_nodes[pos]);

	for (int col = 0; col < m_numNodes; col++) {
		if ((m_matriuAdj[pos][col] != 0) && (!visitat[col]))
			DFSRec(col, recorregut, visitat);
	}
}

void Graf14::BFS(string nodeInicial, queue<string>& recorregut) {
	vector<string>::iterator itNode = find(m_nodes.begin(), m_nodes.end(), nodeInicial);

	if (itNode != m_nodes.end()) {
		vector<bool> visitat;
		visitat.resize(m_numNodes, false);
		queue<int> pendents;
		int pos = distance(m_nodes.begin(), itNode);
		visitat[pos] = true;
		pendents.push(pos);

		while (!pendents.empty()) {
			int nodeActual = pendents.front();
			pendents.pop();
			recorregut.push(m_nodes[nodeActual]);

			for (int col = 0; col < m_numNodes; col++) {
				if ((m_matriuAdj[nodeActual][col] != 0) && (!visitat[col])) {
					pendents.push(col);
					visitat[col] = true;
				}
			}
		}
	}
}
	
