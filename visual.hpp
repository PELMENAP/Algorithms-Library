#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int* generateRandomArrayMassive(size_t size, int minValue, int maxValue);
vector<int> generateRandomArray(size_t size, int minValue, int maxValue);

void drawArray(RenderWindow &window, const vector<int> &arr);

void drawArrayAndTimer(RenderWindow &window, const vector<int> &arr, Text &timerText);

void bubbleSortStep(sf::RenderWindow &window, std::vector<int> &arr, sf::Text &timerText, sf::Clock &clock);

void heapify(RenderWindow &window, vector<int> &arr, int n, int i, Text &timerText, Clock &clock);

void heapSort(RenderWindow &window, vector<int> &arr, Text &timerText, Clock &clock);

void visualPLS(int a = 0);