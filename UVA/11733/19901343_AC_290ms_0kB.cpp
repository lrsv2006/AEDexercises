    #include <iostream>
    #include <algorithm>
    #include <vector>
    using namespace std;

    struct Road {
        int city1, city2, dist;
    };

    int father[10000];
    int weight[10000];

    Road roads[100000];
    Road mst[100000];


    int find(int city){
        if (father[city] == city) {
            return city;
        }
        return father[city] = find(father[city]);
    }

    void join(int city1, int city2){

        city1 = find(city1);
        city2 = find(city2);

        if (weight[city1] < weight[city2]) {
            father[city1] = city2;
        }
        else if (weight[city2] < weight[city1]) {
            father[city2] = city1;
        }
        else {
            father[city1] = city2;
            weight[city2]++;
        }

    }

    bool compare(Road a, Road b){
        return a.dist < b.dist;
    }



    int main() {
        int numCases;
        cin >> numCases;
        int numCities, numRoads, airportCost;
        int whichCase = 1;
        while (numCases > 0) {
            cin >> numCities >> numRoads >> airportCost;
            int amountAirports = 0;


            for (int i = 0; i < numRoads; i++) {
                cin >> roads[i].city1 >> roads[i].city2 >> roads[i].dist;
                roads[i].city1--;
                roads[i].city2--;
            }

            for (int i = 0; i < numCities; i++) {
                father[i] = i;
            }

            sort(roads, roads+numRoads, compare);
            int amountMST = 0;
            for (int i = 0; i < numRoads; i++) {
                if (find(roads[i].city1) != find(roads[i].city2)) {
                    join(roads[i].city1,roads[i].city2);
                    mst[i] = roads[i];
                }
                amountMST++;
            }
            numCases--;
            int totalCost = 0;

            int j;
            int components = 0;


            for (int i = 0; i < numCities; i++) {
                if (father[i] == i) {
                    components++;
                }
            }

            totalCost = totalCost + (components*airportCost);
            amountAirports = components;

            for (int i = 0; i < amountMST; i++) {
                if (mst[i].dist >= airportCost) {
                    totalCost+= airportCost;
                    amountAirports++;
                } else {
                    totalCost += mst[i].dist;
                }
            }


        // preciso ver se alguma tem estrada mais cara q o aeroporto, e se tiver, colocar um aeroporto e trocar de componente
            cout << "Case #" << whichCase << ": " << totalCost << " " << amountAirports << endl;
            for (int i = 0; i < numCities; i++) {
                weight[i] = 0;
            }
            for (int i = 0; i < numCities; i++) {
                father[i] = 0;
                weight[i] = 0;
            }
            for (int i = 0; i < numRoads; i++) {
                roads[i].city1 = 0;
                roads[i].city2 = 0;
                roads[i].dist = 0;
                mst[i].city1 = 0;
                mst[i].city2 = 0;
                mst[i].dist = 0;
            }

            whichCase++;
        }


        return 0;
    }