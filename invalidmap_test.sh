#!/bin/bash

# This script is used to test the invalid maps in the maps folder

printf "[0;33mNo extension [0m"
./cub3D maps/invalid/no_extension 2> behavior
printf "[0;31mcub3D: Invalid file extension\n[0m" > behavior_expected
diff behavior behavior_expected && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"

printf "[0;33mInvalid extension [0m"
./cub3D maps/invalid/invalid_extension.txt 2> behavior
printf "[0;31mcub3D: Invalid file extension\n[0m" > behavior_expected
diff behavior behavior_expected && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"

rm behavior behavior_expected
