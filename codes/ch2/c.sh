#!/bin/bash
cpplint --filter=-whitespace/braces,-legal/copyright,-runtime/int,-readability/casting,-build/include_subdir *.c
