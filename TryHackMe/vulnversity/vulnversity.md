https://tryhackme.com/room/vulnversity

`export IP=10.10.197.20`

```
PORT     STATE SERVICE     VERSION
21/tcp   open  ftp         vsftpd 3.0.3
22/tcp   open  ssh         OpenSSH 7.2p2 Ubuntu 4ubuntu2.7 (Ubuntu Linux; protocol 2.0)
139/tcp  open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp  open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
3128/tcp open  http-proxy  Squid http proxy 3.5.12
3333/tcp open  http        Apache httpd 2.4.18 ((Ubuntu))
Service Info: Host: VULNUNIVERSITY; OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel
```

`gobuster dir -u http://$IP:3333 -w /usr/share/wordlist/Rockyou`

`http://10.10.197.20:3333/internal/index.php`
`http://10.10.197.20:3333/internal/uploads`

Possible payload .phtml


## WSL2 port forwarding
https://github.com/microsoft/WSL/issues/4150#issuecomment-504209723

## Stable shell
`python -c "import pty; pty.spawn('/bin/bash')"`
CTRL + Z
`stty raw -echo`
`fg`
ENTER
ENTER
`export TERM=xterm`