#!/bin/bash

for file in ./index.ipynb */*.ipynb; do
    echo $file
    jupyter nbconvert $file --to notebook --clear-output
done
