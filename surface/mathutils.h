#pragma once

#include <glm\glm.hpp>

namespace planet_engine
{
	template<typename T>
	glm::tvec3<T> to_sphere(const glm::tvec3<T>& t, T radius)
	{
		return glm::normalize(t) * radius;
	}

	template<typename T>
	glm::tvec3<T> lerp(const glm::tvec3<T>& a, const glm::tvec3<T>& b, T f)
	{
		return (a * (T(1.0) - f)) + b * f;
	}
	template<typename T>
	T length2(const glm::tvec3<T>& v)
	{
		return glm::dot(v, v);
	}
}
