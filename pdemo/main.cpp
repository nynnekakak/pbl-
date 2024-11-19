#include<string.h>
#include <fstream>
#include <SFML/Graphics.hpp>
#include"libary/Textbox.h"
#include"libary/Date.h"
#include<math.h>
#include<cmath>
#include<iostream>

using namespace sf;
using namespace std;

void PatientInfo(const string& info);

struct scn2
{
	bool email = false;
	bool password = false;
};

struct scn3
{
	bool email = false;
	bool confirmEmail = false;
	bool password = false;
	bool confirmPassword = false;
};
struct scn4
{
	bool find= false;
};
struct account
{
	string email;
	string password;
};

int scene = 1, i = 1;
scn2 scene2;
scn3 scene3;
scn4 scene4;
account acc[100];
bool first = true;
int showErrorPopup = 0;
bool sign=false;

string checkid(const string& searchSBD) {
    ifstream inFile("ID.txt");
	ifstream in("Doctor.txt");
   	string line;
    string result = "Could not found CCCD/Ma: " + searchSBD;
    bool idFound = false;
    string patientInfo;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            if (line.find("CCCD:") == 0 && line.substr(5) == searchSBD) {
                idFound = true;
                patientInfo += line + "\n";  
            }
            else if (idFound) {
                if (line.empty()) break; 
				patientInfo += line + "\n";
            }
        }
	}
    inFile.close();
	if(in.is_open()){
		 while (getline(in, line)) {
            if (line.find("Ma:") == 0 && line.substr(3) == searchSBD) {
                idFound = true;
                patientInfo += line + "\n";  
            }
            else if (idFound) {
                if (line.empty()) break; 
				patientInfo += line + "\n";
            }
        }
	}
		in.close();
    return idFound ? patientInfo : result;
}
void phongkham (bool roomStatus[5][4],string *b)
{		
	RenderWindow window (VideoMode(710,800),"Phong kham" );
	Texture square;
	Texture giuong;
	Texture background;
	Texture cakham;
	Texture ca;
	Texture back;
	Texture plush,minor;

	back.loadFromFile("D:image/back.png");
	ca.loadFromFile("D:image/ca.png");
	cakham.loadFromFile("D:image/cakham.jpg");
	background.loadFromFile("D:image/clinic2.jpg");
	giuong.loadFromFile("D:image/giuong.png");
	square.loadFromFile("D:image/square.png");
	plush.loadFromFile("D:image/plush.png");
	minor.loadFromFile("D:image/minor.png");

	Sprite Square(square);
	Sprite Giuong(giuong);
	Sprite Background(background);
	Sprite Cakham(cakham);
	Sprite Ca(ca);
	Sprite Back(back);
	Sprite cong(plush);
	Sprite tru(minor);

	Font arial;
	arial.loadFromFile("arial.ttf");
	Clock clock;

	Text full ("FULL",arial,24);
	full.setFillColor(Color(178, 34, 34));
	Text Room1("Room1",arial,24);
    Room1.setFillColor(Color(178, 34, 34));
	Text Room2("Room2",arial,24);
    Room2.setFillColor(Color(178, 34, 34));
	Text Room3("Room3",arial,24);
    Room3.setFillColor(Color(178, 34, 34));
	Text Room4("Room4",arial,24);
    Room4.setFillColor(Color(178, 34, 34));
	Text Ca1("Ca1",arial,24);
    Ca1.setFillColor(Color(178, 34, 34));
	Text Ca2("Ca2",arial,24);
    Ca2.setFillColor(Color(178, 34, 34));
	Text Ca3("Ca3",arial,24);
    Ca3.setFillColor(Color(178, 34, 34));
	Text Name("Phong Kham Nha Khoa Nin Huy",arial,45);

	int sm=1,i=4;
	while (window.isOpen() )
	{
		float time = clock.getElapsedTime().asSeconds();

			Uint8 red = static_cast<Uint8>(abs(sin(time * 1.5f)) * 255);
			Uint8 green = static_cast<Uint8>(abs(sin(time * 0.8f)) * 255);  
			Uint8 blue = static_cast<Uint8>(abs(sin(time * 1.1f)) * 255);  
			Name.setFillColor(sf::Color(red, green, blue));
		Event e;
	while (window.pollEvent(e))
	{
	  if (e.type == Event::Closed)
                window.close();
	if (e.type == Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == Mouse::Left)
				{
					int x = Mouse::getPosition(window).x;
					int y = Mouse::getPosition(window).y;
					if(sm==1)
					{
						if(x>=181 && x<=309 && y>=198 && y<=326)
							{sm=2;i=0;
							}
						if(x>=410 && x<=538 && y>=198 && y<=326)
							{sm=2;i=1;}
						if(x>=181 && x<=309 && y>=415 && y<=543)
							{sm=2;i=2;}
						if(x>=410 && x<=538 && y>=415 && y<=543)
							{sm=2;i=3;}
					}
					if (sm==2)
					{ //back
						if (x >= 15 && x <= 143 && y >= 672 && y <= 800) {
										sm = 1;
									}
						if (x >=291 && 	x<=	419 && y>=	208 && y<=	336)
						{
							int j=0;
							string id=b[i*2+j];
							if (!id.empty())
								{	
								string info =checkid(id);
								 PatientInfo(info);
								}
						}
						if (x >=291 && 	x<=	419 && y>=	336 && y<=	464)
						{
							int j=1;
							string id=b[i*2+j];
							if (!id.empty())
								{	
								string info =checkid(id);
								 PatientInfo(info);
								}
						}
						if (x >=291 && 	x<=	419 && y>=	464 && y<=	592)
						{
							int j=2;
							string id=b[i*2+j];
							if (!id.empty())
								{	
								string info =checkid(id);
								 PatientInfo(info);
								}
						}

					}
				}
			}
	}
	window.clear(Color::Green);

	if(sm==1)
	{	
		window.draw(Background);
		Name.setPosition (30,10);
		window.draw(Name);
	if (!roomStatus[0][3])
		{
			Square.setPosition(181,198);
			window.draw(Square);
			Room1.setPosition(Square.getPosition().x+50,Square.getPosition().y+70);
			window.draw(Room1);
		} 
		else { 
				Giuong.setPosition(181,198);
				window.draw(Giuong);
				full.setPosition(Giuong.getPosition().x+50,Giuong.getPosition().y+70);
				window.draw(full);
			}
	if (!roomStatus[1][3])
			{Square.setPosition(410,198);
			window.draw(Square);
			Room2.setPosition(Square.getPosition().x+50,Square.getPosition().y+70);
			window.draw(Room2);
			}
			else { 
			Giuong.setPosition(410,198);
			window.draw(Giuong);
			full.setPosition(Giuong.getPosition().x+50,Giuong.getPosition().y+70);
			window.draw(full);
			}
	if (!roomStatus[2][3])
	{
			Square.setPosition(181,415);
			window.draw(Square);
			Room3.setPosition(Square.getPosition().x+50,Square.getPosition().y+70);
			window.draw(Room3);
	}
	else{
			Giuong.setPosition(181,415);
			window.draw(Giuong);
			full.setPosition(Giuong.getPosition().x+50,Giuong.getPosition().y+70);
			window.draw(full);
	}
	if (!roomStatus[3][3])
	{
			Square.setPosition(410,415);
			window.draw(Square);
			Room4.setPosition(Square.getPosition().x+50,Square.getPosition().y+70);
			window.draw(Room4);
	}
	else {
			Giuong.setPosition(410,415);
			window.draw(Giuong);
			full.setPosition(Giuong.getPosition().x+50,Giuong.getPosition().y+70);
			window.draw(full);
	}
	}
	if (sm==2)
	{	
		Cakham.setPosition(155,100);
		window.draw(Cakham);
		Name.setPosition (30,10);
		window.draw(Name);
			if (!roomStatus[i][0])
			{
			Ca.setPosition(291,208);
			window.draw(Ca);
			Ca1.setPosition(Ca.getPosition().x+50,Ca.getPosition().y+70);
			window.draw(Ca1);
			}
			else {
			Ca.setPosition(291,208);
			window.draw(Ca);
			full.setPosition(Ca.getPosition().x+50,Ca.getPosition().y+70);
			window.draw(full);
			}
			if (!roomStatus[i][1])
			{
			Ca.setPosition(291,336);
			window.draw(Ca);
			Ca2.setPosition(Ca.getPosition().x+50,Ca.getPosition().y+70);
			window.draw(Ca2);
			}
			else {
			Ca.setPosition(291,336);
			window.draw(Ca);
			full.setPosition(Ca.getPosition().x+50,Ca.getPosition().y+70);
			window.draw(full);
			}
			if (!roomStatus[i][2])
			{
			Ca.setPosition(291,464);
			window.draw(Ca);
			Ca3.setPosition(Ca.getPosition().x+50,Ca.getPosition().y+70);
			window.draw(Ca3);
			}
			else {
			Ca.setPosition(291,464);
			window.draw(Ca);
			full.setPosition(Ca.getPosition().x+50,Ca.getPosition().y+70);
			window.draw(full);
			}
	Back.setPosition(15,672);
	window.draw(Back);
	cong.setPosition(250,672);
	window.draw(cong);
	tru.setPosition(450,672);
	window.draw(tru);
	}
	window.display();
			}	
}

