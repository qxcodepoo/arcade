#!/bin/bash
hooks="find base -maxdepth 2 -name Readme.md -print0 | sort -zn | xargs -0 -I '{}' dirname '{}'"

# replacing Readme.md with .cache/Readme.md
# replacing Readme.md with .cache/Readme.md on arcade
eval $hooks | xargs -L 1 bash -c 'cd "$0" && cp .cache/Readme.md .'