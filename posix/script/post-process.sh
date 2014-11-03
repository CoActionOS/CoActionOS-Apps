#!/bin/bash
PROJ=$1
PREFIX=$2
HOST=$3
$PREFIX/$HOST-objcopy -j .text -j .data -O binary ./$PROJ.elf ./$PROJ
$PREFIX/$HOST-objdump -S -j .text -j .data -j .bss -j .sysmem -d $PROJ.elf > $PROJ.s
$PREFIX/$HOST-size ./$PROJ.elf 
