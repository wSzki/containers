#!/bin/bash

c++ -fsanitize=address -fsanitize=leak ./vector.cpp && ./a.out > ft
c++ -fsanitize=address -fsanitize=leak ./vector.cpp -DSTD=1 && ./a.out > std
diff ft std
