# Project Guidelines

## Git Commit Convention

Use Conventional Commits format:

```
<type>(<scope>): <description>

[optional body]
```

### Types
- `feat`: New problem solution or feature
- `fix`: Bug fix in existing solution
- `refactor`: Code refactoring without changing behavior
- `docs`: Documentation changes
- `chore`: Build process, dependencies, or tooling changes

### Examples
- `feat(abc400): add solution for problem A`
- `fix(abc400): correct edge case in problem B`
- `refactor: improve template structure`
- `chore: update dependencies`

## Project Structure

- `src/bin/` - Individual problem solutions (e.g., `abc400_a.cpp`)
- `src/main.cpp` - Quick testing/scratch file
