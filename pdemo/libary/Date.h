#ifndef DATE_H
#define DATE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

class Date {
public:
    int Day, Month, Year;

    Date(int day = 1, int month = 1, int year = 2024) : Day(day), Month(month), Year(year) {}

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysInMonth(int month, int year) {
        switch (month) {
            case 2: return isLeapYear(year) ? 29 : 28;
            case 4: case 6: case 9: case 11: return 30;
            default: return 31;
        }
    }

    int getStartDay(int month, int year) {
        int day = 1;
        int y = year - (14 - month) / 12;
        int x = y + y / 4 - y / 100 + y / 400;
        int m = month + 12 * ((14 - month) / 12) - 2;
        return (day + x + (31 * m) / 12) % 7;
    }

    string createDateString() const {
        return  to_string(Day) + "-" + to_string(Month) + "-" + to_string(Year);
    }

    void drawCalendar(RenderWindow& window, Font& font, int month, int year, int selectedDay) {
        const string daysOfWeek[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        const string months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };

        int startDay = getStartDay(month, year);
        int daysInMonth = this->daysInMonth(month, year);

        Text title;
        title.setFont(font);
        title.setString(months[month - 1] + " " + to_string(year));
        title.setCharacterSize(30);
        title.setFillColor(Color::Black);
        title.setPosition(200, 20);
        window.draw(title);

        for (int i = 0; i < 7; i++) {
            Text dayText;
            dayText.setFont(font);
            dayText.setString(daysOfWeek[i]);
            dayText.setCharacterSize(20);
            dayText.setFillColor(Color::Black);
            dayText.setPosition(100 + i * 60, 80);
            window.draw(dayText);
        }

        int currentX = 100 + startDay * 60;
        int currentY = 120;
        for (int day = 1; day <= daysInMonth; day++) {
            RectangleShape dayBox(Vector2f(50, 30));
            dayBox.setFillColor(day == selectedDay ? Color::Red : Color::Transparent);
            dayBox.setOutlineColor(Color::Black);
            dayBox.setOutlineThickness(1);
            dayBox.setPosition(currentX, currentY);
            window.draw(dayBox);

            Text dayNumber;
            dayNumber.setFont(font);
            dayNumber.setString(to_string(day));
            dayNumber.setCharacterSize(20);
            dayNumber.setFillColor(Color::Black);
            dayNumber.setPosition(currentX + 10, currentY);
            window.draw(dayNumber);

            currentX += 60;
            if ((startDay + day) % 7 == 0) {
                currentX = 100;
                currentY += 40;
            }
        }
    }

    void selectDate(RenderWindow& window, Font& font) {
        int selectedDay = Day;
        int selectedMonth = Month;
        int selectedYear = Year;
        bool dateSelected = false;

        RectangleShape prevMonthButton(Vector2f(30, 30)), nextMonthButton(Vector2f(30, 30)), saveButton(Vector2f(100, 30));
        prevMonthButton.setFillColor(Color::Blue);
        nextMonthButton.setFillColor(Color::Blue);
        saveButton.setFillColor(Color::Green);

        prevMonthButton.setPosition(50, 20);
        nextMonthButton.setPosition(700, 20);
        saveButton.setPosition(350, 500);

        while (window.isOpen() && !dateSelected) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed) window.close();

                 if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                        int mouseX = event.mouseButton.x;
                        int mouseY = event.mouseButton.y;

                            if (prevMonthButton.getGlobalBounds().contains(mouseX, mouseY)) {
                                    selectedMonth = (selectedMonth == 1) ? 12 : selectedMonth - 1;
                                    if (selectedMonth == 12) selectedYear--;
                                }
                                if (nextMonthButton.getGlobalBounds().contains(mouseX, mouseY)) {
                                    selectedMonth = (selectedMonth == 12) ? 1 : selectedMonth + 1;
                                    if (selectedMonth == 1) selectedYear++;
                                }

                                if (saveButton.getGlobalBounds().contains(mouseX, mouseY)) {
                                    Day = selectedDay;
                                    Month = selectedMonth;
                                    Year = selectedYear;
                                    dateSelected = true;
                                    string selectedDateString = createDateString();
                                    cout << "Selected date: " << selectedDateString << endl;
                                }

                                int startDay = getStartDay(selectedMonth, selectedYear);
                                int currentX = 100 + startDay * 60;
                                int currentY = 120;

                                for (int day = 1; day <= daysInMonth(selectedMonth, selectedYear); day++) {
                                    FloatRect dayRect(currentX, currentY, 50, 30);
                                    if (dayRect.contains(static_cast<float>(mouseX), static_cast<float>(mouseY))) {
                                        selectedDay = day;
                                    }
                                    currentX += 60;
                                    if ((startDay + day) % 7 == 0) {
                                        currentX = 100;
                                        currentY += 40;
                                    }
                                }
                            }
                        }

            window.clear(Color::White);
            window.draw(prevMonthButton);
            window.draw(nextMonthButton);

            Text saveText("Choose", font, 20);
            saveText.setPosition(365, 505);
            saveText.setFillColor(Color::Black);
            window.draw(saveButton);
            window.draw(saveText);

            drawCalendar(window, font, selectedMonth, selectedYear, selectedDay);
            window.display();
        }
    }
};

#endif
