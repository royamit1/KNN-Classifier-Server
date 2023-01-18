//
// Created by yoav on 1/17/23.
//
#include "connectionUtil.h"
#define BUFFERSIZE 4096
using namespace std;
void StandardIO::write(string s) {
    cout << s<<"\n";
}
string StandardIO::read() {
    string x;
    cin>> x;
    return x;
}
void SocketIO::setSock(int sock) {
    this->sock=sock;
}
string SocketIO::read() {
    char buffer[BUFFERSIZE] = "\0";
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    return convertCharToString(buffer,read_bytes);
}
void SocketIO::write(string s) {
    char buffer[BUFFERSIZE] = "\0";
    strcpy(buffer, s.c_str());
    send(sock,buffer, s.length(),0);
}

string ShareData::getClassifiedData(){
    return this->classifiedData;
}
void ShareData::setclassifiedData(string C){
    this->classifiedData=C;
}
string ShareData::getUnClassifiedData(){
    return this->unClassifiedData;
}
void ShareData::setUnClassifiedData(string S){
    this->unClassifiedData=S;
}
string convertCharToString(char *a, int size) {
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}