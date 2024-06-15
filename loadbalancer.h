/**
 * @file loadbalancer.h
 * @author Evan Wu
 * @brief The header file for the load balancer class
 * @version 0.1
 * @date 2024-06-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "server.h"
#include <vector>
#include <queue>
#include <cstdlib>
#include <tuple>

class LoadBalancer {
public: 
    LoadBalancer();
    LoadBalancer(int serverCount, int time);
    string createIP();
    void addRequests(int numRequests);
    void runLoadBalancer();
    void setActiveServers();

    vector<Server> serverList;
    queue<Request> requestQueue;
    vector<tuple<Request, int, int>> requestLogs;
    int numServersActive;
    int clockCount;
};