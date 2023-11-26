@echo off
clang++ -std=c++17 -Ofast %* -o run.exe
.\run.exe
