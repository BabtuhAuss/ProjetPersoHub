#include "ZFraction.h"

using namespace std;

ZFraction::ZFraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
{
}
ZFraction::ZFraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1)
{
}
ZFraction::ZFraction() : m_numerateur(0), m_denominateur(1)
{
}