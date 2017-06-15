
SRC=$(wildcard *.lua)

ifndef NGINX_INSTALL_DIR
NGINX_INSTALL_DIR=/home/centos7/nginx
endif


all:
	@echo 'ok'

clean:
	@echo 'ok'

install:
	test -d $(NGINX_INSTALL_DIR)/lua || mkdir -p $(NGINX_INSTALL_DIR)/lua
	install $(SRC) $(NGINX_INSTALL_DIR)/lua

