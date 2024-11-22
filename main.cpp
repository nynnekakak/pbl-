#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void add()
{
    RenderWindow window(VideoMode(800, 1000), "Them Thong Tin");
    Font font;
    if (!font.loadFromFile("D:/font/arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return;
    }

    // Tạo hai hình chữ nhật đại diện cho các tùy chọn
    RectangleShape doctorBox(Vector2f(200, 100));
    doctorBox.setFillColor(Color::Blue);
    doctorBox.setPosition(300, 200);

    RectangleShape patientBox(Vector2f(200, 100));
    patientBox.setFillColor(Color::Green);
    patientBox.setPosition(300, 400);

    // Tạo text bên trong hình chữ nhật
    Text doctorText("Bac Si", font, 25);
    doctorText.setFillColor(Color::White);
    doctorText.setPosition(doctorBox.getPosition().x + 50, doctorBox.getPosition().y + 30);

    Text patientText("Benh Nhan", font, 25);
    patientText.setFillColor(Color::White);
    patientText.setPosition(patientBox.getPosition().x + 30, patientBox.getPosition().y + 30);

    // Text thông báo
    Text message("", font, 30);
    message.setFillColor(Color::Red);
    message.setPosition(300, 600);

    // Cờ trạng thái
    bool isDoctor = false;
    bool isPatient = false;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                if (doctorBox.getGlobalBounds().contains(mousePos)) {
                    isDoctor = true;
                    isPatient = false;
                    message.setString("Dang nhap thong tin Bac Si");
                }
                else if (patientBox.getGlobalBounds().contains(mousePos)) {
                    isPatient = true;
                    isDoctor = false;
                    message.setString("Dang nhap thong tin Benh Nhan");
                }
            }
        }

        window.clear(Color::White);

        // Nếu chưa chọn, hiển thị các tùy chọn
        if (!isDoctor && !isPatient) {
            window.draw(doctorBox);
            window.draw(patientBox);
            window.draw(doctorText);
            window.draw(patientText);
        }
        else if (isDoctor) {
            // Giao diện nhập thông tin bác sĩ
            Text doctorInfo("Nhap thong tin Bac Si o day...", font, 20);
            doctorInfo.setFillColor(Color::Blue);
            doctorInfo.setPosition(50, 700);
            window.draw(doctorInfo);
        }
        else if (isPatient) {
            // Giao diện nhập thông tin bệnh nhân
            Text patientInfo("Nhap thong tin Benh Nhan o day...", font, 20);
            patientInfo.setFillColor(Color::Green);
            patientInfo.setPosition(50, 700);
            window.draw(patientInfo);
        }

        window.draw(message);
        window.display();
    }
}
