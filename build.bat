@echo off
clang++ -std=c++17 -OFast %* -o run.exe
.\run.exe
