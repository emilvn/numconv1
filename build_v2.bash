
#!/bin/bash

# create dir
mkdir -p build

# compile to build/
gcc v2/*.c v2/*.h lib/*/*.c lib/*/*.h -Wall -o build/v2