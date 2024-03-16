#!/bin/bash
hooks="find base -maxdepth 2 -name Readme.md -print0 | sort -zn | xargs -0 -I '{}' dirname '{}'"

# replacing Readme.md with .cache/Readme.md
eval $hooks | xargs -L 1 bash -c 'cd "$0" && mv .cache/Readme.md .'