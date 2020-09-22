#include <iostream>
#include <cmath>

using namespace std;

/* The DataManager class stores all critical data recieved from input files and
 * calculates all statistics.
*/
class DataManager {

    public:
        DataManager(); // default constructor
        ~DataManager(); // destructor

        // calculations
        void calculateMean(int lengthSum, int lineCount);
        void calculateVarianceAndStdDev(float varianceSum);
        void calculateProbability();

        // processes DNA and saves to nucleotide/bigram member variables
        void processString(string dnaString);
        void addNucleotide(char nucleotide);
        void addBigram(char nucleotide1, char nucleotide2);

        // returns statistic summary of file
        string getOutput();

        // DNA generation methods
        int getGaussianDistribution();
        char generateNucleotide();

        // accessors
        float getMean();

    private:

        // DNA statistics
        int lineCount;
        int lengthSum;
        float mean;
        float varianceSum;
        float variance;
        float stdDev;

        // total nucleotide and bigram counts
        int totalNucleotides;
        int totalBigrams;

        // singular nucleotide counts
        int countA;
        int countC;
        int countT;
        int countG;

        // nucleotide bigram counts
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

        // singular nucleotide probabilities
        float probA;
        float probC;
        float probT;
        float probG;

        // nucleotide bigram probabilities
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
