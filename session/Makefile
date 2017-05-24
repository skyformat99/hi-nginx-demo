
PROJECT=session.so
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))
NGINX_INSTALL_DIR=/home/centos7/nginx

CXX=g++ 
CXXFLAGS+=-O3 -std=c++11 -fPIC -Wall -I$(NGINX_INSTALL_DIR)/include
LDLIBS+=
LDFLAGS+=-shared 

all:$(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS)  $(LDLIBS) -o $@ $^

clean:
	rm -f  $(OBJ) $(PROJECT)

install:
	install $(PROJECT) $(NGINX_INSTALL_DIR)/hi

