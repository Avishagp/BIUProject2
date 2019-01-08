
#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"

int main() {
    FileCacheManager fileCacheManager("bla.txt");
    StringReverser stringReverser;
    MyTestClientHandler myTestClientHandler(&stringReverser, &fileCacheManager);
    MySerialServer mySerialServer;
    mySerialServer.open(5400, &myTestClientHandler);
    while (true) {};
}
