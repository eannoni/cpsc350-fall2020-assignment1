#include "DataManager.h"

// default constructor
DataManager::DataManager() {

    lineCount = 0;
    lengthSum = 0;
    mean = 0.0;
    varianceSum = 0.0;
    variance = 0.0;
    stdDev = 0.0;

    totalNucleotides = 0;
    totalBigrams = 0;

    countA = 0;
    countC = 0;
    countT = 0;
    countG = 0;

    countAA = 0;
    countAC = 0;
    countAT = 0;
    countAG = 0;
    countCA = 0;
    countCC = 0;
    countCT = 0;
    countCG = 0;
    countTA = 0;
    countTC = 0;
    countTT = 0;
    countTG = 0;
    countGA = 0;
    countGC = 0;
    countGT = 0;
    countGG = 0;

    probA = 0.0;
    probC = 0.0;
    probT = 0.0;
    probG = 0.0;

    probAA = 0.0;
    probAC = 0.0;
    probAT = 0.0;
    probAG = 0.0;
    probCA = 0.0;
    probCC = 0.0;
    probCT = 0.0;
    probCG = 0.0;
    probTA = 0.0;
    probTC = 0.0;
    probTT = 0.0;
    probTG = 0.0;
    probGA = 0.0;
    probGC = 0.0;
    probGT = 0.0;
    probGG = 0.0;
}

// destructor
DataManager::~DataManager() {}

void DataManager::calculateMean(int lengthSum, int lineCount) {
    this->lengthSum = lengthSum;
    this->lineCount = lineCount;

    mean = ( (float)lengthSum / (float)lineCount );
}

void DataManager::calculateVarianceAndStdDev(float varianceSum) {
    this->varianceSum = varianceSum;

    variance = (varianceSum / (float)lineCount);
    stdDev = sqrt(variance);
}

// iterate through string and determine nucleotides and bigrams
void DataManager::processString(string dnaString) {

    int length = dnaString.length();

    totalNucleotides += length;
    totalBigrams += (length+1)/2;

    for(int i = 0; i < length - 1; i += 2) {
        addNucleotide(dnaString[i]);
        addNucleotide(dnaString[i + 1]);

        addBigram(dnaString[i], dnaString[i+1]);
    }

    // if DNA string has odd number of nucleotides, add last one and the bigram is
    if(length % 2 == 1) {
        addNucleotide(dnaString[length - 1]);
        addBigram(dnaString[length - 1], dnaString[0]);
    }
}

void DataManager::addNucleotide(char nucleotide) {

    nucleotide = toupper(nucleotide);

    switch(nucleotide) {
        case 'A':
            countA++;
            break;
        case 'C':
            countC++;
            break;
        case 'T':
            countT++;
            break;
        case 'G':
            countG++;
            break;
        default:
            cout << "Error, unknown nucleotide" << endl;
    }
}

void DataManager::addBigram(char nucleotide1, char nucleotide2) {

    nucleotide1 = toupper(nucleotide1);
    nucleotide2 = toupper(nucleotide2);

    switch(nucleotide1) {
        case 'A':
            if(nucleotide2 == 'A') countAA++;
            else if(nucleotide2 == 'C') countAC++;
            else if(nucleotide2 == 'T') countAT++;
            else countAG++;
            break;
        case 'C':
            if(nucleotide2 == 'A') countCA++;
            else if(nucleotide2 == 'C') countCC++;
            else if(nucleotide2 == 'T') countCT++;
            else countCG++;
            break;
        case 'T':
            if(nucleotide2 == 'A') countTA++;
            else if(nucleotide2 == 'C') countTC++;
            else if(nucleotide2 == 'T') countTT++;
            else countTG++;
            break;
        case 'G':
            if(nucleotide2 == 'A') countGA++;
            else if(nucleotide2 == 'C') countGC++;
            else if(nucleotide2 == 'T') countGT++;
            else countGG++;
            break;
        default:
            cout << "Error, unknown nucleotide" << endl;
    }
}

void DataManager::calculateProbability() {
    probA = (float)countA / (float)totalNucleotides;
    probC = (float)countC / (float)totalNucleotides;
    probT = (float)countT / (float)totalNucleotides;
    probG = (float)countG / (float)totalNucleotides;

    probAA = (float)countAA / (float)totalBigrams;
    probAC = (float)countAC / (float)totalBigrams;
    probAT = (float)countAT / (float)totalBigrams;
    probAG = (float)countAG / (float)totalBigrams;
    probCA = (float)countCA / (float)totalBigrams;
    probCC = (float)countCC / (float)totalBigrams;
    probCT = (float)countCT / (float)totalBigrams;
    probCG = (float)countCG / (float)totalBigrams;
    probTA = (float)countTA / (float)totalBigrams;
    probTC = (float)countTC / (float)totalBigrams;
    probTT = (float)countTT / (float)totalBigrams;
    probTG = (float)countTG / (float)totalBigrams;
    probGA = (float)countGA / (float)totalBigrams;
    probGC = (float)countGC / (float)totalBigrams;
    probGT = (float)countGT / (float)totalBigrams;
    probGG = (float)countGG / (float)totalBigrams;
}

string DataManager::getOutput() {
    string output = "\nThe Sum of the length of the DNA strings is: " + to_string(lengthSum);
    output += "\nThe Mean of the length of the DNA strings is: " + to_string(mean);
    output += "\nThe Variance of the length of the DNA strings is: " + to_string(variance);
    output += "\nThe Standard Deviation of the length of the DNA strings is: " + to_string(stdDev);
    output += "\n\nHere is the relative probability of each nucleotide:\n";
    output += "\nA:\t" + to_string(probA);
    output += "\nC:\t" + to_string(probC);
    output += "\nT:\t" + to_string(probT);
    output += "\nG:\t" + to_string(probG);
    output += "\n\nHere is the relative probability of each nucleotide bigram:\n";
    output += "\nAA:\t" + to_string(probAA);
    output += "\nAC:\t" + to_string(probAC);
    output += "\nAT:\t" + to_string(probAT);
    output += "\nAG:\t" + to_string(probAG);
    output += "\nCA:\t" + to_string(probCA);
    output += "\nCC:\t" + to_string(probCC);
    output += "\nCT:\t" + to_string(probCT);
    output += "\nCG:\t" + to_string(probCG);
    output += "\nTA:\t" + to_string(probTA);
    output += "\nTC:\t" + to_string(probTC);
    output += "\nTT:\t" + to_string(probTT);
    output += "\nTG:\t" + to_string(probTG);
    output += "\nGA:\t" + to_string(probGA);
    output += "\nGC:\t" + to_string(probGC);
    output += "\nGT:\t" + to_string(probGT);
    output += "\nGG:\t" + to_string(probGG);
    output += "\n\n-----------------------------------------------\n\n\n";

    return output;
}

int DataManager::getGaussianDistribution() {
    float a = ( (float)rand() / (float)RAND_MAX );
    float b = ( (float)rand() / (float)RAND_MAX );
    float c = sqrt(-2 * log(a)) * cos(2 * M_PI * b);
    int d = (int)(stdDev * c + mean);
    return abs(d);
}

char DataManager::generateNucleotide() {
    float random = ( (float)rand() / (float)RAND_MAX );
    if(random < probA)
        return 'A';
    random -= probA;
    if(random < probC)
        return 'C';
    random -= probC;
    if(random < probT)
        return 'T';
    return 'G';
}

float DataManager::getMean() {
    return mean;
}
