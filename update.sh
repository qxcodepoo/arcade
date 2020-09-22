./scripts/indexer.py board
./scripts/indexer.py manual Readme.md
./scripts/indexer.py links
find base -name Readme.md | xargs -n 1 ./scripts/toc.py