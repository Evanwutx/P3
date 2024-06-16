/**
 * @file server.h
 * @author Evan Wu
 * @brief Header file for the server class
 * @version 0.1
 * @date 2024-06-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "request.h"
using namespace std;

class Server {
public:
	Server();
    Server(int serverNum);
    int serverNumber;
    Request curRequest;
    bool isBusy;
    int receivedRequestTime;
};