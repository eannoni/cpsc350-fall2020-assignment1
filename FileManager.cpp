#include "FileManager.h"

// default constructor
FileManager::FileManager() {}

// destructor
FileManager::~FileManager() {
    inputFile.close();
    outputFile.close();
}

// input file methods

bool FileManager::openInputFile(string fileName) {
    inputFile.open(fileName);
    return inputFile.is_open();
}

void FileManager::fileRead1(DataManager *dm) {
    string dnaString;
    int lineCount = 0;
    int lengthSum = 0;

    while(!inputFile.eof()) {
        inputFile >> dnaString;
        if(!inputFile.fail()) {
            lineCount++;
            lengthSum += dnaString.length();

            dm->processString(dnaString);
        }
    }

    dm->calculateMean(lengthSum, lineCount);
}

void FileManager::fileRead2(DataManager *dm) {
    string dnaString;
    float varianceSum = 0.0;
    float mean = dm->getMean();

    while(!inputFile.eof()) {
        inputFile >> dnaString;
        if(!inputFile.fail())
            varianceSum += pow((float)dnaString.length() - mean, 2);
    }

    dm->calculateVarianceAndStdDev(varianceSum);
}

void FileManager::closeInputFile() {
    inputFile.close();
}

// output file methods

bool FileManager::openOutputFile(string fileName) {
    outputFile.open(fileName);
}

void FileManager::fileWriteHeader() {
    string header = "Eli Annoni";
    header += "\n2348182";
    header += "\nannoni@chapman.edu";
    header += "\nCPSC 350-01";
    header += "\n\n\n--------------- DNA OUTPUT FILE ---------------\n\n";
    outputFile << header;
}

void FileManager::fileWriteData(DataManager *dm) {
    string output = dm->getOutput();
    outputFile << output;
}

void FileManager::fileWriteDNAGeneration(DataManager *dm) {
    int generatedLength;
    outputFile << "Generated DNA:\n\n";
    for(int i = 0; i < 1000; ++i) {
        generatedLength = dm->getGaussianDistribution();
        for(int j = 0; j < generatedLength; ++j) {
            outputFile << dm->generateNucleotide();
        }
        outputFile << endl;
    }
    outputFile << "\n\n-----------------------------------------------\n\n\n";
}

void FileManager::closeOutputFile() {
    outputFile.close();
}
