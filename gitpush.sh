#gitpush.sh
#!/bin/bash

read mycommit

git status
git add -A
git commit -m "${mycommit}"
git push -f origin main

