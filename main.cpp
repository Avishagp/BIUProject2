
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "SearchableMatrix.h"
#include "BestFirstSearch.h"

int main() {

    ISearchable<std::pair<int,int>>* a = new SearchableMatrix("1,2,3\n4,5,6\n7,8,9");
    ISearcher<std::pair<int,int>,std::string>* s = new BestFirstSearch<std::pair<int,int>,std::string>();
    s->search(a);
    delete(a);

    FileCacheManager fileCacheManager("bla.txt");
    StringReverser stringReverser;
    MyTestClientHandler myTestClientHandler(&stringReverser, &fileCacheManager);
    MySerialServer mySerialServer;
    mySerialServer.open(5400, &myTestClientHandler);
    while (true) {};
}
