#!gmake
.PHONY: debug release clean clobber package install tests test


ifeq ($(wildcard Makefile), Makefile)
all:
	$(MAKE) -f Makefile $(MAKECMDGOALS)

install:
	$(MAKE) -f Makefile $(MAKECMDGOALS)

clean:
	$(MAKE) -f Makefile $(MAKECMDGOALS)

test:
	$(MAKE) -f Makefile $(MAKECMDGOALS)
	
tests:
	$(MAKE) -f Makefile $(MAKECMDGOALS)
	
package:
	$(MAKE) -f Makefile $(MAKECMDGOALS)

.DEFAULT:
	$(MAKE) -f Makefile $(MAKECMDGOALS)

else

all: debug

install: Debug/Makefile Release/Makefile
	@$(MAKE) -C Debug install
	@$(MAKE) -C Release install

clean:
	@-$(MAKE) -C Debug clean
	@-$(MAKE) -C Release clean

package: Release/Makefile
	@$(MAKE) -C Release clean
	@$(MAKE) -C Release package

tests: Debug/Makefile
	@$(MAKE) -C Debug tests
	
test: Debug/Makefile
	@$(MAKE) -C Debug tests

.DEFAULT: Debug/Makefile Release/Makefile
	@$(MAKE) -C Debug $(MAKECMDGOALS)
	@$(MAKE) -C Release $(MAKECMDGOALS)
endif

clobber:
	rm -rf Debug Release

debug: Debug/Makefile
	@$(MAKE) -C Debug

Debug/Makefile:
	@mkdir -p Debug
	@cd Debug; cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX:PATH=install

release: Release/Makefile
	@$(MAKE) -C Release

Release/Makefile:
	@mkdir -p Release
	@cd Release; cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX:PATH=install

