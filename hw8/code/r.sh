#!/bin/sh
gcc c_matrix.c -o c_mat && ./c_mat
gcc cpp_matrix.cpp -o cpp_mat && ./cpp_mat
read -p "..."
