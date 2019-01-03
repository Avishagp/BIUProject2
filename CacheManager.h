
#ifndef BIUPROJECT2_CACHEMANAGER_H
#define BIUPROJECT2_CACHEMANAGER_H

#include <string>


class CacheManager {
public:
    virtual bool isSolutionExists(std::string problem) = 0;
    virtual std::string getSolution(std::string problem) = 0;
    virtual void saveSolution(std::string problem, std::string solution) = 0;
};


#endif //BIUPROJECT2_CACHEMANAGER_H
