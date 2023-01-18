
#include<iostream>
#include <string.h>

#include <fstream>
#include <vector>
#include "connectionUtil.h"

#define BUFFERSIZE 4096
using namespace std;

void StandardIO::write(string s) {
    cout << s << "\n";
}

string StandardIO::read() {
    string x;
    cin >> x;
    return x;
}

void SocketIO::setSock(int sock) {
    this->sock = sock;
}

string SocketIO::read() {
    char buffer[BUFFERSIZE] = "\0";
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    return convertCharToString(buffer, read_bytes);
}

void SocketIO::write(string s) {
    char buffer[BUFFERSIZE] = "\0";
    strcpy(buffer, s.c_str());
    send(sock, buffer, s.length(), 0);
}

string ShareData::getClassifiedData() const {
    return this->classifiedData;
}

void ShareData::setClassifiedData(string s) {
    this->classifiedData = s;
}

string ShareData::getUnClassifiedData() const {
    return this->unClassifiedData;
}

void ShareData::setUnClassifiedData(string s) {
    this->unClassifiedData = s;
}

string convertCharToString(char *a, int size) {
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int ShareData::getK() const {
    return this->k;
}

void ShareData::setK(int k) {
    this->k = k;
}

string ShareData::getMetric() const {
    return this->metric;
}

void ShareData::setMetric(string metric) {
    this->metric = metric;
}