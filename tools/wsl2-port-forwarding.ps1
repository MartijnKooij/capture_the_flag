# WSL2 port forwarding
# https://github.com/microsoft/WSL/issues/4150#issuecomment-504209723

$remoteport = '172.28.160.1' #ifconfig IP of the WSL2 machine

#[Ports]

#All the ports you want to forward separated by coma
$ports=@(3333, 1234);


#[Static ip]
#You can change the addr to your ip config to listen to a specific address
$addr='10.10.217.69'; #Source Machine IP (TryHackMe VPN http://10.10.10.10/)
$ports_a = $ports -join ",";


#Remove Firewall Exception Rules
Invoke-Expression "Remove-NetFireWallRule -DisplayName 'WSL 2 Firewall Unlock' ";

#adding Exception Rules for inbound and outbound Rules
Invoke-Expression "New-NetFireWallRule -DisplayName 'WSL 2 Firewall Unlock' -Direction Outbound -LocalPort $ports_a -Action Allow -Protocol TCP";
Invoke-Expression "New-NetFireWallRule -DisplayName 'WSL 2 Firewall Unlock' -Direction Inbound -LocalPort $ports_a -Action Allow -Protocol TCP";

for( $i = 0; $i -lt $ports.length; $i++ ){
  $port = $ports[$i];
  Invoke-Expression "netsh interface portproxy delete v4tov4 listenport=$port listenaddress=$addr";
  Invoke-Expression "netsh interface portproxy add v4tov4 listenport=$port listenaddress=$addr connectport=$port connectaddress=$remoteport";
}

# iex "netsh interface portproxy delete v4tov4 listenport=1234 listenaddress=10.10.34.147";
# iex "netsh interface portproxy add v4tov4 listenport=1234 listenaddress=10.10.34.147 connectport=1234 connectaddress=172.28.164.104";