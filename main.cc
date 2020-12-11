/*
 * main.cc
 *
 * Суть TDD:
 *
 * 1. Пишем код, который не компилируется / не работает
 * 2. Пишем тест к этому коду, который проверяет корректность кода - тест проваливается
 * 3. Делаем так, чтобы тест не проваливался, реализуя минимальный функционал для этого
 * 4. Прогоняем тесты, убеждаясь что всё работает
 * 5. Делаем рефакторинг
 * 6. Прогоняем еще раз тесты, убеждаясь что всё работает
 * 7. Переходим к пункту 1
 *
 *
 *
 *+  ОЗУ
 *+  ПЗУ
 *+- Видеовыход (не хватает fl - мерцания)
 *-  Процессор
 *-  Клавиатура
 *-  Несколько портов (пока только рамка)
 *
 *
 */

#include <vector>
#include <cstdint>
#include <random>
#include <iostream>
#include <fstream>

#include <SDL2/SDL.h>

#include "Window.h"

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {
			Window win;

			win.main();
		} catch (const std::exception & e) {
			std::cerr << e.what() << std::endl;
			return 1;
		} catch (...) {
			std::cerr << "An unknown exception has occured!" << std::endl;
			return 2;
		}
	return 0;
}



