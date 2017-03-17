#include "namevaluepair.h"


string NameValuePair::getName()
{
  return m_Name;
}
string NameValuePair::getValue()
{
  return m_Value;
}
void NameValuePair::setName(string data)
{
  m_Name = data;
}
void NameValuePair::setValue(string data)
{
  m_Value = data;
}
