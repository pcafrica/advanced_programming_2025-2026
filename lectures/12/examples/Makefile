SUBDIRECTORIES=$(wildcard $(PWD)/*/.)

.PHONY=all clean

all:
	for example in $(SUBDIRECTORIES); \
	do \
	  cd $${example}; \
	  cmake -S . -B build -Dpybind11_DIR=$$(python3 -m pybind11 --cmakedir); \
	  make -C build; \
	done

clean:
	for example in $(SUBDIRECTORIES); \
	do \
	  cd $${example}; \
	  rm -rf build; \
	done
