#!/bin/bash
echo "Executing Edinburgh 64-bit under QEMU.."
qemu-system-x86_64  -cdrom Edinburgh-x86_64.iso
echo "Finished!"