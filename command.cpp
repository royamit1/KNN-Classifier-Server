
#include "command.h"
#include "connectionUtil.h"

using namespace std;

// constructors for commands


/**
 * This is the constructor for command - the father class
 * @param dio - DefaultIO object
 * @param description - the description of the ccommand
 */
command::command(DefaultIO *dio, string description) {
    this->dio = dio;
    this->description = description;
}

/**
 * This is the constructor for update command
 * @param dio - DefaultIO object
 */
update::update(DefaultIO *dio) : command(dio, "1. upload an unclassified csv data file") {}

/**
 * This is the constructor for algoSettings command
 * @param dio - DefaultIO object
 */
algoSettings::algoSettings(DefaultIO *dio) : command(dio, "2. algorithm settings") {}

/**
 * This is the constructor for classify command
 * @param dio - DefaultIO object
 */
classify::classify(DefaultIO *dio) : command(dio, "3. classify data") {}

/**
 * This is the constructor for results command
 * @param dio - DefaultIO object
 */
results::results(DefaultIO *dio) : command(dio, "4. display results") {}

/**
 * This is the constructor for download command
 * @param dio - DefaultIO object
 */
download::download(DefaultIO *dio) : command(dio, "5. download results") {}

/**
 * This is the constructor for exitProg command
 * @param dio - DefaultIO object
 */
exitProg::exitProg(DefaultIO *dio) : command(dio, "8. exit") {}


// execute for each command

void update::execute() {}

void algoSettings::execute() {}

void classify::execute() {}

void results::execute() {}

void download::execute() {}

void exitProg::execute() {}
