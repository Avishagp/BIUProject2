
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
    string filePath;
    std::unordered_map<std::string, std::string> solutions;
    void loadAllSolutions();
public:
    explicit FileCacheManager(std::string);
    virtual bool isSolutionExists(std::string);
    virtual std::string getSolution(std::string);
    virtual void saveSolution(std::string, std::string);
};


#endif //BIUPROJECT2_FILECACHEMANAGER_H
