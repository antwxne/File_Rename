## VAR
NAME			=	Changer_les_noms_des_fichiers_par_date
TESTS_NAME	=	unit_tests
BUILD_TYPE	=	Release

BUILD_DIR	=	build

SHELL	=	/bin/sh
RM		?=	rm -f

## Rules ##
.PHONY: all
all: $(NAME)

.PHONY: build
build:
	mkdir -p $(BUILD_DIR) && cd $(BUILD_DIR) && conan install --build=missing .. && cmake -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -G "Unix Makefiles" ..

.PHONY: debug_build
debug_build: BUILD_TYPE	=	Debug
debug_build: build

.PHONY: $(NAME)
$(NAME): build
	cmake --build $(BUILD_DIR) --target $(NAME)

.PHONY: debug
debug: debug_build
	cmake --build $(BUILD_DIR) --target $(NAME)

.PHONY: clean
clean:
	cmake --build $(BUILD_DIR) --target clean

.PHONY: re
re: clean all