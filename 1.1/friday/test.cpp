#include <gtest/gtest.h>
#include "friday.cpp"

/*
TEST(FRIDAY, test_is_century_year) 
{
    ASSERT_TRUE(is_century_year(1900));
    ASSERT_FALSE(is_century_year(1901));
    ASSERT_FALSE(is_century_year(1990));
}

TEST(FRIDAY, test_is_century_leap_year) 
{
    ASSERT_FALSE(is_century_leap_year(1990));
}

TEST(FRIDAY, test_is_normal_leap_year) 
{
    ASSERT_FALSE(is_normal_leap_year(1990));
}
*/

TEST(FRIDAY, test_is_leap_year) 
{
    // leap year
    ASSERT_TRUE(is_leap_year(1992));
    ASSERT_TRUE(is_leap_year(1904));

    // non-leap year
    ASSERT_FALSE(is_leap_year(1990));
    
    // century leap year
    ASSERT_TRUE(is_leap_year(2000));
    
    // century non-leap year
    ASSERT_FALSE(is_leap_year(2100));
    ASSERT_FALSE(is_leap_year(1900));
    ASSERT_FALSE(is_leap_year(1800));
    ASSERT_FALSE(is_leap_year(1700));    
}

TEST(FRIDAY, test_first_day_of_year)
{
    ASSERT_TRUE(get_first_day_of_year(1900) == 1);
    ASSERT_TRUE(get_first_day_of_year(1901) == 2);
    ASSERT_TRUE(get_first_day_of_year(1902) == 3);
    ASSERT_TRUE(get_first_day_of_year(1903) == 4);
    ASSERT_TRUE(get_first_day_of_year(1904) == 5);
    ASSERT_TRUE(get_first_day_of_year(1905) == 7);
    ASSERT_TRUE(get_first_day_of_year(1906) == 1);

}

TEST(FRIDAY, test_get_num_days_in_month)
{
    ASSERT_TRUE(get_num_days_in_month(1900, 1) == 31);
    ASSERT_TRUE(get_num_days_in_month(1900, 2) == 28);
    ASSERT_TRUE(get_num_days_in_month(1900, 3) == 31);
    ASSERT_TRUE(get_num_days_in_month(1900, 4) == 30);
    ASSERT_TRUE(get_num_days_in_month(1900, 5) == 31);
    ASSERT_TRUE(get_num_days_in_month(1900, 6) == 30);
    ASSERT_TRUE(get_num_days_in_month(1900, 7) == 31);
    ASSERT_TRUE(get_num_days_in_month(1900, 8) == 31);
    ASSERT_TRUE(get_num_days_in_month(1900, 9) == 30);
    ASSERT_TRUE(get_num_days_in_month(1900, 10) == 31);
    ASSERT_TRUE(get_num_days_in_month(1900, 11) == 30);
    ASSERT_TRUE(get_num_days_in_month(1900, 12) == 31);
}

TEST(FRIDAY, test_first_day_of_month)
{
    ASSERT_TRUE(get_first_day_of_month(1900, 1) == 1);
    ASSERT_TRUE(get_first_day_of_month(1900, 2) == 4);
    ASSERT_TRUE(get_first_day_of_month(1900, 3) == 4);

    ASSERT_TRUE(get_first_day_of_month(1902, 1) == 3);
    ASSERT_TRUE(get_first_day_of_month(1902, 2) == 6);
    ASSERT_TRUE(get_first_day_of_month(1902, 3) == 6);
    ASSERT_TRUE(get_first_day_of_month(1902, 4) == 2);
    ASSERT_TRUE(get_first_day_of_month(1902, 5) == 4);
    ASSERT_TRUE(get_first_day_of_month(1902, 6) == 7);
    ASSERT_TRUE(get_first_day_of_month(1902, 7) == 2);
    ASSERT_TRUE(get_first_day_of_month(1902, 8) == 5);
    ASSERT_TRUE(get_first_day_of_month(1902, 9) == 1);
    ASSERT_TRUE(get_first_day_of_month(1902, 10) == 3);
    ASSERT_TRUE(get_first_day_of_month(1902, 11) == 6);
    ASSERT_TRUE(get_first_day_of_month(1902, 12) == 1);
}

TEST(FRIDAY, test_day_of_13th_of_month)
{
    ASSERT_TRUE(get_day_of_13th_of_month(1901, 2) == 3);
    ASSERT_TRUE(get_day_of_13th_of_month(1901, 3) == 3);
    
    ASSERT_TRUE(get_day_of_13th_of_month(1900, 1) == 6);
    ASSERT_TRUE(get_day_of_13th_of_month(1900, 2) == 2);
    ASSERT_TRUE(get_day_of_13th_of_month(1900, 3) == 2);
    ASSERT_TRUE(get_day_of_13th_of_month(1900, 4) == 5);
}

TEST(FRIDAY, test_get_frequency_of_13ths)
{
    int nInputs = 8;
    int inputs[] = {1, 2, 5, 13, 45, 100, 256, 400};
    std::string outputs[] = {
      "2 1 1 3 1 2 2",
      "4 3 2 4 4 3 4",
      "9 9 7 9 9 8 9",
      "23 21 22 22 24 21 23",
      "78 76 78 76 78 77 77",
      "173 170 172 171 172 170 172",
      "440 439 438 438 439 439 439",
      "684 687 685 685 687 684 688"
    };

    for(int i = 0; i < nInputs; i++)
    {
        int N = inputs[i];
        int nYear = 1900 + N - 1;
        if (i == 0) ASSERT_TRUE(get_frequency_of_13ths(nYear) == outputs[i]);
    }
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
