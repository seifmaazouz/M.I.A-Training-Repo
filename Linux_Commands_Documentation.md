# Linux Commands Practice Documentation

## Introduction

This document provides a summary of basic Linux commands and tools practiced on Ubuntu. The commands were executed on a virtual machine.

## Commands and Tools

### `ls` - List Directory Contents

- **Usage**: `ls [options] [directory]`
- **Description**: Lists files and directories in the specified directory. If no directory is specified, it lists the contents of the current directory.
- **Examples**:
  - `ls` - Lists files in the current directory.
  - `ls -l` - Provides a detailed list including file permissions, number of links, owner, group, size, and modification date.
  - `ls -a` - Shows hidden files (those starting with a dot).

### `cd` - Change Directory

- **Usage**: `cd [directory]`
- **Description**: Changes the current directory to the specified one.
- **Examples**:
  - `cd Documents` - Moves to the Documents directory.
  - `cd ..` - Moves up one directory level.
  - `cd /` - Moves to the root directory.
  - `cd ~` - Moves to the home directory.

### `pwd` - Print Working Directory

- **Usage**: `pwd`
- **Description**: Displays the full path of the current working directory.
- **Example**:
  - `pwd` - Outputs the path like `/home/username/Documents`.

### `mkdir` - Make Directory

- **Usage**: `mkdir [directory_name]`
- **Description**: Creates a new directory with the specified name.
- **Examples**:
  - `mkdir new_folder` - Creates a directory named `new_folder`.

### `rm` - Remove Files or Directories

- **Usage**: `rm [options] [file]`
- **Description**: Removes files or directories.
- **Examples**:
  - `rm file.txt` - Deletes `file.txt`.
  - `rm -r folder` - Deletes the directory `folder` and its contents recursively.
  - `rm -f file.txt` - Forces the deletion without prompting for confirmation.

### `cp` - Copy Files or Directories

- **Usage**: `cp [options] [source] [destination]`
- **Description**: Copies files or directories from source to destination.
- **Examples**:
  - `cp file.txt /home/username/` - Copies `file.txt` to `/home/username/`.
  - `cp -r folder1 folder2` - Copies the directory `folder1` and its contents to `folder2`.

### `mv` - Move or Rename Files or Directories

- **Usage**: `mv [options] [source] [destination]`
- **Description**: Moves or renames files or directories.
- **Examples**:
  - `mv file.txt /home/username/` - Moves `file.txt` to `/home/username/`.
  - `mv old_name.txt new_name.txt` - Renames `old_name.txt` to `new_name.txt`.

### `cat` - Concatenate and Display Files

- **Usage**: `cat [file]`
- **Description**: Displays the content of a file or concatenates multiple files.
- **Examples**:
  - `cat file.txt` - Displays the content of `file.txt`.
  - `cat file1.txt file2.txt > combined.txt` - Combines `file1.txt` and `file2.txt` into `combined.txt`.

### `nano` - Text Editor

- **Usage**: `nano [file]`
- **Description**: Opens the `nano` text editor to edit the specified file.
- **Examples**:
  - `nano file.txt` - Opens `file.txt` in the `nano` editor.
  - To save changes in `nano`, press `Ctrl + O`, then `Enter`. To exit, press `Ctrl + X`.

## Conclusion

This practice session helped me become familiar with fundamental Linux commands and tools. Understanding these basics is crucial for navigating and managing files in a Linux environment effectively.
