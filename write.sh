#!/bin/bash
echo "Writing to disk.."
echo "Check the script before executing!!"
sudo dd if=Edinburgh-x86_64.iso of=/dev/sdb && sync
echo "Done!"