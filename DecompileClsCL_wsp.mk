.PHONY: clean All

All:
	@echo "----------Building project:[ DecompileClsCL - Release ]----------"
	@$(MAKE) -f  "DecompileClsCL.mk"
clean:
	@echo "----------Cleaning project:[ DecompileClsCL - Release ]----------"
	@$(MAKE) -f  "DecompileClsCL.mk" clean
