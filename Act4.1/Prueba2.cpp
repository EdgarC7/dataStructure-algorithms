#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//https://www.techiedelight.com/depth-first-search/
//https://www.techiedelight.com/breadth-first-search/


struct Edge {
	int src, dest;
};


class Graph
{
public:
	vector<vector<int>> adjList;

	int v; 
	
	int e; 

	int** adj; 

	
	Graph(int v, int e){
		this->v = v;
    	this->e = e;
    	adj = new int*[v];
		for (int row = 0; row < v; row++) {
			adj[row] = new int[v];
			for (int column = 0; column < v; column++) {
				adj[row][column] = 0;
			}
		}	
	}

	//https://stackoverflow.com/questions/15999123/const-before-parameter-vs-const-after-function-name-c
	Graph(vector<Edge> const& edges, int N)
	{

		adjList.resize(N);

		for (auto& edge : edges) //ya muy utilizado en lenguajes como Python, Ruby, C# entre otros
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}

	void addEdge(int,int);
	static void loadGraph(int, int, vector<Edge> const&, Graph &); 
	void DFS(int, vector<bool>&);
	static void BFS(Graph const&, int, vector<bool>&);
};

void Graph::addEdge(int start, int e){
	adj[start][e] = 1;
	adj[e][start] = 1;
}

void Graph::loadGraph(int v, int e, vector<Edge> const& edges, Graph& matrix){
    if(e == 0 || v == 0){
        cout << "no puedo crear los grafos sin vertices o sin arcos." << endl;
        return;
    }

    else {
        Graph Edges(edges, v);


	    if(e == 11){
            matrix.addEdge(1, 2);
            matrix.addEdge(1, 7);
            matrix.addEdge(1, 8);
            matrix.addEdge(2, 3);
            matrix.addEdge(2, 6);
            matrix.addEdge(3, 4);
            matrix.addEdge(3, 5);
            matrix.addEdge(8, 9);
            matrix.addEdge(8, 12);
            matrix.addEdge(9, 10);
            matrix.addEdge(9, 11);
	}

        vector<bool> visited(v, false);

        cout << "Metodo DFS mediante una matriz de adyacencia: " << endl;
        matrix.DFS(1,visited); 

        std::cout << std::endl;

        std::cout << std::endl;

        cout << "Metodo BFS mediante una lista de adyacencia: " << endl;
        vector<bool> visitedB(v, false);
        for (int i = 0; i < v; i++) {
            if (visitedB[i] == false) {
                Graph::BFS(Edges, i, visitedB);
            }
        }
    }
}

void Graph::BFS(Graph const& graph, int v, vector<bool>& discovered)
{
	queue<int> q;

	discovered[v] = true;

	q.push(v);

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << v << " ";

		// do for every edge (v -> u)
		for (int u : graph.adjList[v])
			if (!discovered[u])
			{
				discovered[u] = true;
				q.push(u);
			}
	}
}


// Function to perform DFS on the graph
void Graph::DFS(int start, vector<bool>& visited)
{
  
    // Print the current node
    cout << start << " ";
  
    // Set current node as visited
    visited[start] = true;
  
    // For every node of the graph
    for (int i = 0; i < v; i++) {
  
        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] == 1 && (!visited[i])) {
            DFS(i, visited);
        }
    }
}

int main()
{
	
	vector<Edge> edges = {
		//0 is unconnected node
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
	};

    Graph matrix(13,11);

	int N = 13;

	int a = 11;

	Graph::loadGraph(N,a,edges,matrix);

	return 0;
}