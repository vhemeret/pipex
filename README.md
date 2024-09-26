# 🔗 Pipex

## 📖 About

Pipex is a project that aims to deepen understanding of UNIX mechanisms by implementing a program that simulates the behavior of shell pipes.

## 🎯 Objectives

- Understand and implement UNIX pipes
- Handle file input/output redirection
- Execute shell commands from within a C program
- Manage processes using fork and execve

## 🛠️ Features

- Simulate the behavior of the shell command: `< file1 cmd1 | cmd2 > file2`
- Handle input and output files
- Execute two shell commands with their parameters
- Properly manage error cases and memory

## 🚀 Usage

```
./pipex file1 cmd1 cmd2 file2
```

This will take the content of `file1`, execute `cmd1`, pipe the result to `cmd2`, and output the final result to `file2`.

### Example

```
./pipex infile "ls -l" "wc -l" outfile
```

This is equivalent to: `< infile ls -l | wc -l > outfile`

## ⚙️ Installation

1. Clone the repository:
   ```
   git clone https://github.com/your-username/pipex.git
   ```
2. Navigate to the project folder:
   ```
   cd pipex
   ```
3. Compile the project:
   ```
   make
   ```

---

Made with ❤️ as part of the 42 School curriculum.