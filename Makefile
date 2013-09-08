 
.PHONY: lale tests run-tests

lale:
	ROOT="$$(pwd)" && \
	mkdir -p build/release && \
	cd build/release && \
	qmake "$$ROOT/src/lale" && \
	make -j && \
	cp lale "$$ROOT"

tests:
	ROOT="$$(pwd)" && \
	mkdir -p build/tests && \
	cd build/tests && \
	qmake "$$ROOT/tests/laletests" && \
	make -j

clean:
	rm -R build/* && true

run-tests: tests
	build/tests/laletests

