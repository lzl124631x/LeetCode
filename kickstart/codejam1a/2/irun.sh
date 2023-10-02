#!/bin/bash
g++ main.cpp -std=c++11 -o exe && python interactive_runner.py python3 testing_tool.py 0 -- ./exe