string* checkAvailability(const string& date, bool roomStatus[5][4]) {
    ifstream file("clinic.txt");
    string fileDate;
	int  room,slot;
	string a;
	string* ID=new string [12];
    for (int i = 0; i <4; i++)
        for (int j = 0; j <3; j++)
            roomStatus[i][j] = false;
    while (file >>fileDate >> room >> slot >> a) {
        if (fileDate == date) {
            int roomIndex = room - 1;
            int slotIndex = slot - 1;
            roomStatus[roomIndex][slotIndex] = true;
			ID[roomIndex*2+slotIndex]=a;
        }
    }
		 file.close();
	 for (int i=0;i<4;i++){ 		
			bool isfull=true;
			for (int j=0 ; j< 3 ;j++)
				{
				if ( !roomStatus[i][j]) 
						{isfull=false;
						break;}
				}
			roomStatus[i][3]=isfull;
		}
		return ID;
}
void quydinh(const string& filename)
{
	RenderWindow window(VideoMode(1000, 1000), "Quy Định");
    ifstream file(filename);
    string line;
    stringstream content;

    while (getline(file, line)) {
        content << line << "\n";
    }

    file.close();

    Font font;
    font.loadFromFile("arial.ttf");

	Text bang("QUY DINH PHONG KHAM",font,30);
	bang.setFillColor(Color::Red);
	bang.setPosition(325,0);
    Text text(content.str(), font, 15);
    text.setFillColor(Color::White);
    text.setPosition(20, 20);

    RectangleShape background(Vector2f(1000,1000));
    background.setFillColor(Color(50, 50, 50));

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);
        window.draw(background);
        window.draw(text);
		window.draw(bang);
        window.display();
    }
}
void PatientInfo(const string& info) {
    RenderWindow window(VideoMode(500, 400), "INFORMATION");

    Font font;
    font.loadFromFile("arial.ttf");
	string h;
	if(info[0]=='C')
	{
		h="Thong tin Benh Nhan";
	}
	else if (info[0]=='M')
	{
		h="Thong tin Bac si";
	}
	Text title(h, font, 24);
    title.setFillColor(Color(0, 102, 204)); 
    title.setStyle(Text::Bold);
    title.setPosition(20, 20);
  
    Text text(info, font, 20);
    text.setFillColor(Color::Black);
    text.setPosition(20, 70);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        window.draw(title);
        window.draw(text);
        window.display();
    }
}
void display(const string& filename) {
	ifstream file(filename);
    RenderWindow window(VideoMode(800, 600), "INFORMATION");

    Font font;
    font.loadFromFile("arial.ttf");

    map<string, vector<pair<string, string>>> idData;
    string line;
    string currentID;

    while (getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            string firstPart = line.substr(0, pos);
            string secondPart = line.substr(pos + 1);
            if (firstPart == "CCCD"|| firstPart =="Ma") {
                currentID = secondPart;
            } else if(firstPart == "Ho va Ten") {
                idData[currentID].emplace_back(firstPart, secondPart);
            }
        }
    }
    file.close();

    float itemHeight = 30;
    float scrollOffset = 0;
    float maxScroll = window.getSize().y;
    
    int startX = 50;
    int startY = 100;
    int colWidth = 350;
    int rowHeight = 30;

    RectangleShape scrollbar(Vector2f(10, 100));
    scrollbar.setFillColor(Color::Black);
    scrollbar.setPosition(window.getSize().x - 20, 100);

    auto it = idData.begin();  // Duyệt qua từng ID

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Right) {
                    if (++it == idData.end()) it = idData.begin();  
                    scrollOffset = 0;  
                } else if (event.key.code == Keyboard::Left) {
                    if (it == idData.begin()) it = idData.end();
                    --it;  
                    scrollOffset = 0;  
                }
            } else if (event.type == Event::MouseWheelScrolled) {
                scrollOffset -= event.mouseWheelScroll.delta * 15;
                if (scrollOffset < 0) scrollOffset = 0;
                if (scrollOffset > maxScroll) scrollOffset = maxScroll;

                float scrollbarHeight = (window.getSize().y / float(it->second.size() * rowHeight)) * window.getSize().y;
                scrollbar.setSize(Vector2f(10, scrollbarHeight));
                scrollbar.setPosition(window.getSize().x - 20, 100 + (scrollOffset / maxScroll) * (window.getSize().y - scrollbarHeight));
            }
        }

        window.clear(Color::White);

        if(filename=="ID.txt"){
        Text tieude("Thong tin benh nhan: " + it->first, font, 34);
        tieude.setFillColor(Color::Green);
        tieude.setStyle(Text::Bold);
        tieude.setPosition(80, 20);
        window.draw(tieude);
		}
		else{
		Text tieude("Thong tin bac si: " + it->first, font, 34);
        tieude.setFillColor(Color::Green);
        tieude.setStyle(Text::Bold);
        tieude.setPosition(80, 20);
        window.draw(tieude);
		}

        // Hiển thị bảng dữ liệu cho ID hiện tại
        int visibleRows = window.getSize().y / rowHeight;
        int startIndex = scrollOffset / itemHeight;

        for (size_t i = startIndex; i < it->second.size() && static_cast<int>(i) < startIndex + visibleRows; ++i) {
            float yPos = startY + (i - startIndex) * rowHeight;

            Text firstColumnText(it->second[i].first, font, 20);
            firstColumnText.setFillColor(Color::Black);
            firstColumnText.setPosition(startX + 50, yPos);
            window.draw(firstColumnText);

            Text secondColumnText(it->second[i].second, font, 20);
            secondColumnText.setFillColor(Color::Black);
            secondColumnText.setPosition(startX + colWidth - 50, yPos);
            window.draw(secondColumnText);

            RectangleShape firstBox(Vector2f(colWidth - 100, rowHeight));
            firstBox.setPosition(startX, yPos);
            firstBox.setFillColor(Color::Transparent);
            firstBox.setOutlineColor(Color::Black);
            firstBox.setOutlineThickness(1);
            window.draw(firstBox);

            RectangleShape secondBox(Vector2f(colWidth + 100, rowHeight));
            secondBox.setPosition(startX + colWidth - 100, yPos);
            secondBox.setFillColor(Color::Transparent);
            secondBox.setOutlineColor(Color::Black);
            secondBox.setOutlineThickness(1);
            window.draw(secondBox);
        }

        window.draw(scrollbar);
        window.display();
    }
}
void input() {
    ifstream fin("login.txt", ios::in);
    if (!fin) {
        cerr << "Error: Could not open login.txt\n";
        return;
    }
	i=0;
    while (fin >> acc[i].email) {
        fin >> acc[i].password;
        i++;
    }
    fin.close();
}
void excute()
{
	RenderWindow window(VideoMode(710, 800), "Dental Management ");
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9;
	Texture errorBoxTexture;
	Texture Background1,Background2;
	Texture clinic;
	Texture glass;

	glass.loadFromFile("D:image/glass.png");
	Background1.loadFromFile("D:image/background.jpg");
	t1.loadFromFile("D:image/login.png");
	t2.loadFromFile("D:image/register.png");
	t3.loadFromFile("D:image/email.png");
	t4.loadFromFile("D:image/password.png");
	t5.loadFromFile("D:image/submit.png");
	t6.loadFromFile("D:image/back.png");
	t8.loadFromFile("D:image/confirmPassword.png");
	errorBoxTexture.loadFromFile("D:image/errorbox.png"); 
	clinic.loadFromFile("D:image/clinic.jpg");
	Background2.loadFromFile("D:image/background2.jpg");

	Sprite login(t1);
	Sprite registerr(t2);
	Sprite Email(t3);
	Sprite Password(t4);
	Sprite Submit(t5);
	Sprite Back(t6);
	Sprite ConfirmPassword(t8);
	Sprite errorBox(errorBoxTexture);
	Sprite background1(Background1);
	Sprite guong(glass);
	Sprite Clinic(clinic);
	Sprite background2(Background2);
	

	Font arial;
	arial.loadFromFile("arial.ttf");
	Clock clock;

	Textbox textLoginEmail(30, Color::Black, false,false);
	textLoginEmail.setFont(arial);
	Textbox textLoginPassword(30, Color::Black, false,true);
	textLoginPassword.setFont(arial);
	Textbox textRegisterEmail(30, Color::Black, false,false);
	textRegisterEmail.setFont(arial);
	Textbox textRegisterPassword(30, Color::Black, false,true);
	textRegisterPassword.setFont(arial);
	Textbox textRegisterConfirmPassword(30, Color::Black, false,true);
	textRegisterConfirmPassword.setFont(arial);
	Textbox find(30, Color::Black, false,false);
	find.setFont(arial);

	RectangleShape box(Vector2f(200, 100));
    box.setFillColor(Color(255, 218, 185));
    box.setOutlineColor(Color(128, 0, 128));
    box.setOutlineThickness(2);
	
	CircleShape shape (25.f);
	shape.setOutlineThickness(5.f);
	shape.setOutlineColor(Color(255, 200, 150));
	shape.setFillColor(Color(250, 150, 100));

	Text text1("Doctor", arial, 24);
    text1.setFillColor(Color(178, 34, 34));
	Text text5("regulations", arial, 24);
    text5.setFillColor(Color(178, 34, 34));
	Text text2("Patient", arial, 24);
    text2.setFillColor(Color(178, 34, 34));
	Text text3("FIND", arial, 10);
    text3.setFillColor(Color(178, 34, 34));
	Text text4("Room Status", arial, 24);
    text4.setFillColor(Color(178, 34, 34));
	Text errorMessage1;
	errorMessage1.setFont(arial);
	errorMessage1.setString("Check your account and password again");
	errorMessage1.setCharacterSize(24);
	errorMessage1.setFillColor(Color::Black);
	Text errorMessage2;
	errorMessage2.setFont(arial);
	errorMessage2.setString("Email or password do not match");
	errorMessage2.setCharacterSize(24);
	errorMessage2.setFillColor(Color::Black);
	Text errorMessage3;
	errorMessage3.setFont(arial);
	errorMessage3.setString("Please fill out all fields completely");
	errorMessage3.setCharacterSize(24);
	errorMessage3.setFillColor(Color::Black);
	Text errorMessage4;
	errorMessage4.setFont(arial);
	errorMessage4.setString("account already exists");
	errorMessage4.setCharacterSize(24);
	errorMessage4.setFillColor(Color::Black);
	Text errorButton;
	errorButton.setFont(arial);
	errorButton.setString("OK");
	errorButton.setCharacterSize(40);
	errorButton.setFillColor(Color::Red);
	Text Name;
	Name.setFont(arial);
	Name.setString("Phong Kham Nha Khoa Nin Huy");
	Name.setCharacterSize(45);


	input();

	ofstream fout("login.txt", ios::in | ios::out);

	while (window.isOpen())
	{ 
		if (first == true)
		{
			for (int j = 0; j <i; j++)
			{
				fout << acc[j].email << "\n";
				fout << acc[j].password << "\n";
			}
			first = false;
		}
		float time = clock.getElapsedTime().asSeconds();

			Uint8 red = static_cast<Uint8>(abs(sin(time * 1.5f)) * 255);
			Uint8 green = static_cast<Uint8>(abs(sin(time * 0.8f)) * 255);  
			Uint8 blue = static_cast<Uint8>(abs(sin(time * 1.1f)) * 255);  
			Name.setFillColor(sf::Color(red, green, blue));
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.mouseButton.button == Mouse::Left)
				{
					int x = Mouse::getPosition(window).x;
					int y = Mouse::getPosition(window).y;
					if (showErrorPopup) {
					if (x >= 345 && x <= 385 && y >= 450 && y <= 490) { 
									showErrorPopup = 0; 
								}
					}
								if (scene == 1) {
									if (x >= 80 && x <= 330 && y >= 160 && y <= 410) {
										// LOGIN
										scene = 2;
									}

									if (x >= 380 && x <= 630 && y >= 160 && y <= 410) {
										// REGISTER
										scene = 3;
									}
								}

								if (scene == 2) {
									// back
									if (x >= 70 && x <= 198 && y >= 600 && y <= 728) {
										scene = 1;
									}
									if (x >= 105 && x <= 233 && y >= 150 && y <= 278) {
										// click on email
										scene2.email = true;
										textLoginEmail.setSelected(true);
									}
									if (x >= 105 && x <= 233 && y >= 300 && y <= 428) {
										// click on password
										scene2.password = true;
										textLoginPassword.setSelected(true);
									}
									// submit
									if (x >= 505 && x <= 633 && y >= 610 && y <= 738) {
											string e, p;
										e = textLoginEmail.getText();
										p = textLoginPassword.getText();
										if (!e.empty() && !p.empty()) {
											bool a = false;
											for (int j = 0; j <= i; j++) {
												if (e == acc[j].email && p == acc[j].password) {
													scene = 4;
													a = true;
												}
											}
											if (!a) {
												showErrorPopup = 1;
											}
										}
									}
								}

								if (scene == 3) {
									// back
									if (x >= 15 && x <= 143 && y >= 672 && y <= 800) {
										scene = 1;
									}
									// email
									if (x >= 70 && x <= 198 && y >= 50 && y <= 178) {
										scene3.email = true;
										textRegisterEmail.setSelected(true);
									}
									// password
									if (x >= 70 && x <= 198 && y >= 200 && y <= 328) {
										scene3.password = true;
										textRegisterPassword.setSelected(true);
									}
									// confirm password
									if (x >= 70 && x <= 198 && y >= 369 && y <= 497) {
										scene3.confirmPassword = true;
										textRegisterConfirmPassword.setSelected(true);
									}
									// submit
									if (x >= 582 && x <= 710 && y >= 682 && y <= 800) {
										string e, ce, p, cp;
										e = textRegisterEmail.getText();
										p = textRegisterPassword.getText();
										cp = textRegisterConfirmPassword.getText();
										if (!e.empty() && !p.empty() && !cp.empty()) {
											bool check = true;
											for (int j = 0; j <= i; j++) {
												if (e == acc[j].email) {
													check = false;
													showErrorPopup = 4;
													fout.close();
													break;
												}
											}
											if (check) {
												if (p == cp) {
													fout << e << "\n";
													fout << p << "\n";
													fout.close();
													input();
													scene = 1;
												} else {
													showErrorPopup = 2;
												}
											}
										} else {
											showErrorPopup = 3;
										}
									}
								}

								if (scene == 4) {
									// back
									if (x >= 15 && x <= 143 && y >= 672 && y <= 800) {
										scene = 1;
									}
									// tim kiem
									if (x >= 200 && x <= 264 && y >= 100 && y <= 164) {
										scene4.find =true;
										find.setSelected(true);
									}
									// find
									if(x>=500 && x <=550 && y>=115 && y<=165)
									{
										string id;
										id=find.getText();
										if (!id.empty())
											{	
												string info =checkid(id);
												 PatientInfo(info);
											}

									}
									// Doctor
									if (x>=100 && x<=300 && y>=250 && y<=350)
									{
												display ("Doctor.txt");
									}
									// Patient
									if (x>=450 && x<=650 && y>=250 && y<=350)
									{
												display ("ID.txt");
									}
									// Room
									if (x>=100 && x<=300 && y>=450 && y<=550)
									{
											
												RenderWindow window(VideoMode(800, 600), "Calendar Picker");
												Font font;
												font.loadFromFile("arial.ttf");
												Date date(1, 1, 2024);
												date.selectDate(window, font);
												string a=date.createDateString();
												bool roomStatus[5][4];
												string *b= checkAvailability(a,roomStatus);
												phongkham (roomStatus,b);
												delete[] b;
									}
									//quydinh
									if (x>=450 && x<=650 && y>=450 && y<=550)
									{
										quydinh("quydinh.txt");
									}
				}
				}
			}
			if (e.type == Event::TextEntered)
			{
				if (scene == 2)
				{
					if (scene2.email == true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Return))
						{
							textLoginEmail.setSelected(false);
							scene2.email = false;
						}
						else
						{
							textLoginEmail.typedOn(e);
						}
					}
					else if (scene2.password == true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Return))
						{
							textLoginPassword.setSelected(false);
							scene2.password = false;
						}
						else
						{
							textLoginPassword.typedOn(e);
						}
					}
				}
				if (scene == 3)
				{
					if (scene3.email == true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Return))
						{
							textRegisterEmail.setSelected(false);
							scene3.email = false;
						}
						else
						{
							textRegisterEmail.typedOn(e);
						}
					}
					else if (scene3.password == true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Return))
						{
							textRegisterPassword.setSelected(false);
							scene3.password = false;
						}
						else
						{
							textRegisterPassword.typedOn(e);
						}
					}
					else if (scene3.confirmPassword == true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Return))
						{
							textRegisterConfirmPassword.setSelected(false);
							scene3.confirmPassword = false;
						}
						else
						{
							textRegisterConfirmPassword.typedOn(e);
						}
					}
				}
				if (scene == 4)
				{
					if(scene4.find== true)
					{
						if (Keyboard::isKeyPressed(Keyboard::Return))
						{
							find.setSelected(false);
							scene4.find=false;
						}
						else 
						{
							find.typedOn(e);
						}
					}
				}
			}
		}

		 window.clear(Color::White);
		
		if (scene == 1)
		{	
			background1.setPosition(25,25);
			window.draw(background1);
			login.setPosition(80, 160);
			window.draw(login);
			registerr.setPosition(380, 160);
			window.draw(registerr);
		}
		if (scene == 2)
		{	background1.setPosition(25,25);
			window.draw(background1);
			Submit.setPosition(505, 610);
			window.draw(Submit);
			Password.setPosition(105, 300);
			window.draw(Password);
			Email.setPosition(105, 150);
			window.draw(Email);
			Back.setPosition(70, 600);
			window.draw(Back);
			textLoginEmail.setPosition({ 324, 214 });
			textLoginEmail.drawTo(window);
			textLoginPassword.setPosition({ 324, 375 });
			textLoginPassword.drawTo(window);
		}
		if (scene == 3)
		{
			window.draw(background2);
			Submit.setPosition(582, 682);
			window.draw(Submit);
			Back.setPosition(15,672);
			window.draw(Back);
			Email.setPosition(70, 50);
			window.draw(Email);
			Password.setPosition(70, 200);
			window.draw(Password);
			ConfirmPassword.setPosition(70, 369);
			window.draw(ConfirmPassword);
			textRegisterEmail.setPosition({ 324, 120 });
			textRegisterEmail.drawTo(window);
			textRegisterPassword.setPosition({ 324, 264 });
			textRegisterPassword.drawTo(window);
			textRegisterConfirmPassword.setPosition({ 324, 433 });
			textRegisterConfirmPassword.drawTo(window);
		}
		if (scene == 4)
		{	
			
			window.draw(Clinic);
			guong.setPosition(200,100);
			window.draw(guong);
			shape.setPosition(500,115);
			window.draw(shape);
			text3.setPosition(shape.getPosition().x+12.5,shape.getPosition().y+15);
			window.draw(text3);
			Name.setPosition (30,10);
			window.draw(Name);
			Back.setPosition(15,672);
			window.draw(Back);
			box.setPosition(100, 250);
			window.draw(box);
			text1.setPosition(box.getPosition().x + 60, box.getPosition().y + 35);
			window.draw(text1);
			box.setPosition(450, 250);
			window.draw(box);
			text2.setPosition(box.getPosition().x + 60, box.getPosition().y + 35);
			window.draw(text2);
			box.setPosition(100, 450);
			window.draw(box);
			text4.setPosition(box.getPosition().x + 40, box.getPosition().y + 35);
			window.draw(text4);
			box.setPosition(450, 450);
			window.draw(box);
			text5.setPosition(box.getPosition().x + 40, box.getPosition().y + 35);
			window.draw(text5);
			find.setPosition({275,120});
			find.drawTo(window);
		}
		if (showErrorPopup == 1) {
    window.draw(errorBox);
    errorBox.setPosition(120, 330); 
    window.draw(errorMessage1);
    errorMessage1.setPosition(155, 400); 
    window.draw(errorButton);
    errorButton.setPosition(345, 450); 
}
		if (showErrorPopup == 2) {
			window.draw(errorBox);
			errorBox.setPosition(120, 330);
			window.draw(errorMessage2);
			errorMessage2.setPosition(155, 400);
			window.draw(errorButton);
			errorButton.setPosition(345, 450);
		}
		if (showErrorPopup == 3) {
			window.draw(errorBox);
			errorBox.setPosition(120, 330);
			window.draw(errorMessage3);
			errorMessage3.setPosition(155, 400);
			window.draw(errorButton);
			errorButton.setPosition(345, 450);
		}
		if (showErrorPopup == 4) {
			window.draw(errorBox);
			errorBox.setPosition(120, 330);
			window.draw(errorMessage4);
			errorMessage4.setPosition(155, 400);
			window.draw(errorButton);
			errorButton.setPosition(345, 450);
		}
		window.display();
	}
}
int main()
{
	excute();
	return 0;
}	