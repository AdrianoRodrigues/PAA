#!/bin/bash

echo "g++ -std=c++11 -O3 -w knapsack.cpp -o bin/knapsack"
g++ -std=c++11 -O3 -w knapsack.cpp -o bin/knapsack

for input in kp0*.txt; do
	echo "time ./bin/knapsack < $input"
	time ./bin/knapsack < $input
done

echo "g++ -std=c++11 -O3 -w knapsack_improved.cpp -o bin/knapsack_improved"
g++ -std=c++11 -O3 -w knapsack_improved.cpp -o bin/knapsack_improved

for input in kp0*.txt; do
	echo "time ./bin/knapsack_improved < $input"
	time ./bin/knapsack_improved < $input
done

sudo shutdown -h 1 "O notebook será desligado em 1 minuto."