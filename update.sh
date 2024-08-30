#!/bin/bash

echo "Copying database..."
cp ../ghost/Readme.md .
cp ../ghost/flow.png .
rsync -au --delete ../ghost/base/ ./base
rsync -au --delete ../ghost/wiki/ ./wiki
