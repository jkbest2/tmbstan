#!/bin/bash
set -e # Exit with nonzero exit code if anything fails

Rscript -e 'pkg <- c("rstan", "TMB"); if(!all(pkg%in%installed.packages()))install.packages(pkg)'

make build
make check
make install
