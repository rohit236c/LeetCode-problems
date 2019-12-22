#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Edge
{
public:
	int v = 0;
	int w = 0;

	Edge(int v, int w)
	{
		this->v = v;
		this->w = w;
	}

	Edge()
	{
	}
};

vector<vector<Edge *>> graph;

void addEdge(int u, int v, int w)
{
	if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size())
		return;

	graph[u].push_back(new Edge(v, w));
	graph[v].push_back(new Edge(u, w));
}

void display()
{
	for (int i = 0; i < graph.size(); i++)
	{
		cout << i << " => ";
		for (int j = 0; j < graph[i].size(); j++)
		{
			cout << "( " << graph[i][j]->v << ", " << graph[i][j]->w << "), ";
		}
		cout << endl;
	}
}

void removeEdge(int u, int v)
{
	int i = -1;
	int j = -1;

	for (int k = 0; k < graph[u].size(); k++)
	{
		if (graph[u][k]->v == v)
		{
			i = k;
			break;
		}
	}

	for (int k = 0; k < graph[v].size(); k++)
	{
		if (graph[v][k]->v == u)
		{
			j = k;
			break;
		}
	}

	graph[u].erase(graph[u].begin() + i);
	graph[v].erase(graph[v].begin() + j);
}

void removeVtx(int u)
{
	for (int i = graph[u].size() - 1; i >= 0; i--)
	{
		removeEdge(graph[u][i]->v, u);
	}

	// graph.erase(graph.begin()+u);
}

bool hasPath(int src, int des, vector<bool> &visited, string ans)
{
	if (visited[src])
		return false;

	if (src == des)
	{
		cout << ans << endl;
		return true;
	}

	visited[src] = true;
	bool res = false;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		res = res || hasPath(v, des, visited, ans + to_string(v) + "->");
	}

}

void hasPath_allPath(int src, int des, vector<bool> &visited, string ans)
{
	if (visited[src])
		return;

	if (src == des)
	{
		cout << ans << endl;
		return;
	}

	visited[src] = true;
	// bool res = false;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		if (!visited[v])
			hasPath_allPath(v, des, visited, ans + to_string(v) + "->");
	}

	visited[src] = false;
}
string dir = "";
int minW = 1e6;
void hasPath_allPath_minWeight(int src, int des, int w, vector<bool> &visited, string ans)
{
	if (visited[src])
		return;

	if (src == des)
	{
		if (minW > w && w != 0) {
			minW = w;
			dir = ans;
		}
		return;
	}

	visited[src] = true;
	// bool res = false;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		int wt = e -> w;
		if (!visited[v])
			hasPath_allPath_minWeight(v, des, w + wt, visited , ans + to_string(v) + "->");
	}

	visited[src] = false;
}
string dir_1 = "";
int maxW = 0;
void hasPath_allPath_maxWeight(int src, int des, int w, vector<bool> &visited, string ans)
{
	if (visited[src])
		return;

	if (src == des)
	{
		if (maxW < w) {
			maxW = w;
			dir_1 = ans;
		}
		return;
	}

	visited[src] = true;
	// bool res = false;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		int wt = e -> w;
		if (!visited[v])
			hasPath_allPath_maxWeight(v, des, w + wt, visited , ans + to_string(v) + "->");
	}

	visited[src] = false;
}
void printPreorder(int src, std::vector<bool> &visited, string ans) {

	//base case
	if (visited[src] == true) {
		return;
	}

	// if(ans.size() == 0) cout<<ans + to_string(src)<<endl;

	if (ans.size() != 0) cout << ans << endl;

	visited[src] = true;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		printPreorder(v, visited, ans + to_string(v) + "->");
	}
	visited[src] = false;
}
void printPostOrder(int src, std::vector<bool> &visited, string ans) {

	//base case
	if (visited[src] == true) {
		return;
	}

	visited[src] = true;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		printPostOrder(v, visited, ans + to_string(v) + "->");
	}
	cout << to_string(src) + "->" + ans << endl;
	visited[src] = false;
}

bool HasHamiltonianPath(int src, int curV , vector<bool> &visited, string ans, int vertices) {

	if (vertices == curV) {
		cout << ans << endl;
		return true;
	}
	visited[src] = true;
	bool res = false;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		if (!visited[v])
			res = res || HasHamiltonianPath(v, curV + 1 , visited, ans +  to_string(v) + "->" , vertices);
	}
	visited[src] = false;
	return res;

}
bool checkEdge(int src, int dest) {
	for (Edge *e : graph[src])
	{
		int v = e->v;
		if (v == dest) return true;
	}
	return false;
}
bool HasHamiltonianCycle(int src, int curV , int startSrc , vector<bool> &visited, string ans, int vertices) {

	if (vertices == curV) {
		if (checkEdge(startSrc, src)) {
			cout << ans << endl;
			cout << "Cycle Exist" << endl;
			return true;
		}
		return false;
	}
	visited[src] = true;
	bool res = false;
	for (Edge *e : graph[src])
	{
		int v = e->v;
		if (!visited[v])
			HasHamiltonianCycle(v, curV + 1 , startSrc , visited, ans +  to_string(v) + "->" , vertices);
	}
	visited[src] = false;
	return res;
}
priority_queue<int>pq;
void kthLargest(int src, int dest, int wt , std::vector<bool> &visited, int k) {

	if (src == dest) {
		pq.push(wt);
		return ;
	}

	visited[src] = true;

	for (Edge*e : graph[src]) {
		int v = e->v;
		int w = e->w;
		if (!visited[v]) {
			kthLargest(v, dest, wt + w, visited, k);
		}
	}
	visited[src] = false;
}


void solve()
{
	for (int i = 0; i < 7; i++)
	{
		vector<Edge *> ar;
		graph.push_back(ar);
	}

	addEdge(0, 3, 10);
	addEdge(0, 1, 10);
	addEdge(1, 2, 10);
	addEdge(2, 3, 40);
	addEdge(3, 4, 2);
	addEdge(4, 5, 2);
	// addEdge(5, 2, 2);
	addEdge(4, 6, 3);
	addEdge(5, 6, 8);

	// removeVtx(3);

	vector<bool> visited(graph.size(), false);
	// hasPath(0, 6, visited, to_string(0) + "->");
	// visited[0] = true;
	// printPostOrder(0, visited, "0->");
	// hasPath_allPath_minWeight(0, 6, 0, visited, to_string(0) + "->");
	// cout<<minW<<" @ ";
	// cout<<dir<<endl;
	// hasPath_allPath_maxWeight(0, 6, 0, visited, to_string(0) + "->");
	// cout<<maxW<<" @ ";
	// cout<<dir_1<<endl;
	// display();
	// int src = 2;
	// bool ans = HasHamiltonianPath(src, 1 , visited, to_string(src) + "->", 7);
	// bool ans = HasHamiltonianCycle(src, 1 , src ,visited, to_string(src) + "->", 7);
	// cout << ans;
	// int k = 1;
	// kthLargest(0, 6, 0, visited, 0);
	// while(k) {
	//     pq.pop();
	//     k--;
	// }
	// cout<<pq.top();
}

int main()
{
	solve();
	return 0;
}