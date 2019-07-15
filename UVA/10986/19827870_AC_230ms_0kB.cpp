#include <iostream>
#include <list>
#include <queue>
#define infinite 2147483647

using namespace std;

class Graph {
private:
    int V; //num of servers
    list<pair<int, int> > * graph; //arr containing connections of cables and the weight

public:
    Graph(int V){
        this->V = V;
        graph = new list<pair<int, int>>[V];
    }

    void addLatency(int server1, int server2, int latency) {
        graph[server1].push_back(make_pair(server2, latency));
        graph[server2].push_back(make_pair(server1, latency));
    }

    int Dijkstra(int serverInit, int serverFin) {
        int dist[this->V];
        bool vis[this->V];
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQueue; // dist, cable

        for (int i = 0; i < V; i++) {
            vis[i] = false;
            dist[i] = infinite;
        }

        dist[serverInit] = 0;
        pQueue.push(make_pair(dist[serverInit], serverInit));

        while (!pQueue.empty()) {

            pair<int, int> p = pQueue.top();
            int cablePair = p.second;
            pQueue.pop();

            if (vis[cablePair] == false) {

                vis[cablePair] = true;
                list<pair<int, int>>::iterator i;

                for (i = graph[cablePair].begin(); i != graph[cablePair].end(); i++) {

                    int cable2 = i->first;
                    int latency = i->second;

                    if (dist[cable2] > (dist[cablePair] + latency)) {
                        dist[cable2] = dist[cablePair] + latency;
                        pQueue.push(make_pair(dist[cable2], cable2));
                    }
                }
            }
        }
        return dist[serverFin];

    }
};

int main() {
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; i++) {
        int amountServer, amountCable, initialServer, finalServer;
        cin >> amountServer;
        cin >> amountCable;
        cin >> initialServer;
        cin >> finalServer;
        Graph graph(amountServer);
        int server1,server2, latency;

        for (int j = 0; j < amountCable; j++) {
            cin >> server1;
            cin >> server2;
            cin >> latency;
            graph.addLatency(server1, server2, latency);
        }
        int minSize = graph.Dijkstra(initialServer, finalServer);
        if (minSize != infinite) {
            cout << "Case #" << i + 1 << ": " << minSize << endl;
        } else {
            cout << "Case #" << i + 1 << ": " << "unreachable" << endl;
        }

    }


    return 0;
}