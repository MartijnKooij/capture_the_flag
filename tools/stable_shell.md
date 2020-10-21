## Stable shell
`python -c "import pty; pty.spawn('/bin/bash')"`
CTRL + Z
`stty raw -echo`
`fg`
ENTER
ENTER
`export TERM=xterm`