#include "Graf13.h"



Graf13::Graf13()
{
}


Graf13::~Graf13()
{
}



Graf13::Graf13(vector<string>& nodes, vector<vector<int>>& parelles_nodes) {
	m_nodes = nodes;
	m_numNodes = nodes.size();
	m_numArestes = parelles_nodes.size();
	
}

vector<vector<int>> Graf13::cicles() {
	vector<vector<int>> parades_cicles;

	for (int fila = 0; fila < m_numNodes; fila++) {
		for (int col = 0; col < m_numNodes; col++) {
			if (m_matriuAdj[fila][col] == 1) {
				for (int vei = col; vei < m_numNodes; vei++) {
					if ((m_matriuAdj[fila][vei] == 1) && (m_matriuAdj[col][vei] == 1)) {
						parades_cicles.push_back({ fila,col,vei });
					}
				}
			}
		}
	}
	return parades_cicles;


}
