 
.PHONY: lale build-deps-ubuntu tests run-tests clean
SHELL := bash

lale:
	ROOT="$$(pwd)" && \
	mkdir -p build/release && \
	cd build/release && \
	qmake "$$ROOT/src/lale" && \
	make -j && \
	cp lale "$$ROOT"

build-deps-ubuntu:
	sudo apt-get install qt5-default qt4-qmake libqxt-dev libqt4-sql-sqlite

tests:
	ROOT="$$(pwd)" && \
	mkdir -p build/tests && \
	cd build/tests && \
	qmake "$$ROOT/tests/laletests" && \
	make -j

run-tests: tests
	build/tests/laletests

clean:
	rm -R build/* && true

