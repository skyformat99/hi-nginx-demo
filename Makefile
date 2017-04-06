MOD=demo.so

MODSRC=$(wildcard *.cpp)
MODOBJ=$(patsubst %.cpp,%.o,$(MODSRC))


CC=gcc
CXXFLAGS+=-O3 -fPIC -Wall -I/home/ubuntu1610/nginx/include
LDLIBS+=-lPocoNet -lPocoFoundation
LDLIBS+=`pkg-config --libs opencv`
LDFLAGS+=-shared

NGINX_MODULE_DIR=/home/ubuntu1610/nginx/cpp


all:$(MOD)

$(MOD):$(MODOBJ)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS)

clean:
	rm -f  $(MODOBJ) $(MOD)


install:
	test -d $(NGINX_MODULE_DIR) || mkdir -p $(NGINX_MODULE_DIR)
	install demo.so $(NGINX_MODULE_DIR)
	cp route.conf $(NGINX_MODULE_DIR)
