$remoteport = '172.21.181.131' #ifconfig IP of the WSL2 machine

#[Ports]

#All the ports you want to forward separated by coma
$ports=@(3333, 1234);


#[Static ip]
#You can change the addr to your ip config to listen to a specific address
$addr='10.8.97.41'; #Source Machine IP (TryHackMe VPN http://10.10.10.10/)
$ports_a = $ports -join ",";


#Remove Firewall Exception Rules
iex "Remove-NetFireWallRule -DisplayName 'WSL 2 Firewall Unlock' ";

#adding Exception Rules for inbound and outbound Rules
iex "New-NetFireWallRule -DisplayName 'WSL 2 Firewall Unlock' -Direction Outbound -LocalPort $ports_a -Action Allow -Protocol TCP";
iex "New-NetFireWallRule -DisplayName 'WSL 2 Firewall Unlock' -Direction Inbound -LocalPort $ports_a -Action Allow -Protocol TCP";

for( $i = 0; $i -lt $ports.length; $i++ ){
  $port = $ports[$i];
  iex "netsh interface portproxy delete v4tov4 listenport=$port listenaddress=$addr";
  iex "netsh interface portproxy add v4tov4 listenport=$port listenaddress=$addr connectport=$port connectaddress=$remoteport";
}


# iex "netsh interface portproxy delete v4tov4 listenport=1234 listenaddress=10.8.97.41";
# iex "netsh interface portproxy add v4tov4 listenport=1234 listenaddress=10.8.97.41 connectport=1234 connectaddress=172.21.181.131";