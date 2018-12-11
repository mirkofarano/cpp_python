TARGET = mainx
default: $(TARGET)
all: default

python_include=/usr/include/python2.7/
boost_include=/usr/include/boost/ 

_IDIR = $(python_include) $(boost_include)
IDIR=$(foreach d, $(_IDIR), -I$d)

python_lib=/usr/lib/x86_64-linux-gnu/
boost_lib=/usr/lib/x86_64-linux-gnu/

_LDIR = $(python_lib) $(boost_lib)
LDIR=$(foreach d, $(_LDIR), -L$d)

_LIBS = :libpython2.7.so pthread dl util m :libboost_python-py27.so
LIBS=$(foreach d, $(_LIBS), -l$d)

LFLAGS = -Wl,-rpath=${boost_lib} -Xlinker -export-dynamic

CXX = g++
CFLAGS = -O3 -std=c++11

DEPS = py_file.py
OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS) $(DEPS)
	$(CXX) $(CFLAGS) $(IDIR) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $^ $(CFLAGS) $(LDIR) $(LIBS) $(LFLAGS) -o $@

clean:
	-rm -f $(OBJ)
	-rm -f $(TARGET)
