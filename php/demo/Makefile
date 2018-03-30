
SRC=$(wildcard *.php)

ifndef NGINX_INSTALL_DIR
NGINX_INSTALL_DIR=/usr/local/nginx
endif


all:
	@echo 'ok'

clean:
	@echo 'ok'

install:
	test -d $(NGINX_INSTALL_DIR)/php || mkdir -p $(NGINX_INSTALL_DIR)/php
	install $(SRC) $(NGINX_INSTALL_DIR)/php

