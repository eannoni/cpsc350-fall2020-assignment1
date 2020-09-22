#include <iostream>
#include <cmath>

using namespace std;

class DataManager {

    public:
        DataManager(); // default constructor
        ~DataManager(); // destructor

        void calculateMean(int lengthSum, int lineCount);
        void calculateVarianceAndStdDev(float varianceSum);

        void processString(string dnaString);

        void addNucleotide(char nucleotide);
        void addBigram(char nucleotide1, char nucleotide2);
        void calculateProbability();

        string getOutput();

        int getGaussianDistribution();
        char generateNucleotide();

        float getMean();

    private:

        int lineCount;
        int lengthSum;
        float mean;
        float varianceSum;
        float variance;
        float stdDev;

        int totalNucleotides;
        int totalBigrams;

        int countA;
        int countC;
        int countT;
        int countG;

        int countAA;
        int countAC;
        int countAT;
        int countAG;
        int countCA;
        int countCC;
        int countCT;
        int countCG;
        int countTA;
        int countTC;
        int countTT;
        int countTG;
        int countGA;
        int countGC;
        int countGT;
        int countGG;

        float probA;
        float probC;
        float probT;
        float probG;

        float probAA;
        float probAC;
        float probAT;
        float probAG;
        float probCA;
        float probCC;
        float probCT;
        float probCG;
        float probTA;
        float probTC;
        float probTT;
        float probTG;
        float probGA;
        float probGC;
        float probGT;
        float probGG;
};
