bash theoretical_size.sh

mcs csharp-objekt.cs
./csharp-objekt.exe

mcs csharp-objekt-dynamic.cs
./csharp-objekt-dynamic.exe

mcs csharp-hashmap.cs
./csharp-hashmap.exe

g++ -O3 -o c++-objekt-char-array c++-objekt-char-array.cpp -std=c++0x -lprocps
./c++-objekt-char-array

g++ -O3 -o c++-objekt-string c++-objekt-string.cpp -std=c++0x -lprocps
./c++-objekt-string

g++ -fno-builtin-strdup  -O3 -o c++-objekt-unoptimized c++-objekt-unoptimized.cpp  -l procps
./c++-objekt-unoptimized

g++ -O3 -w -o c++-hashmap c++-hashmap.cpp -std=c++0x -lprocps
./c++-hashmap

javac java_objekt.java
java -Xmx2048m -Xms1m java_objekt

javac java_hashmap.java
java -Xmx2048m -Xms1m java_hashmap

php5.6 php-objekt-deklariert.php 5.6

php5.6 php-objekt-nicht-deklariert.php 5.6

php5.6 php-array.php 5.6

php5.6 php-stdclass.php 5.6

php7.0 php-objekt-deklariert.php 7.0

php7.0 php-objekt-nicht-deklariert.php 7.0

php7.0 php-array.php 7.0

php7.0 php-stdclass.php 7.0

perl perl-hashmap.pl

python python-hashmap.py

python python-objekt.py

node js-objekt.js
