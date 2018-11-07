#!/bin/bash
set -e # Exit with nonzero exit code if anything fails

if [ ! -f ~/.R/Makevars ]; then
    mkdir -p ~/.R
    echo "CXX14 = g++" > ~/.R/Makevars
    echo "CXX14FLAGS = -O3" >> ~/.R/Makevars
fi

Rscript -e 'pkg <- c("rstan", "TMB"); if(!all(pkg%in%installed.packages()))install.packages(pkg)'
