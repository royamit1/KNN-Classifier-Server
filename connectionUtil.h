//
// Created by yoav on 1/17/23.
//

#ifndef YOAV_ROY_ASS4_REPO_CONNECTIONUTIL_H
#define YOAV_ROY_ASS4_REPO_CONNECTIONUTIL_H
#include<iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;
class DefaultIO {
public:
    DefaultIO() = default;
    virtual void read()=0;
    virtual void write(string s)=0;
    virtual ~DefaultIO() = default;
};
class SocketIO : public DefaultIO{
public:
    void read() override;
    void write(string s) override;
    ~SocketIO() override = default;
    SocketIO()=default;
};
class StandardIO : public DefaultIO{
public:
    void read() override;
    void write(string s) override;
    ~StandardIO() override = default;
    StandardIO()=default;
};
class Cli{
private:
    DefaultIO* dio;
public:
     Cli(DefaultIO dio);
     void start();
     ~Cli()=default;
};
class ShareData{
private:
    string classifiedData;
    string unClassifiedData;
public:
    string getClassifiedData();
    void setclassifiedData();
    string getUnClassifiedData();
    void setUnClassifiedData();
};

#endif //YOAV_ROY_ASS4_REPO_CONNECTIONUTIL_H
