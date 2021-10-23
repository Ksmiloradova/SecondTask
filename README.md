# SecondTask
Второе домашнее задание по предмету "Архитектура вычислительных систем" студента Милорадовой Ксении группы БПИ206

Формат командной строки
для генераци случайного транспорта:
    -n <transport number><output file> <log file>
для ввода из файла:
    -f <input file> <output file> <log file>

Формат ввода транспорта через файл

самолёт:
	1 <speed> <distance> <flightRange> <loadCapacity>
	speed: 500-900
	flightRange: 5000-20000
	loadCapacity: 16000-150000
поезд:
	1 <speed> <distance> <numberOfWagons>
	speed: 80-200
	numberOfWagons: 1-75
корабль:
	1 <speed> <distance> <displacement> <numberOfShipType>
	speed: 19-67
	displacement: 20000-500000
	numberOfShipType: 1-3
