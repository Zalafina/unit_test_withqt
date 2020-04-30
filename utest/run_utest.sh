#!/bin/sh

mkdir -p out \
&& rm -f ./out/test*.info \
&& lcov -z -d .;
./utest;
lcov -c -d . -o out/test.info \
&& lcov --extract out/test.info '*utest_main.cc' -o out/test_final.info \
&& rm -rf out/html \
&& genhtml out/test_final.info -o out/html -t UT_TEST -s -l \
&& rm -rf ./out/gcov \
&& mkdir -p ./out/gcov \
&& cp -af ./*.gcda ./*.gcno ./out/gcov \
&& LANG='en_US' \
&& gcov -nfb out/gcov/*.gcno > out/gcov.txt;
