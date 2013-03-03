.PHONY: clean All

All:
	@echo "----------Building project:[ Decompile - Debug ]----------"
	@$(MAKE) -f  "Decompile.mk"
clean:
	@echo "----------Cleaning project:[ Decompile - Debug ]----------"
	@$(MAKE) -f  "Decompile.mk" clean
