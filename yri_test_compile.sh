#!/bin/bash

YRI_SD_RUNTIME_VERIF_SUT="${HOME}/yri_sd_runtime_verif"

${YRI_SD_RUNTIME_VERIF_SUT}/yri_DEPLOY_FOR_lang_UNIT_TESTS-development.sh

TEST_YRI_FILE_OUTPUT="TEST_YRI_RESULTS.TXT"

CUR_DIR="$(pwd)"

YRI_LIB_MONITOR_GENERATION_DIR="${CUR_DIR}/yri_sd_runtime_verif"

YRI_TEST_DIR="${CUR_DIR}"

cd "${YRI_LIB_MONITOR_GENERATION_DIR}" 

yri_compile_TESTING_j8.sh

if [ ! $? ]; then
	echo "compilation of yri_sd_runtime_verif FAILED !"
	exit 1
fi

cd "${YRI_TEST_DIR}"

clear && qmake && make clean && make -j2 && \
	cd "${CUR_DIR}" && \
	bin/yri_monitor_test_1 > "${TEST_YRI_FILE_OUTPUT}" 2>&1 && \
	run-test-yri-coverage-gen-html.sh	

