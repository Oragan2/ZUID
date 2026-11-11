module = zuid
dependency_libs =
library_folder = libraries/
old_libs = $(library_folder)lib$(module).a

.PHONY: build clean

all: build

build: $(old_libs)
	gcc -shared -o $(library_folder)$(module).dll \
		-Wl,--out-implib=$(library_folder)lib$(module).dll.a \
		-Wl,--export-all-symbols \
		-Wl,--enable-auto-import \
		-Wl,--whole-archive $(old_libs) \
		-Wl,--no-whole-archive $(dependency_libs)

$(old_libs): obj/zuid.o
	ar rcs $@ $^

obj/zuid.o: include/zuid.h

obj/%.o: src/%.c
	gcc -c $< -o $@ -Iinclude -std=c23 -DBUILDING_ZUID_DLL

ifeq ($(strip $(OS)),Windows_NT)
  CLEAN_FILES = $(subst /,\,obj/*.o $(old_libs) $(library_folder)cyg$(module).dll $(library_folder)lib$(module).dll.a)
  CLEAN_CMD = del /Q /F $(CLEAN_FILES) 2>nul || exit 0
else
  CLEAN_FILES = obj/*.o $(old_libs) $(library_folder)cyg$(module).dll $(library_folder)lib$(module).dll.a
  CLEAN_CMD = rm -f $(CLEAN_FILES)
endif

clean:
	$(CLEAN_CMD)



