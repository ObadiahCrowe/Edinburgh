#!/bin/bash
echo "Writing to disk.."
echo "Check the script before executing!!"
sudo dd if=build/edinburgh.iso of=/dev/sdb && sync
echo "Done!"