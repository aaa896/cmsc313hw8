#!/bin/sh
g++ c_matrix.c -o c_mat && ./c_mat
g++ cpp_matrix.cpp -o cpp_mat && ./cpp_mat
read -p "..."
