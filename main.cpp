#include "FileManager.h"

using namespace std;

string fileName;
string outFileName = "annoni.out";

// sets user input and sets it equal to fileName
void setFileName() {
    cout << "Enter a different file name to open, or 'quit' to quit: ";
    cin >> fileName;
}

// loops until file is opened (returns true) or user enters 'quit' (returns false)
bool openFileFromUser(FileManager *fm) {
    bool isOpen;
    isOpen = fm->openInputFile(fileName);
    while(!isOpen) {
        if(fileName == "quit")
            return false;
        cout << "Could not locate file. ";
        setFileName();
        isOpen = fm->openInputFile(fileName);
    }
    return true;
}

// MAIN METHOD

int main(int argc, char** argv) {

    bool running = true;

    // get command line input
    if(argc != 2) {
        cout << "Invalid command line parameters, please enter a file name." << endl;
        return -1;
    } else {
        fileName = argv[1];
    }

    // instantiate FileManager, and initialize output file & header
    FileManager *fm = new FileManager();
    fm->openOutputFile(outFileName);
    fm->fileWriteHeader();

    // open fileName from user's input
    running = openFileFromUser(fm);

    while(running) {

        DataManager *dm = new DataManager();

        // first read
        fm->fileRead1(dm);
        dm->calculateProbability();
        fm->closeInputFile();

        // second read
        fm->openInputFile(fileName);
        fm->fileRead2(dm);
        fm->closeInputFile();

        // write to file annoni.out
        cout << "Writing..." << endl;
        fm->fileWriteData(dm);
        fm->fileWriteDNAGeneration(dm);
        cout << "Successfully wrote output to \'" << outFileName << "\'." << endl;

        delete dm;

        // prompt user again for input
        setFileName();
        running = openFileFromUser(fm);
    }

    cout << "\nQuitting program.\n" << endl;

    delete fm;

    return 0;
}
