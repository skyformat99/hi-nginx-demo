
SRC=$(shell find . -type f | egrep *.php$$)

ifndef NGINX_INSTALL_DIR
NGINX_INSTALL_DIR=/usr/local/nginx
endif


all:
	@echo 'ok'

clean:
	@echo 'ok'

install:${SRC}
	for i in ${SRC};do test -d $(NGINX_INSTALL_DIR)/php/`dirname $$i` || mkdir -p $(NGINX_INSTALL_DIR)/php/`dirname $$i` && install $$i $(NGINX_INSTALL_DIR)/php/$$i ;done


