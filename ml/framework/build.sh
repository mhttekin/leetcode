#!/bin/sh

set -xe

clang -Wall -Wextra -o ml ml.c -lm
