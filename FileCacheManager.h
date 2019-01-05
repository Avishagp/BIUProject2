
#ifndef BIUPROJECT2_FILECACHEMANAGER_H
#define BIUPROJECT2_FILECACHEMANAGER_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "CacheManager.h"

using namespace std;

class FileCacheManager : public CacheManager {
private:
    string filePath;
    std::map<std::string, std::string> solutions;
    void loadAllSolutions();
public:
    explicit FileCacheManager(std::string);
    bool isSolutionExists(std::string) override;
    std::string getSolution(std::string) override;
    void saveSolution(std::string, std::string) override;
};


#endif //BIUPROJECT2_FILECACHEMANAGER_H
