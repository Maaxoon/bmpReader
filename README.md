bmpReader - консольная утилита для просмотра BMP файлов с выводом в консоль.  

Сборка:  
mkdir build  
cd build  
cmake ..\    
cmake --build . --config Release  

Тестирование:
cd Release
.\drawBmp.exe ..\\..\samples\2.bmp  

Использование:  
drawBmp.exe <путь_до_BMP>  
