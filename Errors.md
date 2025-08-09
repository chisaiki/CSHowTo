# Terminal Based Errors

## Python WSL Error
When trying to run Python in VSCode with WSL as my primary terminal:
```
Error: C:/Users/<username>/AppData/Local/Programs/Python/Python313/python.exe d:/Test/Python/Practice/week10.py
-bash: C:/Users/<username>/AppData/Local/Programs/Python/Python313/python.exe: No such file or directory
```
### Solution
The reason you need to use the Linux path (/mnt/d/...) and run Python from WSL is because your main terminal in VS Code is set to WSL. <br>
When you press the "Run" button, VS Code tries to use the default Python interpreter and path settings, which may be configured for Windows, not WSL.

In WSL, Windows paths like week10.py are not recognized. WSL uses Linux-style paths, so you must use ```/mnt/d/Test/Python/Practice/week10.py.```

Must run: ```python3 /mnt/d/Test/Python/Practice/week10.py```
