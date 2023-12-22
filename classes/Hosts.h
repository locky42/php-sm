#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Hosts { 
  private:
      std::string hostsPath = "storage/hosts";
  public:
    string getHostsPath() {
      return hostsPath;
    }

    void addHost(const string& hostToAdd, const string& ip = "127.0.0.1") {
      ifstream inFile(hostsPath);
      stringstream ss;
      string line;
      string newContent;

      if (inFile.is_open()) {
        while (getline(inFile, line)) {
          if (line.rfind(hostToAdd) == string::npos || line.rfind(hostToAdd) != line.size() - hostToAdd.size()) {
            newContent += line + "\n";
          }
        }
        inFile.close();
      }

      ofstream outFile(hostsPath);
      if (outFile.is_open()) {
        outFile << newContent;
        outFile << ip + "\t" + hostToAdd + "\n";
        outFile.close();
      }
    }

    void removeHost(const string& hostToRemove) {
      ifstream inFile(hostsPath);
      stringstream ss;
      string line;
      string newContent;

      if (inFile.is_open()) {
        while (getline(inFile, line)) {
          if (line.find(hostToRemove) == string::npos) {
            newContent += line + "\n";
          }
        }
        inFile.close();
      }

      ofstream outFile(hostsPath);
      if (outFile.is_open()) {
        outFile << newContent;
        outFile.close();
      }
    }
};
