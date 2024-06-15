/**
 * @file server.cpp
 * @author Evan Wu
 * @brief CPP file for the server class
 * @version 0.1
 * @date 2024-06-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "server.h"

/**
 * @brief Construct a new Server:: Server object
 * 
 */
Server::Server() {
    serverNumber = 0;
    isBusy = false;
}

/**
 * @brief Construct a new Server with parameters:: Server object
 * 
 * @param serverNum The server number identifier
 */
Server::Server(int serverNum) {
    serverNumber = serverNum;
    isBusy = false;
}