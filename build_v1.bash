
#!/bin/bash

# create dir
mkdir -p build

# compile to build/
gcc v1/*.c v1/*.h lib/*/*.c lib/*/*.h -Wall -o build/v1