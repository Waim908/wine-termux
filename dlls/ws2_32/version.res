        ��  ��                     <   W I N E _ D A T A _ F I L E   ��       0           # 127.0.0.1 localhost
    <   W I N E _ D A T A _ F I L E   ��       0           # loopback 127
�  <   W I N E _ D A T A _ F I L E   ��       0           # Internet protocols

ip           0   IP
icmp         1   ICMP
ggp          3   GGP
tcp          6   TCP
egp          8   EGP
pup          12  PUP
udp          17  UDP
hmp          20  HMP
xns-idp      22  XNS-IDP
rdp          27  RDP
ipv6         41  IPv6
ipv6-route   43  IPv6-Route
ipv6-frag    44  IPv6-Frag
esp          50  ESP
ah           51  AH
ipv6-icmp    58  IPv6-ICMP
ipv6-nonxt   59  IPv6-NoNxt
ipv6-opts    60  IPv6-Opts
rvd          66  RVD
  #  <   W I N E _ D A T A _ F I L E   ��       0           # Network services, Internet style

echo            7/tcp
echo            7/udp
discard         9/tcp     sink null
discard         9/udp     sink null
systat          11/tcp    users
daytime         13/tcp
daytime         13/udp
netstat         15/tcp
qotd            17/tcp    quote
qotd            17/udp    quote
chargen         19/tcp    ttytst source
chargen         19/udp    ttytst source
ftp-data        20/tcp
ftp             21/tcp
fsp             21/udp    fspd
ssh             22/tcp
telnet          23/tcp
smtp            25/tcp    mail
time            37/tcp    timserver
time            37/udp    timserver
rlp             39/udp    resource
nameserver      42/tcp    name
nameserver      42/udp    name
whois           43/tcp    nicname
tacacs          49/tcp
tacacs          49/udp
domain          53/tcp
domain          53/udp
bootps          67/udp    dhcps
bootpc          68/udp    dhcpc
bootps          67/udp
bootpc          68/udp
tftp            69/udp
gopher          70/tcp
finger          79/tcp
http            80/tcp    www
hosts2-ns       81/tcp
hosts2-ns       81/udp
kerberos        88/tcp    kerberos5 krb5 kerberos-sec
kerberos        88/udp    kerberos5 krb5 kerberos-sec
hostname        101/tcp   hostnames
iso-tsap        102/tcp   tsap
acr-nema        104/tcp   dicom
rtelnet         107/tcp
pop2            109/tcp   postoffice
pop3            110/tcp   pop-3
sunrpc          111/tcp   rpcbind portmap
sunrpc          111/udp   rpcbind portmap
auth            113/tcp   authentication tap ident
uucp-path       117/tcp
sqlserv         118/tcp
nntp            119/tcp   usenet readnews untp
ntp             123/udp
epmap           135/tcp   loc-srv
epmap           135/ucp   loc-srv
netbios-ns      137/tcp   nbname
netbios-ns      137/udp   nbname
netbios-dgm     138/udp   nbdatagram
netbios-ssn     139/tcp   nbsession
imap2           143/tcp   imap imap4
sql-net         150/tcp
sqlsrv          156/tcp
pcmail-srv      158/tcp
snmp            161/tcp
snmp            161/udp
snmp-trap       162/tcp   snmptrap
snmp-trap       162/udp   snmptrap
cmip-man        163/tcp
cmip-man        163/udp
cmip-agent      164/tcp
cmip-agent      164/udp
print-srv       170/tcp
mailq           174/tcp
xdmcp           177/udp
bgp             179/tcp
irc             194/tcp
smux            199/tcp
qmtp            209/tcp
z3950           210/tcp   wais
ipx             213/udp
ptp-event       319/udp
ptp-general     320/udp
rtsps           322/tcp
rtsps           322/udp
pawserv         345/tcp
zserv           346/tcp
mftp            349/tcp
mftp            349/udp
rpc2portmap     369/tcp
rpc2portmap     369/udp
codaauth2       370/tcp
codaauth2       370/udp
clearcase       371/udp   Clearcase
ldap            389/tcp
ldap            389/udp
svrloc          427/tcp
svrloc          427/udp
https           443/tcp   MCom
https           443/udp   MCom
snpp            444/tcp
microsoft-ds    445/tcp
microsoft-ds    445/udp
kpasswd         464/tcp
kpasswd         464/udp
submissions     465/tcp   ssmtp smtps urd
saft            487/tcp
isakmp          500/udp   ike
crs             507/tcp
crs             507/udp
exec            512/tcp
biff            512/udp   comsat
login           513/tcp
who             513/udp   whod
shell           514/tcp   cmd syslog
syslog          514/udp
printer         515/tcp   spooler
talk            517/udp
ntalk           518/udp
efs             520/tcp
route           520/udp   router routed
ulp             522/tcp    
ulp             522/udp    
timed           525/udp   timeserver
tempo           526/tcp   newdate
irc-serv        529/tcp
irc-serv        529/udp
courier         530/tcp   rpc
conference      531/tcp   chat
netnews         532/tcp   readnews
netwall         533/udp
gdomap          538/tcp
gdomap          538/udp
uucp            540/tcp   uucpd
klogin          543/tcp
kshell          544/tcp   krcmd
dhcpv6-client   546/tcp
dhcpv6-client   546/udp
dhcpv6-server   547/tcp
dhcpv6-server   547/udp
afpovertcp      548/tcp
afpovertcp      548/udp
new-rwho        550/udp   new-who
rtsp            554/tcp
rtsp            554/udp
remotefs        556/tcp   rfs rfs_server
rmonitor        560/udp   rmonitord
monitor         561/udp
nntps           563/tcp   snntp
nntps           563/udp   snntp
whoami          565/tcp
whoami          565/udp
ms-shuttle      568/tcp
ms-shuttle      568/udp
ms-rome         569/tcp
ms-rome         569/udp
submission      587/tcp
http-rpc-epmap  593/tcp
http-rpc-epmap  593/udp
nqs             607/tcp
hmmp-ind        612/tcp
hmmp-ind        612/udp
hmmp-op         613/tcp
hmmp-op         613/udp
asf-rmcp        623/udp
qmqp            628/tcp
ipp             631/tcp
ldaps           636/tcp   sldap
ldaps           636/udp
ldp             646/tcp
ldp             646/udp
tinc            655/tcp
tinc            655/udp
doom            666/tcp
doom            666/udp
msexch-routing  691/tcp
msexch-routing  691/udp
silc            706/tcp
kerberos-adm    749/tcp
kerberos-adm    749/udp
kerberos-iv     750/udp
mdbs_daemon     800/tcp
mdbs_daemon     800/udp
domain-s        853/tcp
domain-s        853/udp
rsync           873/tcp
ftps-data       989/tcp
ftps            990/tcp
telnets         992/tcp
imaps           993/tcp
ircs            994/tcp
pop3s           995/tcp   spop3
pop3s           995/udp   spop3
kpop            1109/tcp
nfsd-status     1110/tcp
nfsd-keepalive  1110/udp
nfa             1155/tcp
nfa             1155/udp
activesync      1034/tcp
phone           1167/udp
opsmgr          1270/tcp
opsmgr          1270/udp
ms-sql-s        1433/tcp
ms-sql-s        1433/udp
ms-sql-m        1434/tcp
ms-sql-m        1434/udp
ms-sna-server   1477/tcp
ms-sna-server   1477/udp
ms-sna-base     1478/tcp
ms-sna-base     1478/udp
wins            1512/tcp
wins            1512/udp
ingreslock      1524/tcp  ingres
stt             1607/tcp
stt             1607/udp
l2tp            1701/udp
pptconference   1711/tcp
pptconference   1711/udp
pptp            1723/tcp
msiccp          1731/tcp
msiccp          1731/udp
remote-winsock  1745/tcp
remote-winsock  1745/udp
ms-streaming    1755/tcp
ms-streaming    1755/udp
msmq            1801/tcp
msmq            1801/udp
radius          1812/udp
radacct         1813/udp
msnp            1863/tcp
msnp            1863/udp
ssdp            1900/tcp
ssdp            1900/udp
close-combat    1944/tcp
close-combat    1944/udp
nfsd            2049/udp  nfs
knetd           2053/tcp
mzap            2106/tcp
mzap            2106/udp
qwave           2177/tcp
qwave           2177/udp
directplay      2234/tcp
directplay      2234/udp
ms-olap3        2382/tcp
ms-olap3        2382/udp
ms-olap4        2383/tcp
ms-olap4        2383/udp
ms-olap1        2393/tcp
ms-olap1        2393/udp
ms-olap2        2394/tcp
ms-olap2        2394/udp
ms-theater      2460/tcp
ms-theater      2460/udp
wlbs            2504/tcp
wlbs            2504/udp
ms-v-worlds     2525/tcp
ms-v-worlds     2525/udp
sms-rcinfo      2701/tcp
sms-rcinfo      2701/udp
sms-xfer        2702/tcp
sms-xfer        2702/udp
sms-chat        2703/tcp
sms-chat        2703/udp
sms-remctrl     2704/tcp
sms-remctrl     2704/udp
msolap-ptp2     2725/tcp
msolap-ptp2     2725/udp
icslap          2869/tcp
icslap          2869/udp
cifs            3020/tcp
cifs            3020/udp
xbox            3074/tcp
xbox            3074/udp
ms-dotnetster   3126/tcp
ms-dotnetster   3126/udp
ms-rule-engine  3132/tcp
ms-rule-engine  3132/udp
msft-gc         3268/tcp
msft-gc         3268/udp
msft-gc-ssl     3269/tcp
msft-gc-ssl     3269/udp
ms-cluster-net  3343/tcp
ms-cluster-net  3343/udp
ms-wbt-server   3389/tcp
ms-wbt-server   3389/udp
ms-la           3535/tcp
ms-la           3535/udp
pnrp-port       3540/tcp
pnrp-port       3540/udp
teredo          3544/tcp
teredo          3544/udp
p2pgroup        3587/tcp
p2pgroup        3587/udp
ws-discovery    3702/udp
ws-discovery    3702/tcp
dvcprov-port    3776/tcp
dvcprov-port    3776/udp
msfw-control    3847/tcp
msdts1          3882/tcp
sdp-portmapper  3935/tcp
sdp-portmapper  3935/udp
net-device      4350/tcp
net-device      4350/udp
ipsec-msft      4500/tcp
ipsec-msft      4500/udp
llmnr           5355/tcp
llmnr           5355/udp
wsd             5357/tcp
wsd             5358/tcp
rrac            5678/tcp
rrac            5678/udp
dccm            5679/tcp
dccm            5679/udp
ms-licensing    5720/tcp
ms-licensing    5720/udp
directplay8     6073/tcp
directplay8     6073/udp
man             9535/tcp
rasadv          9753/tcp
rasadv          9753/udp
imip-channels   11320/tcp
imip-channels   11320/udp
directplaysrvr  47624/tcp
directplaysrvr  47624/udp
T      �� ��     0           T4   V S _ V E R S I O N _ I N F O     ���     �(
  �(
?                          �    S t r i n g F i l e I n f o   �    0 4 0 9 0 4 B 0   L   C o m p a n y N a m e     M i c r o s o f t   C o r p o r a t i o n   D   F i l e D e s c r i p t i o n     W i n e   c o r e   d l l   <   F i l e V e r s i o n     5 . 1 . 2 6 0 0 . 5 5 1 2   "   I n t e r n a l N a m e       � \  L e g a l C o p y r i g h t   C o p y r i g h t   ( c )   1 9 9 3 - 2 0 2 4   t h e   W i n e   p r o j e c t   a u t h o r s   ( s e e   t h e   f i l e   A U T H O R S   f o r   a   c o m p l e t e   l i s t )   >   O r i g i n a l F i l e n a m e   w s 2 _ 3 2 . d l l     *   P r o d u c t N a m e     W i n e     @   P r o d u c t V e r s i o n   5 . 1 . 2 6 0 0 . 5 5 1 2   D     V a r F i l e I n f o     $    T r a n s l a t i o n     	