#!/bin/bash
echo "Pulling possible changes.."
git pull

echo "Adding all files.."
git add .

echo "Commit message: "
read commitMsg

echo "Commiting all files.."
git commit -m "$commitMsg"

echo "Pushing new changes.."
git push -u origin master
echo "Done!"