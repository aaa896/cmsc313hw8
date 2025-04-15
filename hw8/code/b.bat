@echo off
mkdir ..\build
pushd ..\build
cl /nologo /Zi ..\code\c_matrix.c 
cl /nologo /Zi ..\code\cpp_matrix.cpp

pause
