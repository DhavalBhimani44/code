#include <iostream>
#include <vector>
#include <climits>

using namespace std;

 pair<int, int> addTimes(pair<int, int> time1, pair<int, int> time2) {
    int totalMinutes = time1.first + time2.first;
    int totalSeconds = time1.second + time2.second;

    if (totalSeconds >= 60) {
        totalMinutes += totalSeconds / 60;
        totalSeconds = totalSeconds % 60;
    }

    return {totalMinutes, totalSeconds};
}

bool isShorter(pair<int, int> time1, pair<int, int> time2) {
    if (time1.first < time2.first) return true;
    if (time1.first == time2.first && time1.second < time2.second) return true;
    return false;
}

void floydWarshall(vector<vector<pair<int, int>>>& travelTimes, int numIntersections) {
    for (int k = 0; k < numIntersections; k++) {
        for (int i = 0; i < numIntersections; i++) {
            for (int j = 0; j < numIntersections; j++) {
                if (travelTimes[i][k].first != INT_MAX && travelTimes[k][j].first != INT_MAX) {
                    pair<int, int> newTime = addTimes(travelTimes[i][k], travelTimes[k][j]);
                    if (isShorter(newTime, travelTimes[i][j])) {
                        travelTimes[i][j] = newTime;
                    }
                }
            }
        }
    }
}

// Function to print the shortest travel times matrix
void printShortestTravelTimes(const vector<vector<pair<int, int>>>& travelTimes, int numIntersections) {
    cout << "Shortest travel times between every pair of intersections:\n";
    for (int i = 0; i < numIntersections; i++) {
        for (int j = 0; j < numIntersections; j++) {
            if (travelTimes[i][j].first == INT_MAX)
                cout << "INF\t";
            else
                cout << travelTimes[i][j].first << " min " << travelTimes[i][j].second << " sec\t";
        }
        cout << endl;
    }
}

int main() {
    int numIntersections;
    cout << "Enter the number of intersections: ";
    cin >> numIntersections;

    vector<vector<pair<int, int>>> travelTimes(numIntersections, vector<pair<int, int>>(numIntersections, {INT_MAX, 0}));

    for (int i = 0; i < numIntersections; i++) {
        travelTimes[i][i] = {0, 0};
    }

    int numRoutes;
    cout << "Enter the number of routes (direct connections between intersections): ";
    cin >> numRoutes;

    cout << "Enter each route in the format: intersection1 intersection2 minutes seconds\n";
    for (int i = 0; i < numRoutes; i++) {
        int src, dest, minutes, seconds;
        cin >> src >> dest >> minutes >> seconds;

        travelTimes[src][dest] = {minutes, seconds};
        travelTimes[dest][src] = {minutes, seconds};
    }

    floydWarshall(travelTimes, numIntersections);

    printShortestTravelTimes(travelTimes, numIntersections);

    return 0;
}
