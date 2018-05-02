sAll: server.o client.o  imagTrans.o
	g++ server.o imagTrans.o -o server/server
	g++ client.o imagTrans.o -o client/client

server.o: server.cc
	g++ -c server.cc

client.o: client.cc
	g++ -c client.cc

imagTrans.o: imagTrans.cc imagTrans.h
	g++ -c imagTrans.cc

clean:
	rm *.o server/server client/client