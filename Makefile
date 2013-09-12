 
.PHONY: lale get-deps-ubuntu tests run-tests benchmarks run-benchmarks clean
SHELL := bash

lale:
	ROOT="$$(pwd)" && \
	mkdir -p build/release && \
	cd build/release && \
	qmake "$$ROOT/src/lale" && \
	make -j && \
	cp lale "$$ROOT"

run: lale
	./lale

get-deps-ubuntu:
	sudo apt-get install libboost-dev qt5-default qt4-qmake libqxt-dev libqt4-sql-sqlite

tests:
	ROOT="$$(pwd)" && \
	mkdir -p build/tests && \
	cd build/tests && \
	qmake "$$ROOT/tests/laletests" && \
	make -j

run-tests: tests
	build/tests/laletests

benchmarks:
	ROOT="$$(pwd)" && \
	mkdir -p build/benchmarks && \
	cd build/benchmarks && \
	qmake "$$ROOT/benchmarks/lalebenchmarks" && \
	make -j

run-benchmarks: benchmarks
	build/benchmarks/lalebenchmarks

clean:
	rm -R build/* && true

