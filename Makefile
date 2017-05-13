PROJECT=hello empty form math error redirect


all:$(PROJECT)
	for i in $(PROJECT);do cd $$i && make && cd .. ;done

clean:
	for i in $(PROJECT);do cd $$i && make clean && cd .. ;done

install:
	for i in $(PROJECT);do cd $$i && make install && cd .. ;done
