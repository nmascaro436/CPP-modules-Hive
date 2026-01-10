#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {}

Weapon::~Weapon() {}

// We return a reference to _type, so the first const protects it from being modified
// Second const means its read only function (function is allowed to be called on const objects),
// if a function doesn't modify the object it has to be marked const

const std::string& Weapon::getType() const
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
