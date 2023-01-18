
#ifndef SERVER_CPP_COMMAND_H
#define SERVER_CPP_COMMAND_H

#include <string>
#include "connectionUtil.h"

using namespace std;

/**
 *
 */
class command {
protected:

    string description;
    DefaultIO *dio;

public:
    command(DefaultIO *dio, string description);

    virtual ~command() = default;

    virtual void execute() = 0;
};

/**
 *
 */
class update : public command {

public:
    update(DefaultIO *dio);

    ~update() override = default;

    void execute() override;
};

/**
 *
 */
class algoSettings : public command {

    string description;

public:
    algoSettings(DefaultIO *dio);

    ~algoSettings() override = default;

    void execute() override;
};

/**
 *
 */
class classify : public command {

    string description;

public:
    classify(DefaultIO *dio);

    ~classify() override = default;

    void execute() override;
};

/**
 *
 */
class results : public command {

    string description;

public:
    results(DefaultIO *dio);

    ~results() override = default;

    void execute() override;
};

/**
 *
 */
class download : public command {

    string description;

public:
    download(DefaultIO *dio);

    ~download() override = default;

    void execute() override;
};

/**
 *
 */
class exit : public command {

    string description;

public:
    exit(DefaultIO *dio);

    ~exit() override = default;

    void execute() override;
};

#endif //SERVER_CPP_COMMAND_H
