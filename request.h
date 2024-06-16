/**
 * @file request.h
 * @author Evan Wu
 * @brief Header file for the request class
 * @version 0.1
 * @date 2024-06-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string>
using namespace std;

class Request {
public:
	Request();
	Request(string ipIn, string ipOut, int time);
    string ipInput;
    string ipOutput;
    int timeToProcess;
};