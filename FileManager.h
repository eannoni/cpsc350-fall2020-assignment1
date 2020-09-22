#include "DataManager.h"

#include <fstream>

using namespace std;

class FileManager {

    public:
        FileManager(); // default constructor
        ~FileManager(); // destructor

        // input file methods
        bool openInputFile(string fileName);
        void fileRead1(DataManager *dm);
        void fileRead2(DataManager *dm);
        void closeInputFile();

        // output file methods
        bool openOutputFile(string fileName);
        void fileWriteHeader();
        void fileWriteData(DataManager *dm);
        void fileWriteDNAGeneration(DataManager *dm);
        void closeOutputFile();

    private:
        ifstream inputFile;
        ofstream outputFile;
};
