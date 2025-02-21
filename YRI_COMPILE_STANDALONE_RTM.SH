#!/bin/bash
#compilation of a runtime monitor as standalone program

YRI_GENERATED_RUNTIME_MONITOR_CPP_FILE="${1}"

set -x

g++ -fPIC "${YRI_GENERATED_RUNTIME_MONITOR_CPP_FILE}" \
	-I /usr/include/x86_64-linux-gnu/qt5/ \
	-I . \
	-L /usr/lib/x86_64-linux-gnu \
	-L lib \
	-lQt5Core \
	-l:libyri_sd_runtime_verif.a \
	-o yri_rtm

