SRC=$(wildcard *.py)

ifndef NGINX_INSTALL_DIR
NGINX_INSTALL_DIR=/home/centos7/nginx
endif


all:
	@echo 'ok'

clean:
	@echo 'ok'

install:
	test -d $(NGINX_INSTALL_DIR)/python || mkdir -p $(NGINX_INSTALL_DIR)/python
	install $(SRC) $(NGINX_INSTALL_DIR)/python

