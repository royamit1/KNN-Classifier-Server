
#include "command.h"
#include "connectionUtil.h"

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

/**
 * This is the constructor for update command
 * @param dio - DefaultIO object
 */
update::update(DefaultIO *dio) : command(dio, "1. upload an unclassified csv data file") {}

/**
 * @return - the description of a command
 */
string update::getDes() { return this->description; }


/**
 * This is the constructor for algoSettings command
 * @param dio - DefaultIO object
 */
algoSettings::algoSettings(DefaultIO *dio) : command(dio, "2. algorithm settings") {}

/**
 * @return - the description of a command
 */
string algoSettings::getDes() { return this->description; }


/**
 * This is the constructor for classify command
 * @param dio - DefaultIO object
 */
classify::classify(DefaultIO *dio) : command(dio, "3. classify data") {}

/**
* @return - the description of a command
*/
string classify::getDes() { return this->description; }


/**
 * This is the constructor for results command
 * @param dio - DefaultIO object
 */
results::results(DefaultIO *dio) : command(dio, "4. display results") {}

/**
 * @return - the description of a command
 */
string results::getDes() { return this->description; }

/**
 * This is the constructor for download command
 * @param dio - DefaultIO object
 */
download::download(DefaultIO *dio) : command(dio, "5. download results") {}

/**
 * @return - the description of a command
 */
string download::getDes() { return this->description; }

/**
 * This is the constructor for exitProg command
 * @param dio - DefaultIO object
 */
exitProg::exitProg(DefaultIO *dio) : command(dio, "8. exit") {}

/**
 * @return - the description of a command
 */
string exitProg::getDes() { return this->description; }


// execute for each command

void update::execute(ShareData *data) {

    dio->write("Please upload your local train CSV file.\n");
    data->setUnClassifiedData(dio->read());
    dio->write("Upload complete.\n");
    dio->write("Please upload your local test CSV file.\n");
    data->setClassifiedData(dio->read());
    dio->write("Upload complete.\n");

}

void algoSettings::execute(ShareData *data) {
    string k = to_string(data->getK());
    dio->write("The current KNN parameters are: k = " + k + ", distance metric = " + data->getMetric() + ".\n");
    if (!dio->read().empty()) {
        //TODO - need to check that the input is valid

    }
}

void classify::execute(ShareData *data) {

    dio->write("classifying data complete.\n");
    dio->write("please upload data.\n");

}

void results::execute(ShareData *data) {

    dio->write("please upload data.\n");
    dio->write("please classify the data.\n");

}

void download::execute(ShareData *data) {

}

void exitProg::execute(ShareData *data) {

}
