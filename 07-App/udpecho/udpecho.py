import socket

request    = "poipoipoipoi"
myAddress  = '' #means 'all'
myPort     = 21568
hisAddress = 'bbbb::1415:920b:0301:00e9'
hisPort    = 7
succ       = 0
fail       = 0
print "Testing udpEcho..."

for i in range(10):
   print "echo " + str(i)
   socket_handler = socket.socket(socket.AF_INET6,socket.SOCK_DGRAM)
   socket_handler.settimeout(5)
   socket_handler.bind((myAddress,myPort))
   socket_handler.sendto(request,(hisAddress,hisPort))
   print "\nrequest "+myAddress+"%"+str(myPort)+" -> "+hisAddress+"%"+str(hisPort)
   print request+" ("+str(len(request))+" bytes)"
   try:
      reply,dist_addr = socket_handler.recvfrom(1024)
   except socket.timeout:
      print "\nno reply"
      fail=fail+1
   else:
      print "\nreply "+str(dist_addr[0])+"%"+str(dist_addr[1])+" -> "+myAddress+"%"+str(myPort)
      print reply+" ("+str(len(reply))+" bytes)"
      succ=succ+1
   socket_handler.close()

print "success " + str(succ) + " fail " + str(fail)
raw_input("\nPress return to close this window...")
