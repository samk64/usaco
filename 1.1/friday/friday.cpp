/*
ID: samk641
PROG: friday
LANG: C++
*/

/**
 * Prompt
 * 
 * Is Friday the 13th really an unusual event?
 * 
 * That is, does the 13th of the month land on a Friday less often than on any other day of the week? 
 * To answer this question, write a program that will compute the frequency that the 13th of each month 
 * lands on Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday over a given period of N years. 
 * The time period to test will be from January 1, 1900 to December 31, 1900+N-1 for a given number of years, N. 
 * N is positive and will not exceed 400.
 * 
 * Note that the start year is NINETEEN HUNDRED, not 1990.
 * 
 * There are few facts you need to know before you can solve this problem:
 * 
 * - January 1, 1900 was on a Monday.
 * - Thirty days has September, April, June, and November, all the rest have 31 except for February which has 28 except in leap years when it has 29.
 * - Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
 * - The rule above does not hold for century years. Century years divisible by 400 are leap years, all other are not. 
 *   Thus, the century years 1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year.
 *
 * Do not use any built-in date functions in your computer language.
 * 
 * Don't just precompute the answers, either, please.
 *
 */

/** 
 * :return: Seven space separated integers on one line. 
 * These integers represent the number of times the 13th 
 * falls on Saturday, Sunday, Monday, Tuesday, ..., Friday.
 *
 */
#include <assert.h>
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

bool is_leap_year(int nYear);
bool is_normal_leap_year(int nYear);
bool is_century_leap_year(int nYear);
bool is_century_year(int nYear);
int get_num_days_in_month(int nYear, int nMonth);
int get_first_day_of_month(int nYear, int nMonth);
int get_first_day_of_year(int nYear);
void get_frequency_of_13ths_cumulative(int nYear, std::map<int, int>& mapDayToFrequency);
std::string get_frequency_of_13ths(int nYear);
int get_day_of_13th_of_month(int nYear, int nMonth);
int convert_day_to_weekday(int day);

bool is_leap_year(int nYear)
{
    if (is_century_year(nYear))
    {
        return is_century_leap_year(nYear);
    }
    else
    {
        return is_normal_leap_year(nYear);
    }
}

bool is_normal_leap_year(int nYear)
{
    return ((nYear % 4) == 0);
}

bool is_century_leap_year(int nYear)
{
    return is_century_year(nYear) && ((nYear % 400) == 0);
}

bool is_century_year(int nYear)
{
    return ((nYear % 100) == 0);
}

int convert_day_to_weekday(int nDay)
{
    int nWeekDay = nDay % 7;
    
    if(nWeekDay == 0) 
    {
        nWeekDay = 7;
    }

    return nWeekDay;
}

// :return: the day of the first of the year, -1 if error
int get_first_day_of_year(int nYear)
{
    if (nYear < 1900)
    {
        return -1;
    }           
    else
    {
        int nDaysSince1900 = 1;
        int nYears = 1900;
    
        // find number of days since 1900 until target year
        while(nYears < nYear)
        {
            nDaysSince1900 += 365 + (int)is_leap_year(nYears);
            nYears++; 
        } 

        return convert_day_to_weekday(nDaysSince1900);
    } 
}

// :param nMonth: the month of the year, 1-12
// :return: the first day of the month, -1 if error
int get_first_day_of_month(int nYear, int nMonth)
{
    if (nMonth < 1 || nMonth > 12)
    {
        return -1;
    }

    // get the number of days before this month + first day of year
    int nDaysTilMonth = get_first_day_of_year(nYear);
    int nMonths = nMonth-1;
    while (nMonths)
    {
        nDaysTilMonth += get_num_days_in_month(nYear, nMonths);
        nMonths--;
    }
    
    return convert_day_to_weekday(nDaysTilMonth);
}

int get_num_days_in_month(int nYear, int nMonth)
{
    if(nMonth < 1 || nMonth > 12)
    {
        return -1;
    }

    switch(nMonth)
    {
        // Feb has 28, and 29 for leap years
        case 2: 
            return is_leap_year(nYear) ? 29 : 28;
        // April, June, Sept, Nov have 30 days
        case 4:
        case 6:
        case 9:
        case 11: 
            return 30;
        // All other months have 31 days 
        default:
            return 31;
    }
}

int get_day_of_13th_of_month(int nYear, int nMonth)
{
    int nFirstDayOfMonth = get_first_day_of_month(nYear, nMonth);

    int nDayOf13th = convert_day_to_weekday(nFirstDayOfMonth + 12); 
    
    return nDayOf13th;
}

// :return: the frequency that the 13th falls on a Sun, Tues, Wed throughout the year
void get_frequency_of_13ths_cumulative(int nYear, std::map<int, int>& mapDayToFrequency)
{
    for(int i = 1; i <= 7; i++)
    {
        mapDayToFrequency[i] = 0;
    } 
       
    // get 13th of month for all months 
    for(int year = 1900; year <= nYear; year++) 
    {
        for(int month = 1; month <= 12; month++)
        {
            int nDayOf13th = get_day_of_13th_of_month(year, month);
            if (year == 1900 && month == 1)
            {
                assert(nDayOf13th = 6);
            }
            //std::cout << nDayOf13th << std::endl;   

            mapDayToFrequency[nDayOf13th] += 1; 
        }
    }

    //std::map<int, int>::iterator it = mapDayToFrequency.begin();
    //while( it != mapDayToFrequency.end() )
    //{
     //   std::cout << it->first << ", " << it->second << std::endl; 
      //  ++it;
    //}

}

// return string of frequency of 13ths in a year occurring on Sun, Mon, Tues, etc.
std::string get_frequency_of_13ths(int nYear)
{
    std::string strFrequency;
    std::map<int, int> mapDayToFrequency;
    get_frequency_of_13ths_cumulative(nYear, mapDayToFrequency);
    
    for (int i = 1; i <= 7; i++)
    {
        int nDaysInWeek = 7;
        int nDayOfWeek = convert_day_to_weekday(i+5); // start on saturday 

        //std::cout << "DAY " << nDayOfWeek << std::endl;

        std::stringstream os;
        os << mapDayToFrequency[nDayOfWeek];
       
        strFrequency.append(os.str());
        if(i != 7) 
        {
            strFrequency.append(" "); 
        }
    }

    return strFrequency;
}

#ifdef GTEST
#else
int main(int argc, char* argv[])
{
    std::ifstream fin("friday.in"); 
    std::ofstream fout("friday.out");
    std::string strN;
    fin >> strN;
     
    int N = atoi(strN.c_str());
    int nYear = 1900 + N - 1; 
    
    fout << get_frequency_of_13ths(nYear) << std::endl;

    return 0;
}
#endif
