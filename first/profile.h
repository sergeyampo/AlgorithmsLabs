#ifndef GUARD_LOG_DURATION
#define GUARD_LOG_DURATION

#include <chrono>
#include <iostream>
#include <string>

//Макрос генерации уникального имени от строки
#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno)  UNIQ_ID_IMPL(lineno)

//Макрос для создания объекта LogDuration с уникальным именем, чтобы каждый раз не придумывать
//имя экземпляра самостоятельно
#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};

class LogDuration {
public:
	//Конструктор отсчитывает начало времени
	explicit LogDuration(const std::string& msg = "") : start(std::chrono::steady_clock::now()), message(msg + ": ") { }
	//Деструктор отмеряет конец временного промежутка и выводит результат
	~LogDuration() {
		auto finish = std::chrono::steady_clock::now();
		std::cerr << message << std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() << " ms" << std::endl;
	}
private:
	std::chrono::steady_clock::time_point start;
	std::string message;
};

#endif