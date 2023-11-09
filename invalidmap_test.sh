#!/bin/bash

# This script is used to test the invalid maps in the maps folder

printf "[0;33mNo extension [0m"
./cub3D map/invalid/no_extension 2> behavior
printf "[0;31mcub3D: Invalid file extension\n[0m" > behavior_expected
diff behavior behavior_expected > /dev/null && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"

printf "[0;33mInvalid extension [0m"
./cub3D map/invalid/invalid_extension.txt 2> behavior
printf "[0;31mcub3D: Invalid file extension\n[0m" > behavior_expected
diff behavior behavior_expected > /dev/null && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"

printf "[0;33mNo such file [0m"
./cub3D map/invalid/no_such_file.cub 2> behavior
printf "[0;31mcub3D: map/invalid/no_such_file.cub: No such file or directory\n[0m" > behavior_expected
diff behavior behavior_expected > /dev/null && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"

printf "[0;33mTwo player in file (same direction) [0m"
./cub3D map/invalid/twoplayer_different_dir.cub 2> behavior
printf "[0;31mcub3D: Map has more than one player\n[0m" > behavior_expected
diff behavior behavior_expected > /dev/null && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"

printf "[0;33mTwo player in file (different direction) [0m"
./cub3D map/invalid/twoplayer_same_dir.cub 2> behavior
printf "[0;31mcub3D: Map has more than one player\n[0m" > behavior_expected
diff behavior behavior_expected > /dev/null && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"

printf "[0;33mNot surrounded by walls [0m"
./cub3D map/invalid/not_surrounded_by_walls.cub 2> behavior
printf "[0;31mcub3D: Map is not surrounded by walls\n[0m" > behavior_expected
diff behavior behavior_expected > /dev/null && printf "[0;32m[OK] [0m" || printf "[0;31m[KO] [0m"
./cub3D map/invalid/not_surrounded_by_walls2.cub 2> behavior
diff behavior behavior_expected > /dev/null && printf "[0;32m[OK]\n[0m" || printf "[0;31m[KO]\n[0m"


rm behavior behavior_expected
