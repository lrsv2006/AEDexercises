#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <numeric>


int main() {
    std::string highwaylength;

    while (std::cin >> highwaylength) {

        int restaurantposition = 0;
        int drugstoreposition = 0;
        std::string drugandrest = "Z";
        int amountofR = 0;
        int amountofD = 0;

        std::vector<int> positionsR;
        std::vector<int> positionsD;


        int nHighwaylength = std::stoi(highwaylength);

        if (nHighwaylength == 0) {
            break;
        }
        std::string map;
        std::cin >> map;

        if (map.find(drugandrest) != std::string::npos) {
            std::cout << "0\n";


        } else {
            //find amount of R and D
            for (int i = 0; i < map.length(); i++) {
                if (map.at(i) == 'R') {
                    amountofR++;

                }

                if (map.at(i) == 'D') {
                    amountofD++;

                }
            }


            //find R and D positions n fill arrays w positions

            for (int i = 0; i < map.length(); i++) {
                //int newSize = positionsR.length + 1;
               // positionsR = Arrays.copyOf(positionsR, newSize);

               // int newSize2 = positionsD.length + 1;
               // positionsD = Arrays.copyOf(positionsD, newSize2);

                if (map.at(i) == 'R') {
                    positionsR.push_back(i+1);
                }

                if (map.at(i) == 'D') {
                    positionsD.push_back(i+1);
                }


            }


            if (amountofR == 1 && amountofD == 1) {


                while (((map.at(restaurantposition)) != 'R') && (restaurantposition <= map.length())) {
                    restaurantposition++;
                }

                while (((map.at(drugstoreposition)) != 'D') && (drugstoreposition <= map.length())) {
                    drugstoreposition++;
                }

                int distance = restaurantposition - drugstoreposition;

                if (distance < 0) {
                    distance = distance * (-1);
                }

                std:: cout << (distance) << "\n";
                restaurantposition = 0;
                drugstoreposition = 0;

            } else if ((amountofD > 1 && amountofR > 1) || (amountofD > 1 && amountofR == 1) || (amountofR > 1 && amountofD == 1)) {
                int positionR = 0;
                int positionD = 0;
                int distance = 999999999;
                int aux = 0;

                for (int i = 0; i < positionsR.size(); i++) {
                    if (positionsR[i] != 0) {
                        positionR = positionsR[i];

                        for (int j = 0; j < positionsD.size();j++) {
                            if (positionsD[j] != 0) {
                                positionD = positionsD[j];
                            }
                            aux = positionD - positionR;
                            if (aux < 0) {
                                aux = aux * (-1);
                            }

                            if (aux < distance) {
                                distance = aux;
                            }
                        }
                    }
                }

                std:: cout << distance << "\n";
            }
        }
    }
}