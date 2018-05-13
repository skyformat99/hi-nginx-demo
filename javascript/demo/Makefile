
SRC=$(shell find . -type f | egrep *.js$$)

ifndef NGINX_INSTALL_DIR
NGINX_INSTALL_DIR=/usr/local/nginx
endif

all:
	@echo 'ok'

clean:
	@echo 'ok'

install:${SRC}
	for i in ${SRC};do test -d $(NGINX_INSTALL_DIR)/javascript/`dirname $$i` || mkdir -p $(NGINX_INSTALL_DIR)/javascript/`dirname $$i` && install $$i $(NGINX_INSTALL_DIR)/javascript/$$i ;done


