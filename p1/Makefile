INCLUDES=./mydash-src/git_version.o

# This Makefile will not build unless you first update the line 
# below to point to your linked list code from p0
LISTINSTALL=../p0
export LISTINSTALL

svnversion=git_version()
DASH_PROMPT="my_dash>"
export DASH_PROMPT
export SVN_VERSION=$(svnversion)

all: mydash-project dox

mydash-project: lib
	cd mydash-src; make


lib:
	cd $(LISTINSTALL); make 
	cp $(LISTINSTALL)/lib/libmylib.so .

dox:
	echo "Generating documentation using doxygen..."
	doxygen doxygen-config > doxygen.log 2>&1
	echo "Use konqueror docs/html/index.html to see docs (or any other browser)"

clean:
	cd mydash-src; make clean
	cd other-progs; make clean
	cd $(LISTINSTALL); make clean
	/bin/rm -f *.so mydash


