#!/bin/bash

path=$1
program_path="$path/main.cpp"
program_path="$path/a.out"

g++ $program_path

$out_path
