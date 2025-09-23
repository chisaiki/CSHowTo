# NVM Installation Guide for WSL

This document outlines the complete process followed to install Node Version Manager (NVM) on Windows Subsystem for Linux (WSL).

## Initial System State

- **Operating System**: Ubuntu 24.04.1 LTS (WSL)
- **Initial Node.js**: v18.19.1 (installed via system package manager at `/usr/bin/node`)
- **Issue**: NVM was not installed, `nvm` command returned "Command 'nvm' not found"

## Diagnostic Steps

### 1. Check Current Node.js Installation
```bash
node --version
# Output: v18.19.1

which node
# Output: /usr/bin/node
```

### 2. Verify NVM is Not Installed
```bash
nvm --version
# Output: Command 'nvm' not found, but there are 14 similar ones.

ls -la ~/.nvm
# Output: ls: cannot access '/home/sair_a/.nvm': No such file or directory

cat ~/.bashrc | grep -i nvm
# Output: (no results)
```

### 3. Check System Information
```bash
lsb_release -a
# Output: Ubuntu 24.04.1 LTS, Codename: noble

curl --version
# Output: curl 8.5.0 (confirmed curl is available)
```

## NVM Installation Process

### Step 1: Install NVM Using Official Curl Script
```bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.7/install.sh | bash
```

**Installation Output:**
```
=> Downloading nvm from git to '/home/sair_a/.nvm'
=> Cloning into '/home/sair_a/.nvm'...
=> Compressing and cleaning up git repository
=> Appending nvm source string to /home/sair_a/.bashrc
=> Appending bash_completion source string to /home/sair_a/.bashrc
=> Close and reopen your terminal to start using nvm or run the following to use it now:

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"
```

### Step 2: Activate NVM in Current Session
```bash
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"
```

### Step 3: Verify NVM Installation
```bash
nvm --version
# Output: 0.39.7
```

## Node.js Upgrade Process

### Step 1: Check Available LTS Versions
```bash
nvm list-remote --lts
# Shows all available LTS versions, latest being v22.19.0 (LTS: Jod)
```

### Step 2: Install Latest LTS Node.js
```bash
nvm install --lts
```

**Installation Output:**
```
Installing latest LTS version.
Downloading and installing node v22.19.0...
Downloading https://nodejs.org/dist/v22.19.0/node-v22.19.0-linux-x64.tar.xz...
Computing checksum with sha256sum
Checksums matched!
Now using node v22.19.0 (npm v10.9.3)
Creating default alias: default -> lts/* (-> v22.19.0)
```

## Final Verification

### Check Updated Versions
```bash
node --version
# Output: v22.19.0

npm --version
# Output: 10.9.3

which node
# Output: /home/sair_a/.nvm/versions/node/v22.19.0/bin/node
```

## Results Summary

| Component | Before | After |
|-----------|--------|-------|
| NVM | Not installed | v0.39.7 |
| Node.js | v18.19.1 (system) | v22.19.0 (NVM-managed) |
| npm | N/A | v10.9.3 |
| Installation Path | `/usr/bin/node` | `~/.nvm/versions/node/v22.19.0/bin/node` |

## Key Benefits Achieved

✅ **NVM Installed**: Can now manage multiple Node.js versions  
✅ **Latest LTS Node.js**: Upgraded from v18.19.1 to v22.19.0  
✅ **Version Management**: Can easily switch between Node.js versions  
✅ **User-level Installation**: No sudo required for Node.js installations  
✅ **Automatic Configuration**: NVM added to `~/.bashrc` for future sessions  

## Useful NVM Commands

```bash
# List installed versions
nvm list

# Install specific version
nvm install 20.18.0

# Switch between versions
nvm use 20.18.0
nvm use 22.19.0

# Set default version
nvm alias default 22.19.0

# Install latest stable
nvm install node

# Install latest LTS
nvm install --lts

# List remote versions available
nvm list-remote

# List only LTS versions
nvm list-remote --lts
```

## Automatic Configuration Added to ~/.bashrc

The installation automatically added these lines to `~/.bashrc`:

```bash
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion
```

## Notes

- **WSL Compatibility**: All steps performed successfully on Ubuntu 24.04.1 LTS running in WSL
- **No Script Concerns**: We used the official curl installation method after initially discussing script-free alternatives
- **Automatic Default**: NVM automatically set v22.19.0 as the default Node.js version
- **Future Sessions**: NVM will be available in all new terminal sessions due to the bashrc configuration

---

*Installation completed on September 22, 2025*