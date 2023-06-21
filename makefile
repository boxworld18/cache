.PHONY: cs cl ca mm

all: cs cl ca mm

cs: cache_size.cpp
	g++ -o cache_size cache_size.cpp -O2

cl: cache_line.cpp
	g++ -o cache_line cache_line.cpp -O2 

ca: cache_asso.cpp
	g++ -o cache_asso cache_asso.cpp -O2

mm: mat_mul.cpp
	g++ -o mat_mul mat_mul.cpp -O0

clean:
	rm -f cache_size cache_line cache_asso mat_mul