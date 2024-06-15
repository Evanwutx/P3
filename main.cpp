#include <iostream>
#include <fstream> 
#include "loadbalancer.h"

int main() {
    srand(42);
    printf("Input the number of servers: ");
    string numServers;
    cin >> numServers;
    printf("Input the clock count: ");
    string clockCount;
    cin >> clockCount;

    LoadBalancer loadBalancer(atoi(numServers.c_str()), atoi(clockCount.c_str()));
    loadBalancer.runLoadBalancer();
    printf("Total finished requests: %d\n", loadBalancer.requestLogs.size());

    ofstream logFile("logs.txt");

    logFile << "Starting Queue Size: " + to_string(atoi(numServers.c_str()) * 100) + ", Ending Queue Size: " + to_string(loadBalancer.requestQueue.size()) + "\n";
    logFile << "Task Time Range: 1-10\n";

    for (int i = 0; i < loadBalancer.requestLogs.size(); i++) {
        logFile << "Log Number: " + to_string(i + 1) + ", Request IP In: " + get<0>(loadBalancer.requestLogs[i]).ipInput + 
        ", Request IP Out: " + get<0>(loadBalancer.requestLogs[i]).ipOutput + ", Server Number: " + to_string(get<1>(loadBalancer.requestLogs[i])) + 
        ", Time received: " + to_string(get<2>(loadBalancer.requestLogs[i])) + "\n";
    }
    

    logFile.close();
    return 0;
}