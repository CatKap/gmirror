#!/bin/bash
if ! trans --version; then

git clone https://github.com/soimort/translate-shell
cd translate-shell/
make
make install
rm -rf ./translate-shell/
