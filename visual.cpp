#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

const int tickrate = 5;


int* generateRandomArrayMassive(size_t size, int minValue, int maxValue) {
    int* arr = new int[size]; // Выделяем память для массива
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);

    for (size_t i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }

    return arr;
}

vector<int> generateRandomArray(size_t size, int minValue, int maxValue) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minValue, maxValue);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
    return arr;
}

void drawArray(RenderWindow &window, const vector<int> &arr) {
    window.clear(Color::Black);
    float barWidth = static_cast<float>(window.getSize().x) / arr.size();
    for (size_t i = 0; i < arr.size(); ++i) {
        RectangleShape bar(Vector2f(barWidth - 2, static_cast<float>(arr[i])));
        bar.setFillColor(Color::White);
        bar.setPosition(i * barWidth, window.getSize().y - arr[i]);
        window.draw(bar);
    }
    window.display();
}

void drawArrayAndTimer(RenderWindow &window, const vector<int> &arr, Text &timerText) {
    window.clear(Color::Black);
    float barWidth = static_cast<float>(window.getSize().x) / arr.size();
    for (size_t i = 0; i < arr.size(); ++i) {
        RectangleShape bar(Vector2f(barWidth - 2, static_cast<float>(arr[i])));
        bar.setFillColor(Color::White);
        bar.setPosition(i * barWidth, window.getSize().y - arr[i]);
        window.draw(bar);
    }
    window.draw(timerText);
    window.display();
}

void bubbleSortStep(sf::RenderWindow &window, std::vector<int> &arr, sf::Text &timerText, sf::Clock &clock) {
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                sf::Time elapsed = clock.getElapsedTime();
                timerText.setString("Time: " + std::to_string(elapsed.asSeconds()) + " s");
                drawArrayAndTimer(window, arr, timerText);
                std::this_thread::sleep_for(std::chrono::milliseconds(tickrate));
            }
        }
        if (!swapped) break;
    }
}

void heapify(RenderWindow &window, vector<int> &arr, int n, int i, Text &timerText, Clock &clock) {
    int largest = i;   
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        Time elapsed = clock.getElapsedTime();
        timerText.setString("Time: " + to_string(elapsed.asSeconds()) + " s");
        drawArrayAndTimer(window, arr, timerText);
        this_thread::sleep_for(chrono::milliseconds(tickrate));
        heapify(window, arr, n, largest, timerText, clock);
    }
}

void heapSort(RenderWindow &window, vector<int> &arr, Text &timerText, Clock &clock) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(window, arr, n, i, timerText, clock);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        Time elapsed = clock.getElapsedTime();
        timerText.setString("Time: " + to_string(elapsed.asSeconds()) + " s");
        drawArrayAndTimer(window, arr, timerText);
        this_thread::sleep_for(chrono::milliseconds(tickrate));
        heapify(window, arr, i, 0, timerText, clock);
    }
}

void visualPLS(int a = 0) 
{
    RenderWindow window(VideoMode(800, 600), "Heap Sort Visualization");

    size_t arraySize = 50; 
    int minValue = 50;
    int maxValue = 500;
    vector<int> arr = generateRandomArray(arraySize, minValue, maxValue);

    Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cerr << "Ошибка загрузки шрифта!" << endl;
        return;
    }
    Text timerText;
    timerText.setFont(font);
    timerText.setCharacterSize(24);
    timerText.setFillColor(Color::White);
    timerText.setPosition(10, 10);

    Clock clock;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        drawArrayAndTimer(window, arr, timerText);
        this_thread::sleep_for(chrono::seconds(1));

        if(a == 0)
        {
            heapSort(window, arr, timerText, clock);
        }
        else
        {
            bubbleSortStep(window, arr, timerText, clock);
        }

        timerText.setFillColor(Color::Red);
        drawArrayAndTimer(window, arr, timerText);
        this_thread::sleep_for(chrono::seconds(2));
        window.close();
    }
}