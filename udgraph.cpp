/* An implementation of an Undirected Graph by Ekesh Kumar. */
#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

/* An enumerated type of colors. These are used DFS/BFS traversal, and 
    implementations of red-black trees. */
typedef enum color {WHITE, GRAY, RED, BLACK} Color; 

typedef struct Node {
	int data;
	int distance; 
	Color color;
} Node;



int main() {
	/* An array of nodes, representing the nodes adjacent to node i. */
	int size = 5;
	vector<vector<Node>> graph(size);


	Node n1 = {1}; 
	Node n2 = {2};
	Node n3 = {3};
	Node n4 = {4};

	graph.push_back(n1);
	graph.push_back(n2);
	graph.push_back(n3);
	graph.push_back(n4);

	graph.at(0).push_back(n2);
	graph.at(0).push_back(n3);
	graph.at(1).push_back(n4);

}

void BFS(vector<vector<Node>> graph, Node source) {

	for (auto i : graph) {
		
	}


}