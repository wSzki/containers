#!/bin/bash

c++ -fsanitize=address -fsanitize=leak ./stack.cpp && ./a.out > ft
c++ -fsanitize=address -fsanitize=leak ./stack.cpp -DSTD=1 && ./a.out > std
diff ft std
