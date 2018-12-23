Ex2_1Display.o : Ex2_1Display.cpp
	g++ -o main Ex2_1Display.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs	 
Ex2_3Video.o : Ex2_3Video.cpp
	g++ -o main Ex2_3Video.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
Ex2_4Trackbar.o : Ex2_4Trackbar.cpp
	g++ -o main Ex2_4Trackbar.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
Ex2_5Transoformation.o : Ex2_5Transoformation.cpp
	g++ -o main Ex2_5Transoformation.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
Ex2_6.o : Ex2_6.cpp
	g++ -o main Ex2_6.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
Ex2_7Edge.o : Ex2_7Edge.cpp
	g++ -o main Ex2_7Edge.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
Ex2_9.o : Ex2_9.cpp
	g++ -o main Ex2_9.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
Ex2_11VidoeWrite.o : Ex2_11VidoeWrite.cpp
	g++ -o main Ex2_11VidoeWrite.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
2_34.o : 2_34.cpp
	g++ -o main 2_34.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
2_5.o : 2_5.cpp
	g++ -o main 2_5.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_videostab -lopencv_imgproc
clean:
	rm -f main
	