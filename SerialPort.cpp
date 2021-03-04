#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"
#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

using namespace std;
using namespace sf;



//application reads from the specified serial port and reports the collected data
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Welcome to the serial Comm app!\n\n" << endl;

	Serial* SP = new Serial("\\\\.\\COM18");    // Setting COM port

	if (SP->IsConnected())
		cout << "We're connected \n" << endl;

	char incomingData[3] = "";			// pre-allocate memory
	int dataLength = 3;
	int readResult = 0;
	//graphic(incomingData);


	Texture gui, greenLed, redLed, blueLed, arm;
	Sprite background, green, red, blue, armB, irs;
	RenderWindow window(VideoMode(1280, 1024), "TollBooth GUI");


	gui.loadFromFile("Metal.png");
	greenLed.loadFromFile("Green-Button-Off.png");
	redLed.loadFromFile("Red-Button-Off.png");
	blueLed.loadFromFile("Blue-Button-Off.png");
	arm.loadFromFile("armDown.png");
	background.setTexture(gui);

	// green LED status
	green.setTexture(greenLed);
	green.setPosition(25, 5);

	// red LED status
	red.setTexture(redLed);
	red.setPosition(550, 5);



	// blue LED status
	blue.setTexture(blueLed);
	blue.setPosition(1125, 5);

	// arm settings
	armB.setTexture(arm);
	armB.setPosition(0, 155);

		window.draw(background);
		window.draw(armB);
		window.draw(green);
		window.draw(red);
		window.draw(blue);
		window.display();
		
		
		while (window.isOpen())
		{

			char data[6] = "";
			Event close;
			while (window.pollEvent(close))
				if (close.type == Event::Closed)
					window.close();

		
			string test(incomingData);
			for (int i = 0; i < 6; i++){
				SP->ReadData(incomingData, dataLength);
				data[i] = incomingData[i];
				cout << data[i] << endl;
			}
			

				if (data[0] == '1')
				{
					greenLed.loadFromFile("Green-Button-On.png");
					arm.loadFromFile("armMov.png");
					window.draw(background);
					window.draw(armB);
					window.draw(green);
					window.draw(red);
					window.draw(blue);
					window.display();
				}
				else
				{
					greenLed.loadFromFile("Green-Button-Off.png");
					arm.loadFromFile("armDown.png");
					window.draw(background);
					window.draw(armB);
					window.draw(green);
					window.draw(red);
					window.draw(blue);
					window.display();
				}


				if (data[1] == '1')
				{
					redLed.loadFromFile("Red-Button-On.png");
					arm.loadFromFile("armUp.png");
					window.draw(background);
					window.draw(armB);
					window.draw(green);
					window.draw(red);
					window.draw(blue);
					window.display();
				}
				else
				{
					redLed.loadFromFile("Red-Button-Off.png");
					arm.loadFromFile("armDown.png");
					window.draw(background);
					window.draw(armB);
					window.draw(green);
					window.draw(blue);
					window.draw(red);
					window.display();
				}

				if (data[2] == '1')
				{
					blueLed.loadFromFile("Blue-Button-On.png");
					arm.loadFromFile("armDown.png");
					window.draw(background);
					window.draw(armB);
					window.draw(green);
					window.draw(red);
					window.draw(blue);
					window.display();
				}
				else
				{
					blueLed.loadFromFile("Blue-Button-Off.png");
					window.draw(background);
					window.draw(armB);
					window.draw(green);
					window.draw(red);
					window.draw(blue);
					window.display();
				}
		}	
	system("pause");
	return 0;
}

// IRS = 0
// Lower Limit = 1
// Upper Limit = 2
