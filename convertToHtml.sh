#!/bin/bash

if [ -d html ]; then
    rm -rf html
fi

mkdir html

for file in ./index.ipynb */*.ipynb; do
    echo $file
    fname="${file%.*}"
    jupyter nbconvert $file --to html --execute --allow-errors
    sed -i "s/ipynb/html/g" ${fname}.html

    dir=$(dirname "${file}")
    if [ ! -f html/$dir ]; then
        mkdir html/$dir
    fi

    mv ${fname}.html html/$dir
done

cp -R img html
