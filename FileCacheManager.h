
#ifndef BIUPROJECT2_FILECACHEMANAGER_H
#define BIUPROJECT2_FILECACHEMANAGER_H

#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include "CacheManager.h"

using namespace std;

class FileCacheManager : public CacheManager {
private:

    //// Members:
    string filePath;
    std::unordered_map<std::string, std::string> solutions;

    //// Private Functions:
    void loadAllSolutions();
public:

    //// Public Functions:
    explicit FileCacheManager(std::string);
    virtual bool isSolutionExists(std::string);
    virtual std::string getSolution(std::string);
    virtual void saveSolution(std::string, std::string);

    ~FileCacheManager() {};
};


#endif //BIUPROJECT2_FILECACHEMANAGER_H
