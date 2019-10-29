reset
make -f Makefile
./bin/main
# valgrind --show-leak-kinds=all --track-origins=yes --leak-check=full ./lab0205