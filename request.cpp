/**
 * @file request.cpp
 * @author Evan Wu
 * @brief CPP file for the request class
 * @version 0.1
 * @date 2024-06-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "request.h"

/**
 * @brief Construct a new Request:: Request object
 * 
 */
Request::Request() {
    ipInput = "";
    ipOutput = "";
    timeToProcess = 0;
}

/**
 * @brief Construct a new Request with parameters:: Request object
 * 
 * @param ipIn Input IP address
 * @param ipOut Output IP address
 * @param time Number of clock cycles it takes to process this request
 */
Request::Request(string ipIn, string ipOut, int time) {
    ipInput = ipIn;
    ipOutput = ipOut;
    timeToProcess = time;
}
