#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <string>
#include <iomanip>

using namespace std;

const double PI_CONST = 3.14159265358979323846;

double convertToRadians(double angleInDegrees) {
    return angleInDegrees * PI_CONST / 180.0;
}

struct Locator {
    int deviceID;
    vector<pair<int, pair<int, int>>> connectedDevices;  // (device_id, (distance, angle))
    double xCoord, yCoord;
    bool isVisited;
};

double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void exploreDevice(Locator& currentDevice, unordered_map<int, Locator>& allDevices) {
    if (currentDevice.isVisited) return;
    currentDevice.isVisited = true;

    for (auto& connection : currentDevice.connectedDevices) {
        int connectedDeviceID = connection.first;
        int distanceToConnected = connection.second.first;
        int angleToConnected = connection.second.second;

        double radians = convertToRadians(angleToConnected);
        double deltaX = distanceToConnected * cos(radians);
        double deltaY = distanceToConnected * sin(radians);

        if (allDevices.find(connectedDeviceID) != allDevices.end() && !allDevices[connectedDeviceID].isVisited) {
            allDevices[connectedDeviceID].xCoord = currentDevice.xCoord + deltaX;
            allDevices[connectedDeviceID].yCoord = currentDevice.yCoord + deltaY;
            exploreDevice(allDevices[connectedDeviceID], allDevices);
        }
    }
}

int main() {
    int totalDevices;
    cin >> totalDevices;

    unordered_map<int, Locator> devicesMap;
    
    for (int i = 0; i < totalDevices; i++) {
        int deviceIdentifier, numberOfConnections;
        cin >> deviceIdentifier >> numberOfConnections;
        devicesMap[deviceIdentifier] = Locator{deviceIdentifier, {}, 0, 0, false};  // Initialize the device
        
        for (int j = 0; j < numberOfConnections; j++) {
            int connectedDeviceID, distance, angle;
            cin >> connectedDeviceID >> distance >> angle;
            devicesMap[deviceIdentifier].connectedDevices.push_back({connectedDeviceID, {distance, angle}});
        }
    }

    int startDeviceID, endDeviceID;
    cin >> startDeviceID >> endDeviceID;

    devicesMap[startDeviceID].xCoord = 0;
    devicesMap[startDeviceID].yCoord = 0;

    exploreDevice(devicesMap[startDeviceID], devicesMap);

    double finalDistance = calculateDistance(devicesMap[startDeviceID].xCoord, devicesMap[startDeviceID].yCoord, 
                                            devicesMap[endDeviceID].xCoord, devicesMap[endDeviceID].yCoord);
    
    cout << fixed << setprecision(2) << finalDistance << endl;
    
    return 0;
}
