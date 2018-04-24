
PROJECT=demo.so
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))

ifndef NGINX_INSTALL_DIR
NGINX_INSTALL_DIR=/usr/local/nginx
endif

CXX=g++ 
CXXFLAGS+=-O3 -std=c++11 -fPIC -Wall -I$(NGINX_INSTALL_DIR)/include
LDLIBS+=-lboost_regex
LDFLAGS+=-shared 

all:$(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS)  $(LDLIBS) -o $@ $^

clean:
	rm -f  $(OBJ) $(PROJECT)

install:
	test -d $(NGINX_INSTALL_DIR)/cpp || mkdir -p $(NGINX_INSTALL_DIR)/cpp
	install $(PROJECT) $(NGINX_INSTALL_DIR)/cpp

