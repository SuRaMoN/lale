 
.PHONY: lale tests run-tests
SHELL := bash

lale:
	ROOT="$$(pwd)" && \
	mkdir -p build/release && \
	cd build/release && \
	qmake "$$ROOT/src/lale" && \
	make -j && \
	cp lale "$$ROOT"

build-deps-ubuntu:
	sudo apt-get install qt5-default qt4-qmake libqxt-dev

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

