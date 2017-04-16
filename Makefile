MOD=demo.so

MODSRC=$(wildcard *.cpp)
MODOBJ=$(patsubst %.cpp,%.o,$(MODSRC))

NGINX_INSTALL_DIR=/usr/local/hi

CC=g++ 
CXXFLAGS+=-O3 -std=c++11 -fPIC -Wall -I$(NGINX_INSTALL_DIR)/include
LDLIBS+=-lPocoFoundation
LDLIBS+=`pkg-config --libs opencv`
LDFLAGS+=-shared





all:$(MOD)

$(MOD):$(MODOBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS)

clean:
	rm -f  $(MODOBJ) $(MOD)


install:
	test -d $(NGINX_MODULE_DIR) || mkdir -p $(NGINX_MODULE_DIR)
	install demo.so route.conf $(NGINX_INSTALL_DIR)/cpp
	install upload.html $(NGINX_INSTALL_DIR)/html
