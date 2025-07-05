.PHONY: run
run:
	@echo "Running $(FILE)..."
	./bin/run.sh "$(FILE)"

.PHONY: setup
setup:
	@if [ -z "$(DIR)" ]; then \
		echo "Usage: make setup DIR=<contest_directory_name>" >&2; \
		echo "Example: make setup DIR=atcoder/abc412" >&2; \
		exit 1; \
	fi
	@echo "Setting up $(DIR)..."
	./bin/setup.sh "$(DIR)"

.PHONY: clean
clean:
	rm -f main
	@echo "Cleaned up build artifacts."

