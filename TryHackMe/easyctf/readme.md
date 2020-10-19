https://tryhackme.com/room/easyctf

`export IP=10.10.31.33`
`ssh user mitch password secret`

Copy a file from local to the SSH victim machine
`scp -P 2222 ./linpeas.sh mitch@10.10.31.33:/home/mitch/linpeas.sh`

https://gtfobins.github.io/gtfobins/vim/

Stabilize shell
`python -c 'import pty; pty.spawn("/bin/bash")'`

Scan for directories
gobuster dir -u $IP/ -w /usr/share/wordlists/dirb/common.txt

```
robots.txt
#
# "$Id: robots.txt 3494 2003-03-19 15:37:44Z mike $"
#
#   This file tells search engines not to index your CUPS server.
#
#   Copyright 1993-2003 by Easy Software Products.
#
#   These coded instructions, statements, and computer programs are the
#   property of Easy Software Products and are protected by Federal
#   copyright law.  Distribution and use rights are outlined in the file
#   "LICENSE.txt" which should have been included with this file.  If this
#   file is missing or damaged please contact Easy Software Products
#   at:
#
#       Attn: CUPS Licensing Information
#       Easy Software Products
#       44141 Airport View Drive, Suite 204
#       Hollywood, Maryland 20636-3111 USA
#
#       Voice: (301) 373-9600
#       EMail: cups-info@cups.org
#         WWW: http://www.cups.org
#

User-agent: *
Disallow: /


Disallow: /openemr-5_0_1_3 
#
# End of "$Id: robots.txt 3494 2003-03-19 15:37:44Z mike $".
#
```

Scan for known vulnerabilities
`nmap -v --script vuln $IP`

