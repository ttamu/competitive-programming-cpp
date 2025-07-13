.PHONY: run
run:
	@./bin/run.sh "$(f)" "$(in)"

.PHONY: new
new:
	@if [ -z "$(f)" ]; then \
		echo "Usage: make new f=<contest>-<problem> or f=<contest>" >&2; \
		echo "Example: make new f=abc400-d" >&2; \
		exit 1; \
	fi
	./bin/setup.sh "$(f)"

