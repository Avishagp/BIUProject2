cmake_minimum_required(VERSION 3.8)
project(BIUProject2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "-pthread")
set(SOURCE_FILES main.cpp Server.h MySerialServer.h MySerialServer.cpp ClientHandler.h MyTestClientHandler.cpp
        MyTestClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Solver.h StringReverser.h
        ArgumentsForOpenServer.h SearchableMatrix.h SearchableMatrix.cpp ISearchable.h ISearcher.h PQSearcher.h
        StateComparatorLesser.h DFS.cpp DFS.h BFS.cpp BFS.h AStar.cpp AStar.h)
add_executable(BIUProject2 ${SOURCE_FILES} main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.h
        MyTestClientHandler.cpp MyTestClientHandler.h CacheManager.h FileCacheManager.h FileCacheManager.cpp Solver.h
        ArgumentsForOpenServer.h DFS.cpp DFS.h BFS.cpp BFS.h AStar.cpp AStar.h)