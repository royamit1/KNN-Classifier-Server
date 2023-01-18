
#include "CLI.h"

/**
 * This is the constructor of CLI
 * We fill the vector with all the commands
 * @param dio - DefaultIO object
 */
CLI::CLI(DefaultIO *dio) {
    this->dio = dio;
    commands.push_back(new update(dio));
    commands.push_back(new algoSettings(dio));
    commands.push_back(new classify(dio));
    commands.push_back(new results(dio));
    commands.push_back(new download(dio));
    commands.push_back(new exitProg(dio));
}

/**
 * This is the destructor
 */
CLI::~CLI() {
    for (auto & command : commands) {
        delete command;
    }
}

/**
 * This function presents the selection options to the user
 */
void CLI::start() {



}
