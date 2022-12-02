#!/bin/bash

gcc  main.c evaluatePrefix.c mountPrefix.c utils/strStack.c utils/doubleStack.c -I utils/ -ggdb -o math_calc
