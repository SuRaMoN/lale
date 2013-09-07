 
.PHONY: lale tests run-tests

lale:
	mkdir -p build/release && \
	cd build/release && \
	qmake ../../src/lale && \
	make && \
	cp lale ../..

tests:
	mkdir -p build/tests && \
	cd build/tests && \
	qmake ../../tests/laletests && \
	make

run-tests: tests
	build/tests/laletests

