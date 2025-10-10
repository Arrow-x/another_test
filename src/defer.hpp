#pragma once

template <typename F>
struct Defer {
	F f;
	Defer(F f_) : f(f_) {}
	~Defer() { f(); }
};

#define CONCAT_DETAIL(x, y) x##y
#define CONCAT(x, y) CONCAT_DETAIL(x, y)

#define DEFER(block) auto CONCAT(_defer_, __COUNTER__) = Defer([&]() block)
