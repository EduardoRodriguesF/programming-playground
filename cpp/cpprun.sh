#!/bin/bash

path=$1

g++ $path/main.cpp -o $path/a.out

$path/a.out
