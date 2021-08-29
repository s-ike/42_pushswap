#!/bin/bash

if [ $# = 0 ]; then
    COUNT=100
else
    COUNT="$1"
fi
MAX=2147483647
MIN=-2147483648

ARG="`jot -r -s " " ${COUNT} ${MIN} ${MAX}`"

echo "${ARG}"
./push_swap $ARG | ./checker_Mac $ARG
./push_swap $ARG | wc -l
