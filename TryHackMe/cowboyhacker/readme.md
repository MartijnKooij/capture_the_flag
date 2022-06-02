https://tryhackme.com/room/cowboyhacker

`export IP=10.10.174.162`

- Nmap scan
- get files, 1 username and some passwords
- Use hydra to brute force ssh
- Get user.txt flag
- Check what user can run `sudo -l`
- Reveals tar, lookup on gtfobins to find sudo exploitable command
https://gtfobins.github.io/gtfobins/tar/ 