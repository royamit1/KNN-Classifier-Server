
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
    for (auto &command: commands) {
        delete command;
    }
}

/**
 * This function presents the selection options to the user
 */
void CLI::start() {
    string strInput;
    int intInput;
    ShareData data;
    dio->write("Welcome to the KNN Classifier Server. Please choose an option:\n");
    int i=0;
    while (commands[i]->getDes()[0] != '8') {
        for (int j = 0; j < 6; ++j) {
            dio->write(commands[j]->getDes() + "\n");
        }
        strInput = dio->read();
        if ((strInput >= "1" || strInput <= "5") || strInput == "8") {
            intInput = stoi(strInput);
            commands[intInput]->execute(&data);
        }

        //TODO - the server returns "invalid input" and go back to main menu
    }
}
