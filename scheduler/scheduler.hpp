#pragma once
#include <iostream>
#include "../date/date.hpp"

class Scheduler
{
    private:
    Date m_begin_date;   
    Date m_end_date;

    public:
    Scheduler();
    void SetBeginDate(Date);
    void SetEndDate(Date);
    //~Scheduler();
    bool IsValid();

};