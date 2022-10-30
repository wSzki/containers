#!/bin/bash

c++ -fsanitize=address -fsanitize=leak ./*.cpp && ./a.out > ft
c++ -fsanitize=address -fsanitize=leak ./*.cpp -DSTD=1 && ./a.out > std
diff ft std
