.PHONY: run
run:
	@echo "Running $(FILE)..."
	./bin/run.sh "$(FILE)" $(INPUT_FILE)

.PHONY: run-in-txt
run-in-txt:
	@echo "Running $(FILE) with data/in.txt..."
	./bin/run.sh "$(FILE)" data/in.txt

.PHONY: new
new:
	@if [ -z "$(f)" ]; then \
		echo "Usage: make new f=<contest>-<problem> or f=<contest>" >&2; \
		echo "Example: make new f=abc400-d" >&2; \
		exit 1; \
	fi
	./bin/setup.sh "$(f)"

.PHONY: clean
clean:
	rm -f main
	@echo "Cleaned up build artifacts."
