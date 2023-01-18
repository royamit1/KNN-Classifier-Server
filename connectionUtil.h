//
// Created by yoav on 1/17/23.
//

#ifndef YOAV_ROY_ASS4_REPO_CONNECTIONUTIL_H
#define YOAV_ROY_ASS4_REPO_CONNECTIONUTIL_H

#include<iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <bits/stdc++.h>
#include "validations.h"
#include "vectorData.h"


using namespace std;

class DefaultIO {
public:
    DefaultIO() = default;

    virtual string read() = 0;

    virtual void write(string s) = 0;

    virtual ~DefaultIO() = default;
};


class SocketIO : public DefaultIO{
    int sock;
public:
    void setSock(int sock);
    string read() override;
    void write(string s) override;
    ~SocketIO() override = default;
    SocketIO()=default;
};
class StandardIO : public DefaultIO{
public:
    string read() override;
    void write(string s) override;
    ~StandardIO() override = default;
    StandardIO()=default;
};

class ShareData{
private:
    string classifiedData;
    string unClassifiedData;
public:
    string getClassifiedData();
    void setclassifiedData(string C);
    string getUnClassifiedData();
    void setUnClassifiedData(string S);
};
string convertCharToString(char *a, int size);
#endif //YOAV_ROY_ASS4_REPO_CONNECTIONUTIL_H
