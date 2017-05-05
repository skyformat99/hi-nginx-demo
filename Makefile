MODSRC=$(wildcard *.cpp)
MODOBJ=$(patsubst %.cpp,%.o,$(MODSRC))
MODLIB=$(MODSRC:%.cpp=%.so)

NGINX_INSTALL_DIR=/home/centos7/nginx

CC=g++ 
CXXFLAGS+=-O3 -std=c++11 -fPIC -Wall -I$(NGINX_INSTALL_DIR)/include
LDLIBS+=-lPocoFoundation
LDFLAGS+=-shared 



all:$(MODLIB)

%.so: %.cpp
	g++ $(CXXFLAGS) $(LDFLAGS)  $(LDLIBS) -o $@ $< 

clean:
	rm -f  $(MODOBJ) $(MODLIB)


install:
	test -d $(NGINX_MODULE_DIR) || mkdir -p $(NGINX_MODULE_DIR)
	install $(MODLIB) $(NGINX_INSTALL_DIR)/hi
	install demo.conf $(NGINX_INSTALL_DIR)/conf
	install upload.html $(NGINX_INSTALL_DIR)/html
