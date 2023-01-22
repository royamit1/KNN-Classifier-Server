
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
void CLI::start() {
    string strInput;
    int intInput;
    ShareData data;
    size_t i = 0;
    while (commands[i]->getDes()[0] != '8') {
        dio->write("Welcome to the KNN Classifier Server. Please choose an option:");
        for (int j = 0; j < commands.size(); ++j) {
            dio->write(commands[j]->getDes());
        }
        dio->write("");
        strInput = dio->read();
        if (strInput[0] >= '1' && strInput[0] <= '5') {
            intInput = stoi(strInput);
            commands[intInput - 1]->execute(&data);
            i = intInput;
        } else if (strInput[0] == '8') {
            commands[commands.size() - 1]->execute(&data);
            i = commands.size() - 1;
        } else {
            dio->write("Invalid input");
        }
    }
}
/**
 * This function presents the selection options to the user
 */
//void CLI::start() {
//    while (true){
//        string x=dio->read();
//        cout << x<<"\n";
//        dio->write(x);
//    }
//}