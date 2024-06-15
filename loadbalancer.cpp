/**
 * @file loadbalancer.cpp
 * @author Evan Wu
 * @brief The CPP file for the load balancer class
 * @version 0.1
 * @date 2024-06-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "loadbalancer.h"
#include <cmath>

/**
 * @brief Construct a new Load Balancer with parameters:: Load Balancer object
 * 
 * @param serverCount The number of servers this load balancer will manage
 * @param time The total number of clock cycles this load balancer will run for
 */
LoadBalancer::LoadBalancer(int serverCount, int time) {
    for(int i = 1; i <= serverCount; i++) {
        serverList.push_back(Server(i));
    }

    for (int i = 0; i < 100 * serverCount; i++) {
        requestQueue.push(Request(createIP(), createIP(), rand() % 10 + 1));
    }
    numServersActive = serverCount;
    clockCount = time;
}

/**
 * @brief Create a new IP address and return it
 * 
 * @return string IP address
 */
string LoadBalancer::createIP() {
    return to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);    
}

/**
 * @brief Add a number of requests to the request queue.
 * The input and output IPs are generated by createIP() and the time it takes to process is randomly chose between 1 - 10 clock cycles.
 * 
 * @param numRequests The number of requests to add
 */
void LoadBalancer::addRequests(int numRequests) {
    for (int i = 0; i < numRequests; i++) {
        requestQueue.push(Request(createIP(), createIP(), rand() % 10 + 1));
    }
}

/**
 * @brief Set the number of active servers based on the size of the request queue divided by 100. 
 * If the number calculated is not between the min/max number of servers which are 1 and the total number of servers respectively, switch to it.
 * 
 */
void LoadBalancer::setActiveServers() {
    int reqsPerServer = round(requestQueue.size() / 100.0);
    if (reqsPerServer > serverList.size()) {
        reqsPerServer = serverList.size();
    } else if (reqsPerServer < 1) {
        reqsPerServer = 1;
    }
    
    numServersActive = reqsPerServer;
}

/**
 * @brief runs the loadbalancer by iterating through the total number of clock cycles. 
 * For each clock cycle, iterate through the number of active servers and check if the server is currently busy or not.
 * If the server is busy, check if the request is done by seeing if the current clock cycle is greater or equal than the clock cycle the request was received plus the number of clock cycles it takes to process.
 * If the server isn't busy, assign a new request to it from the request queue if it isn't empty.
 * After iterating through the active servers, set the new number of active servers by calling the setActiveServers() function.
 * Lastly, have a 20% random chance to add a number of new requests between 1 and the total number of servers to the queue. 
 * 
 */
void LoadBalancer::runLoadBalancer() {
    for (int curClock = 1; curClock <= clockCount; curClock++) {
        for (int idx = 0; idx < numServersActive; idx++)
        {
            if (serverList[idx].isBusy) {
                if ((serverList[idx].receivedRequestTime + serverList[idx].curRequest.timeToProcess) <= curClock) {
                    serverList[idx].isBusy = false;
                    requestLogs.push_back({serverList[idx].curRequest, serverList[idx].serverNumber, serverList[idx].receivedRequestTime});
                }
            } else {
                if (!requestQueue.empty()) {
                    serverList[idx].curRequest = requestQueue.front();
                    requestQueue.pop();
                    serverList[idx].receivedRequestTime = curClock;
                    serverList[idx].isBusy = true;
                }
            }
        }

        setActiveServers();
        
        if(rand() % 5 == 0) {
            addRequests(rand() % serverList.size() + 1);
        }
    }
    
}