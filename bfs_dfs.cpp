#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <list>

using namespace std;

class Graph
{
	int V;
	list <int> *adj;
	bool *visit;
	int *tot;
public:
	Graph(int V);
	void addEdge(int u, int v);
	void BFS(int s);
	void DFS(int s);
	void disptot();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list <int>[V];
	visit = new bool[V];
	tot = new int[V];
	for(int j=0; j<V; j++)
	{
		visit[j] = false;
		tot[j] = 0;
	}
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	int *distance = new int[V];
	int *neibors = new int[V];
	int *req = new int[V];

	list<int>::iterator i;

	for(int j=0; j<V; j++)
	{
		visited[j] = false;
		neibors[j] = 0;
		for(i = adj[j].begin(); i!=adj[j].end(); i++)
		{
			neibors[j]++;
		}
		req[j] = 1;
		//cout << neibors[j];
	}
	
	list <int> q;
	visited[s] = true;
	distance[s] = 0;
	q.push_back(s);

	while(!q.empty())
	{
		s = q.front();
		cout << s+1 << " " << distance[s] <<  endl; 
		q.pop_front();

		for(i = adj[s].begin(); i!=adj[s].end(); i++)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				distance[*i] = distance[s] + 1;
				q.push_back(*i);
				req[s]+= neibors[*i];
			}
		}
	}
	for(int j=0; j<V; j++)
	{
		cout << j+1 << " " << req[j] <<  endl;
	}

}

void Graph::DFS(int s)
{
	visit[s] = true;
	tot[s] = 1;
	//cout << s+1 << endl;
	list <int>::iterator i;
	for(i=adj[s].begin(); i!=adj[s].end(); i++)
	{
		if(!visit[*i])
		{
			DFS(*i);
			tot[s]+= tot[*i];
		}
	}
}

void Graph::disptot()
{
	tot[0]-= 1;
	for(int j=0; j<V; j++)
	{
		cout << tot[j] << " ";
	}
	cout << endl;
}

int main()
{
	int n, u, v;
	cin >> n;
	Graph g(n);
	for(int i=0; i<n-1; i++)
	{
		cin >> u >> v;
		g.addEdge(u-1, v-1);
	}
	
	g.DFS(0);
	g.disptot();
	return 0;
}