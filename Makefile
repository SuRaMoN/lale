 
.PHONY: lale run get-deps-ubuntu build-test test update clean
SHELL := bash

lale:
	ROOT="$$(pwd)" && \
	mkdir -p build/release && \
	cd build/release && \
	qmake-qt4 "$$ROOT/src/lale" && \
	make -j && \
	cp lale "$$ROOT"

run: lale
	./lale

get-deps-ubuntu:
	sudo apt-get install libboost-dev qt5-default qt4-qmake libqxt-dev libqt4-sql-sqlite

build-test:
	ROOT="$$(pwd)" && \
	mkdir -p build/tests && \
	cd build/tests && \
	qmake-qt4 "$$ROOT/tests/laletests" && \
	make -j

test: build-test
	build/tests/laletests

update:
	git pull origin master
	$(MAKE) clean
	$(MAKE) lale

clean:
	rm -R build/* && true

