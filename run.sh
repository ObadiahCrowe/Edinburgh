#!/bin/bash
echo "Executing Edinburgh 64-bit under QEMU.."
qemu-system-x86_64  -cdrom build/edinburgh.iso
echo "Finished!"