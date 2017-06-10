
SRC=$(wildcard *.lua)

NGINX_INSTALL_DIR=/home/centos7/nginx


all:
	@echo 'ok'

clean:
	@echo 'ok'

install:
	test -d $(NGINX_INSTALL_DIR)/lua || mkdir -p $(NGINX_INSTALL_DIR)/lua
	install $(SRC) $(NGINX_INSTALL_DIR)/lua

