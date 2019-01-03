
#ifndef BIUPROJECT2_FILECACHEMANAGER_H
#define BIUPROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"

using namespace std;

class FileCacheManager : public CacheManager {
private:
    string filePath;
public:
    explicit FileCacheManager(string path) {
        filePath = path;
    }
    bool isSolutionExists(std::string problem) override;
    std::string getSolution(std::string problem) override;
    void saveSolution(std::string problem, std::string solution) override;
};


#endif //BIUPROJECT2_FILECACHEMANAGER_H
