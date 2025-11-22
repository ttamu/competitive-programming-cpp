CONTAINER_NAME := procon-cpp
IMAGE_NAME := procon-env

.PHONY: up down run new test

up:
	@if docker ps -q -f name=$(CONTAINER_NAME) | grep -q .; then \
		echo "Container already running."; \
	else \
		docker run -d --name $(CONTAINER_NAME) --rm -v $(PWD):/work -w /work $(IMAGE_NAME) tail -f /dev/null; \
		echo "Container started."; \
	fi

down:
	@docker rm -f $(CONTAINER_NAME) 2>/dev/null || true
	@echo "Container stopped."

run:
	@./scripts/run.sh $(filter-out $@,$(MAKECMDGOALS))

new:
	@target="$(filter-out $@,$(MAKECMDGOALS))"; \
	if [ -z "$$target" ]; then \
		echo "Usage: make new <target>" >&2; \
		echo "Example: make new abc400_d" >&2; \
		exit 1; \
	fi; \
	file="src/bin/$$target.cpp"; \
	if [ -f "$$file" ]; then \
		echo "Error: $$file already exists." >&2; \
		exit 1; \
	fi; \
	mkdir -p src/bin; \
	cp src/template.cpp "$$file"; \
	echo "Created $$file"

test:
	@target="$(filter-out $@,$(MAKECMDGOALS))"; \
	if [ -z "$$target" ]; then \
		echo "Usage: make test <target>" >&2; \
		echo "Example: make test abc400_d" >&2; \
		exit 1; \
	fi; \
	if [ ! -d "testcases/$$target" ]; then \
		contest=$$(echo "$$target" | sed 's/_[^_]*$$//'); \
		echo "Downloading test cases for $$target..."; \
		oj download "https://atcoder.jp/contests/$$contest/tasks/$$target" -d "testcases/$$target"; \
	fi; \
	oj test -c "make run $$target" -d "testcases/$$target"

%:
	@:
