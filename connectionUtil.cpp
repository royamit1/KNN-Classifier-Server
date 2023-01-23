
#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include "connectionUtil.h"

#define BUFFERSIZE 4096
using namespace std;

/**
 * This function writes to cout
 * @param s - string to write to cout
 */
void StandardIO::write(string s) {
    cout << s << "\n";
}

/**
 * This function reads from cin
 * @return - the string input
 */
string StandardIO::read() {
    string x;
    getline(cin, x);
    return x;
}

/**
 * setter for the socket number
 * @param sock - socket number
 */
void SocketIO::setSock(int sock) {
    this->sock = sock;
}
void SocketIO::setClientSock(int client_sock){
    this->client_sock=client_sock;
}

string SocketIO::read() {
    //char buffer[BUFFERSIZE] = "\0";
    char buffer='0';
    string s;
    while(true){
        recv(client_sock,&buffer,sizeof(char),0);
        if(buffer=='$')
            break;
        s+=buffer;
    }
    //int expected_data_len = sizeof(buffer);
    //int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    //return convertCharToString(buffer, read_bytes);
    return s;
}

void SocketIO::write(string s) {
    char buffer[BUFFERSIZE] = "\0";
    strcpy(buffer, s.c_str());
    send(client_sock, buffer, s.length()+1, 0);
    sleep(1);
}

/**
 * converts character array to string and returns it
 * @param a - the char array
 * @param size - size of the array
 * @return - the string
 */
string convertCharToString(char *a, int size) {
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

/**
 * getter for the path of the classified vectors file
 * @return - the path of the classified vectors file
 */
string ShareData::getClassifiedData() const {
    return this->classifiedData;
}

/**
 * setter for the path of the classified vectors file
 * @param s - new path to classified vectors file
 */
void ShareData::setClassifiedData(string s) {
    this->classifiedData = s;
}

/**
 * getter for the path of the unclassified vectors file
 * @return - the path of the unclassified vectors file
 */
string ShareData::getUnClassifiedData() const {
    return this->unClassifiedData;
}

/**
 * setter for the path of the unclassified vectors file
 * @param s - new path to unclassified vectors file
 */
void ShareData::setUnClassifiedData(string s) {
    this->unClassifiedData = s;
}

/**
 * getter for the number of neighbors (k)
 * @return - the number of neighbors
 */
int ShareData::getK() const {
    return this->k;
}

/**
 * setter for the number of neighbors (k)
 * @param k - new number of neighbors
 */
void ShareData::setK(int k) {
    this->k = k;
}

/**
 * getter for the metric
 * @return - the metric
 */
string ShareData::getMetric() const {
    return this->metric;
}

/**
 * setter for the metric
 * @param met - a new metric
 */
void ShareData::setMetric(string met) {
    this->metric = met;
}

/**
 * getter for the classified vectors vector
 * @return vector that holds all the classified vectors
 */
vector<classifiedVector *> ShareData::getAllClassVec() const {
    return this->allClassVec;
}

/**
 * setter for the classified vectors vector
 * @param allClsVec - vector that holds all the classified vectors
 */
void ShareData::setAllClassVec(vector<classifiedVector *> allClsVec) {
    this->allClassVec = allClsVec;
}

/**
 * getter for the unclassified vectors vector
 * @return vector that holds all the unclassified vectors
 */
vector<classifiedVector *> ShareData::getAllUnClassVec() const {
    return this->allUnClassVec;
}

/**
 * setter for the unclassified vectors vector
 * @param allUnClsVec - vector that holds all the unclassified vectors
 */
void ShareData::setAllUnClassVec(vector<classifiedVector *> allUnClsVec) {
    this->allUnClassVec = allUnClsVec;
}


int connectToClient(int sock) {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) {
        cout << "error accepting client" << endl;
        exit(1);
    }
    return client_sock;
}