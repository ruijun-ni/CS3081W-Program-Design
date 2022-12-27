#include "gtest/gtest.h"
#include "date.h"

class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};

// overload == to compare Date objects
bool operator==(const Date& lhs, const Date& rhs)
{
    return lhs.GetDate() == rhs.GetDate();
}

TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
  
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/

/**
  * Mutant: Dates from GetDate are missing a character
  */
TEST_F(DateTest, GetDaysTests) {
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetDate(), "2018-12-11") << "Last day of class not setup properly";
}

/** 
  * Mutant: Today's date month off by one
  */
TEST_F(DateTest, GetTodaysDateTests) {
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  Date today = Date(); 
  Date expected_today(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
  EXPECT_EQ(today, expected_today) << "Today's date month is wrong";
}

/**
  * Mutant: Dates constructed with epoch are about 70 years in the future
  */
TEST_F(DateTest, DatesWithEpochTests) {
  Date d(86400); // one day have elapsed since 00:00:00 1 January 1970
  Date expected_date(1970, 1, 2);
  EXPECT_EQ(d, expected_date) << "Dates constructed with epoch not correct";
}

/**
  * Mutant: Dates from GetUsDate are not in the right format (same as GetDate?)
  * GetUsDate should not be the same as GetDate
  */
TEST_F(DateTest, GetUsDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  EXPECT_NE(y2k.GetDate(), y2k.GetUsDate()) << "GetUsDate not setup properly";
  EXPECT_NE(ind_day.GetDate(), ind_day.GetUsDate()) << "GetUsDate not setup properly";
  EXPECT_NE(best_holiday.GetDate(), best_holiday.GetUsDate()) << "GetUsDate not setup properly";
}

/**
  * Mutant: 1/1/2016 to 3/1/2016 is 60 days, but this version returns 59
  */
TEST_F(DateTest, DaysBetweenTests2) {
  Date d1(2016, 1, 1);
  Date d2(2016, 3, 1);
  EXPECT_EQ(d1.GetUsDate(), "01-01-2016") << "d1 of class not setup properly";
  EXPECT_EQ(d2.GetUsDate(), "03-01-2016") << "d2 of class not setup properly";
  EXPECT_EQ(d1.DaysBetween(d2), 60) << "Days between is not calculated properly";
}

/**
  * Mutant: operator-: Probably a copy paste error
  */
TEST_F(DateTest, OperatorMinusTests) {
  Date d1(2016, 1, 1);
  Date d2(2016, 2, 28);
  Date d3(2016, 3, 1);
  EXPECT_EQ(d3.operator-(60), d1) << "operator- not setup properly";
  EXPECT_EQ(d3.operator-(2), d2) << "operator- not setup properly";
}

/**
  * Mutant: Some errors related with calculating
  */
TEST_F(DateTest, CalculateTests) {
  Date d1(2015, 6, 15);
  Date d2 = d1.operator+(5);
  Date d3(2016, 2, 27);
  Date d4 = d3.operator+(2);

  testing::internal::CaptureStdout();
  d2.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  d4.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, "2015-06-20") << "calculate not setup properly";
  EXPECT_EQ(output2, "2016-02-29") << "calculate not setup properly";
}

/**
  * Mutant: Some dates don't have leading zeroes
  */
TEST_F(DateTest, LeadingZeroesTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); 
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output4 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); 
  ind_day.PrintUsDate(false);
  std::string output5 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output6 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1.length(), 10);
  EXPECT_EQ(output2.length(), 10);
  EXPECT_EQ(output3.length(), 10);
  EXPECT_EQ(output4.length(), 10);
  EXPECT_EQ(output5.length(), 10);
  EXPECT_EQ(output6.length(), 10);
}