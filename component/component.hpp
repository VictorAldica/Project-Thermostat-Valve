#pragma once
#include <iostream>

using std::string;

class Component {
public:
  Component();
  Component(string, string);
  //~Component();
  virtual void whoami();

protected:
  string m_name;
  string m_desc;
};