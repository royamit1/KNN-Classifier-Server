
#include "command.h"
#include "connectionUtil.h"

using namespace std;

command::command(DefaultIO *dio, string description) {
    this->dio = dio;
    this->description = description;
}

// constructors for commands

update::update(DefaultIO *dio) : command(dio, "1. upload an unclassified csv data file") {}

algoSettings::algoSettings(DefaultIO *dio) : command(dio, "2. algorithm settings") {}

classify::classify(DefaultIO *dio) : command(dio, "3. classify data") {}

results::results(DefaultIO *dio) : command(dio, "4. display results") {}

download::download(DefaultIO *dio) : command(dio, "5. download results") {}

exit::exit(DefaultIO *dio) : command(dio, "8. exit") {}


// execute for each command

void update::execute() {}

void algoSettings::execute() {}

void classify::execute() {}

void results::execute() {}

void download::execute() {}

void exit::execute() {}
