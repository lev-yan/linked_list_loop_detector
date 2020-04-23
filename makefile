all:linked_list.cpp
	@clear
	@echo =====================================
	@./loading.sh
	@g++  -pthread -g linked_list.cpp -o list
	@./list
	@ctags -R

clean:
	rm list
