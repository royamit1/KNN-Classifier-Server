
#include "command.h"
#include "connectionUtil.h"
#include "validations.h"

using namespace std;

// constructors for commands

/**
 * This is the constructor for command - the father class
 * @param dio - DefaultIO object
 * @param description - the description of the command
 */
command::command(DefaultIO *dio, string description) {
    this->dio = dio;
    this->description = description;
}

string command::getDes() { return this->description; }

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

void update::execute(ShareData *data) {

    dio->write("Please upload your local train CSV file.");
    data->setClassifiedData(dio->read());
    dio->write("Upload complete.");
    dio->write("Please upload your local test CSV file.");
    data->setUnClassifiedData(dio->read());
    dio->write("Upload complete.");

}

void algoSettings::execute(ShareData *data) {
    dio->write("The current KNN parameters are: K = " + to_string(data->getK()) + ", distance metric = " +
               data->getMetric() + ".");
    int result;
    const string userInput = dio->read();

    if (!userInput.empty()) {
        size_t first_index = userInput.find_first_of(' ');
        result = checkAlgoSettingsInput(userInput);
        if (result == 1) {
            dio->write("invalid value for K");
        } else if (result == 2) {
            dio->write("invalid value for metric");
        } else if (result == 3) {
            dio->write("invalid value for K");
            dio->write("invalid value for metric");
        } else {
            data->setK(stoi(userInput.substr(0, first_index)));
            data->setMetric(userInput.substr(first_index + 1, userInput.length()));
        }
    }
}


void classify::execute(ShareData *data) {

    data->setAllClassVec(fileToVec(data->getClassifiedData(), true));
    data->setAllUnClassVec(fileToVec(data->getUnClassifiedData(), false));

    for (int i = 0; i < data->getAllUnClassVec().size(); ++i) {
        data->getAllUnClassVec()[i]->setClass(getClassification(data->getAllClassVec(),
                                                                data->getMetric(), data->getK(),
                                                                data->getAllUnClassVec()[i]->getCurrVec()));
    }
    dio->write("classifying data complete.");
    dio->write("please upload data.");

}

void results::execute(ShareData *data) {
    if (data->getClassifiedData().empty() && data->getUnClassifiedData().empty()) {
        dio->write("please upload data.");
    }
    dio->write("please classify the data.");
    int i = 1;
    for (auto &clsVec: data->getAllUnClassVec()) {
        dio->write(to_string(i) + "\t" + clsVec->getClass());
        i++;
    }
    dio->write("Done.");
}

void download::execute(ShareData *data) {

}

void exitProg::execute(ShareData *data) {}
