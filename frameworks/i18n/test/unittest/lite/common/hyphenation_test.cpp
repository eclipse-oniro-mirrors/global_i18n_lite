/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "i18n_test.h"
#include <gtest/gtest.h>
#include "date_time_format.h"
#include "locale_info.h"
#include "measure_format.h"
#include "number_format.h"
#include "plural_format.h"
#include "types.h"
#include "week_info.h"

using namespace std;
using namespace testing::ext;

namespace OHOS {
namespace I18N {
class I18NTest : public testing::Test {
public:
    void SetUp();
    void TearDown();
};

void I18NTest::SetUp()
{
}

void I18NTest::TearDown()
{
}

/**
 * @tc.name: HyphenationTest001
 * @tc.desc: Test LocaleInfo constructor1
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest001, TestSize.Level1)
{
    LocaleInfo *locale = new LocaleInfo("zh", "Hans", "CN");
    EXPECT_TRUE(locale != nullptr);
    delete locale;
}

/**
 * @tc.name: HyphenationTest002
 * @tc.desc: Test LocaleInfo constructor2
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest002, TestSize.Level1)
{
    LocaleInfo *locale = new LocaleInfo("zh", "CN");
    EXPECT_TRUE(locale != nullptr);
    delete locale;
}

/**
 * @tc.name: HyphenationTest003
 * @tc.desc: Test LocaleInfo default Constructor
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest003, TestSize.Level1)
{
    LocaleInfo *locale = new LocaleInfo();
    EXPECT_TRUE(locale != nullptr);
    delete locale;
}

/**
 * @tc.name: HyphenationTest004
 * @tc.desc: Test LocaleInfo copy constructor
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest004, TestSize.Level1)
{
    LocaleInfo locale("zh", "CN");
    LocaleInfo locale2(locale);
    const char *language = locale2.GetLanguage();
    const char *region = locale2.GetRegion();
    EXPECT_TRUE(language != nullptr);
    EXPECT_TRUE(region != nullptr);
    if (language != nullptr) {
        EXPECT_TRUE(strcmp(language, "zh") == 0);
    }
    if (region != nullptr) {
        EXPECT_TRUE(strcmp(region, "CN") == 0);
    }
}

/**
 * @tc.name: HyphenationTest005
 * @tc.desc: Test LocaleInfo equals function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest005, TestSize.Level1)
{
    LocaleInfo locale("zh", "CN");
    LocaleInfo locale2("zh", "CN");
    EXPECT_TRUE(locale == locale2);
}

/**
 * @tc.name: HyphenationTest006
 * @tc.desc: Test LocaleInfo GetLanguage function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest006, TestSize.Level1)
{
    LocaleInfo locale("ar", "AE");
    const char *language = locale.GetLanguage();
    EXPECT_TRUE(language != nullptr);
    if (language != nullptr) {
        EXPECT_TRUE(strcmp(language, "ar") == 0);
    }
}

/**
 * @tc.name: HyphenationTest007
 * @tc.desc: Test LocaleInfo GetRegion function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest007, TestSize.Level1)
{
    LocaleInfo locale("ar", "AE");
    const char *region = locale.GetRegion();
    EXPECT_TRUE(region != nullptr);
    if (region != nullptr) {
        EXPECT_TRUE(strcmp(region, "AE") == 0);
    }
}

/**
 * @tc.name: HyphenationTest008
 * @tc.desc: Test LocaleInfo GetScript function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest008, TestSize.Level1)
{
    LocaleInfo locale("zh", "Hans", "CN");
    const char *script = locale.GetScript();
    EXPECT_TRUE(script != nullptr);
    if (script != nullptr) {
        EXPECT_TRUE(strcmp(script, "Hans") == 0);
    }
}

/**
 * @tc.name: HyphenationTest009
 * @tc.desc: Test LocaleInfo GetId function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest009, TestSize.Level1)
{
    LocaleInfo locale("zh", "Hans", "CN");
    const char *id = locale.GetId();
    EXPECT_TRUE(id != nullptr);
    if (id != nullptr) {
        EXPECT_TRUE(strcmp(id, "zh-Hans-CN") == 0);
    }
}

/**
 * @tc.name: HyphenationTest010
 * @tc.desc: Test LocaleInfo IsDefaultLocale function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest010, TestSize.Level1)
{
    LocaleInfo locale("zh", "Hans", "CN");
    EXPECT_TRUE(!locale.IsDefaultLocale());
    LocaleInfo locale2("en", "US");
    EXPECT_TRUE(locale2.IsDefaultLocale());
}

/**
 * @tc.name: HyphenationTest011
 * @tc.desc: Test DateTimeFormat Constructor
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest011, TestSize.Level1)
{
    LocaleInfo locale("zh", "Hans", "CN");
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::HOUR_MINUTE;
    DateTimeFormat *formatter = new DateTimeFormat(pattern, locale);
    EXPECT_TRUE(formatter != nullptr);
    delete formatter;
}

/**
 * @tc.name: HyphenationTest012
 * @tc.desc: Test DateTimeFormat Init function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest012, TestSize.Level1)
{
    LocaleInfo locale("zh", "Hans", "CN");
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::HOUR_MINUTE;
    DateTimeFormat formatter(pattern, locale);
    EXPECT_TRUE(formatter.Init());
}

/**
 * @tc.name: HyphenationTest013
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest013, TestSize.Level1)
{
    LocaleInfo locale("zh", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::FULL;
    DateTimeFormat formatter(pattern, locale);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "1970年1月7日星期三";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest014
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest014, TestSize.Level1)
{
    LocaleInfo locale("ar", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::FULL;
    DateTimeFormat formatter(pattern, locale);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "الأربعاء، ٧ يناير، ١٩٧٠";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest015
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest015, TestSize.Level1)
{
    LocaleInfo locale("en", "", "US");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::FULL;
    DateTimeFormat formatter(pattern, locale);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "Wednesday, January 7, 1970";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest016
 * @tc.desc: Test DateTimeFormat ApplyPattern function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest016, TestSize.Level1)
{
    LocaleInfo locale("zh", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::SHORT;
    DateTimeFormat formatter(pattern, locale);
    formatter.ApplyPattern(AvailableDateTimeFormatPattern::FULL);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "1970年1月7日星期三";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest017
 * @tc.desc: Test DateTimeFormat ApplyPattern function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest017, TestSize.Level1)
{
    LocaleInfo locale("ar", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::SHORT;
    DateTimeFormat formatter(pattern, locale);
    formatter.ApplyPattern(AvailableDateTimeFormatPattern::FULL);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "الأربعاء، ٧ يناير، ١٩٧٠";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest018
 * @tc.desc: Test DateTimeFormat ApplyPattern function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest018, TestSize.Level1)
{
    LocaleInfo locale("en", "", "US");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::SHORT;
    DateTimeFormat formatter(pattern, locale);
    formatter.ApplyPattern(AvailableDateTimeFormatPattern::FULL);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "Wednesday, January 7, 1970";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest019
 * @tc.desc: Test DateTimeFormat GetWeekName
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest019, TestSize.Level1)
{
    LocaleInfo locale("zh", "", "CN");
    std::string weekDays[] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::SHORT;
    DateTimeFormat formatter(pattern, locale);
    for (int i = 0; i < 7; ++i) {
        std::string out = formatter.GetWeekName(i, DateTimeDataType::FORMAT_WIDE);
        EXPECT_TRUE(weekDays[i] == out);
    }
}

/**
 * @tc.name: HyphenationTest020
 * @tc.desc: Test DateTimeFormat GetMonthName
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest020, TestSize.Level1)
{
    LocaleInfo locale("en", "", "US");
    std::string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
        "October", "November", "December" };
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::SHORT;
    DateTimeFormat formatter(pattern, locale);
    for (int i = 0; i < 12; ++i) {
        std::string out = formatter.GetMonthName(i, DateTimeDataType::FORMAT_WIDE);
        EXPECT_TRUE(months[i] == out);
    }
}

/**
 * @tc.name: HyphenationTest021
 * @tc.desc: Test numberFormat format integer
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest021, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    int intNum1 = 1234567;
    int intNum2 = 123456789;
    int intNum3 = 1234;
    std::string out = formatter.Format(intNum1, status);
    std::string out2 = formatter.Format(intNum2, status);
    std::string out3 = formatter.Format(intNum3, status);
    EXPECT_TRUE(out == "1,234,567");
    EXPECT_TRUE(out2 == "123,456,789");
    EXPECT_TRUE(out3 == "1,234");
}

/**
 * @tc.name: HyphenationTest022
 * @tc.desc: Test numberFormat format no group integer
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest022, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    int intNum1 = 1234567;
    int intNum2 = 123456789;
    int intNum3 = 1234;
    std::string out = formatter.FormatNoGroup(intNum1, status);
    std::string out2 = formatter.FormatNoGroup(intNum2, status);
    std::string out3 = formatter.FormatNoGroup(intNum3, status);
    EXPECT_TRUE(out == "1234567");
    EXPECT_TRUE(out2 == "123456789");
    EXPECT_TRUE(out3 == "1234");
}

/**
 * @tc.name: HyphenationTest023
 * @tc.desc: Test numberFormat format double
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest023, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    double doubleNum1 = 1234567.567;
    double doubleNum2 = 1.23456789567E8;
    double doubleNum3 = 1234.0;
    std::string out = formatter.Format(doubleNum1, NumberFormatType::DECIMAL, status);
    std::string out2 = formatter.Format(doubleNum2, NumberFormatType::DECIMAL, status);
    std::string out3 = formatter.Format(doubleNum3, NumberFormatType::DECIMAL, status);
    EXPECT_TRUE(out == "1,234,567.567");
    EXPECT_TRUE(out2 == "123,456,789.567");
    EXPECT_TRUE(out3 == "1,234");
}

/**
 * @tc.name: HyphenationTest024
 * @tc.desc: Test numberFormat format no group double
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest024, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    double doubleNum1 = 1234567.567;
    double doubleNum2 = 1.23456789567E8;
    double doubleNum3 = 1234.0;
    std::string out = formatter.FormatNoGroup(doubleNum1, NumberFormatType::DECIMAL, status);
    std::string out2 = formatter.FormatNoGroup(doubleNum2, NumberFormatType::DECIMAL, status);
    std::string out3 = formatter.FormatNoGroup(doubleNum3, NumberFormatType::DECIMAL, status);
    EXPECT_TRUE(out == "1234567.567");
    EXPECT_TRUE(out2 == "123456789.567");
    EXPECT_TRUE(out3 == "1234");
}

/**
 * @tc.name: HyphenationTest025
 * @tc.desc: Test numberFormat format SetMaxDecimalLength;
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest025, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    double doubleNum1 = 1234567.567;
    double doubleNum2 = 1.23456789567E8;
    double doubleNum3 = 1234.0;
    formatter.SetMaxDecimalLength(1);
    std::string out = formatter.FormatNoGroup(doubleNum1, NumberFormatType::DECIMAL, status);
    std::string out2 = formatter.FormatNoGroup(doubleNum2, NumberFormatType::DECIMAL, status);
    std::string out3 = formatter.FormatNoGroup(doubleNum3, NumberFormatType::DECIMAL, status);
    EXPECT_TRUE(out == "1234567.6");
    EXPECT_TRUE(out2 == "123456789.6");
    EXPECT_TRUE(out3 == "1234");
}

/**
 * @tc.name: HyphenationTest026
 * @tc.desc: Test numberFormat format SetMinDecimalLength;
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest026, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    double doubleNum1 = 1234567.56;
    double doubleNum2 = 1.2;
    double doubleNum3 = 1234.0;
    formatter.SetMinDecimalLength(3);
    std::string out = formatter.FormatNoGroup(doubleNum1, NumberFormatType::DECIMAL, status);
    std::string out2 = formatter.FormatNoGroup(doubleNum2, NumberFormatType::DECIMAL, status);
    std::string out3 = formatter.FormatNoGroup(doubleNum3, NumberFormatType::DECIMAL, status);
    EXPECT_TRUE(out == "1234567.560");
    EXPECT_TRUE(out2 == "1.200");
    EXPECT_TRUE(out3 == "1234.000");
}

/**
 * @tc.name: HyphenationTest027
 * @tc.desc: Test numberFormat format percent;
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest027, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    double percentNum1 = 0.1234;
    double percentNum2 = 0.123456;
    std::string out = formatter.Format(percentNum1, NumberFormatType::PERCENT, status);
    std::string out2 = formatter.Format(percentNum2, NumberFormatType::PERCENT, status);
    EXPECT_TRUE(out == "12%");
    EXPECT_TRUE(out2 == "12%");
}
/**
 * @tc.name: HyphenationTest028
 * @tc.desc: Test NumberFormat Format function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest0028, TestSize.Level1)
{
    LocaleInfo locale("zh", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    std::string out = formatter.Format(1234567, status);
    std::string expect = "1,234,567";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest029
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest029, TestSize.Level1)
{
    LocaleInfo locale("am", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(0, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(17, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(10000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest030
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest030, TestSize.Level1)
{
    LocaleInfo locale("ar", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(3, status);
    int expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(10, status);
    expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(11, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(26, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::TWO;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::ZERO;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest031
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest031, TestSize.Level1)
{
    LocaleInfo locale("as", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(0, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest032
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest032, TestSize.Level1)
{
    LocaleInfo locale("az", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(16, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest033
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest033, TestSize.Level1)
{
    LocaleInfo locale("be", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(2, status);
    int expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(4, status);
    expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(5, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(19, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(21, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest034
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest034, TestSize.Level1)
{
    LocaleInfo locale("bg", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(16, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(10000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest035
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest035, TestSize.Level1)
{
    LocaleInfo locale("bn", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(0, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(17, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(10000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest036
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest036, TestSize.Level1)
{
    LocaleInfo locale("bo", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(0, status);
    int expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(15, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(10000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest037
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest037, TestSize.Level1)
{
    LocaleInfo locale("bs", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(2, status);
    int expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(4, status);
    expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(22, status);
    expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(21, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest038
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest038, TestSize.Level1)
{
    LocaleInfo locale("ca", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest039
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest039, TestSize.Level1)
{
    LocaleInfo locale("cs", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(2, status);
    int expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(4, status);
    expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest040
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest040, TestSize.Level1)
{
    LocaleInfo locale("da", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest041
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest041, TestSize.Level1)
{
    LocaleInfo locale("de", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1000000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest042
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest042, TestSize.Level1)
{
    LocaleInfo locale("el", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest043
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest043, TestSize.Level1)
{
    LocaleInfo locale("en", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(16, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest044
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest044, TestSize.Level1)
{
    LocaleInfo locale("es", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest045
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest045, TestSize.Level1)
{
    LocaleInfo locale("et", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(1, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(100000, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest046
 * @tc.desc: Test NumberFormat Format percent
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest046, TestSize.Level1)
{
    LocaleInfo locale("de", "DE");
    int status = I18nStatus::ISUCCESS;
    NumberFormat format(locale, status);
    std::string out = format.Format(0.12, NumberFormatType::PERCENT, status);
    std::string expect = "12 %";
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest047
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest047, TestSize.Level1)
{
    LocaleInfo locale("lv", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    double number = 2.1;
    int out = formatter.GetPluralRuleIndex(number, status);
    int expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    number = 10.0;
    out = formatter.GetPluralRuleIndex(number, status);
    expect = PluralRuleType::ZERO;
    EXPECT_TRUE(expect == out);
    number = 100.2;
    out = formatter.GetPluralRuleIndex(number, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest048
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest048, TestSize.Level1)
{
    LocaleInfo locale("hr", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    double number = 2.3;
    int out = formatter.GetPluralRuleIndex(number, status);
    int expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    number = 10.1;
    out = formatter.GetPluralRuleIndex(number, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    number = 1.5;
    out = formatter.GetPluralRuleIndex(number, status);
    expect = PluralRuleType::OTHER;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest049
 * @tc.desc: Test LocaleInfo ForLanguageTag
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest049, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale = LocaleInfo::ForLanguageTag("zh-Hant-CN-u-nu-arab", status);
    EXPECT_TRUE(status == I18nStatus::ISUCCESS);
}

/**
 * @tc.name: HyphenationTest050
 * @tc.desc: Test LocaleInfo GetExtension
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest050, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale = LocaleInfo::ForLanguageTag("zh-Hant-CN-u-nu-arab", status);
    EXPECT_TRUE(status == I18nStatus::ISUCCESS);
    const char *numberDigits = locale.GetExtension("nu");
    EXPECT_TRUE(numberDigits != nullptr);
    if (numberDigits != nullptr) {
        EXPECT_TRUE(strcmp("arab", numberDigits) == 0);
    }
}

/**
 * @tc.name: HyphenationTest051
 * @tc.desc: Test WeekInfo constructor;
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest051, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("zh", "CN");
    WeekInfo weekInfo(locale, status);
    EXPECT_TRUE(status == I18nStatus::ISUCCESS);
}

/**
 * @tc.name: HyphenationTest052
 * @tc.desc: Test WeekInfo GetFirstDayOfWeek()
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest052, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("zh", "CN");
    WeekInfo weekInfo(locale, status);
    uint8_t ret = weekInfo.GetFirstDayOfWeek();
    EXPECT_TRUE(ret == 1);
}

/**
 * @tc.name: HyphenationTest053
 * @tc.desc: Test WeekInfo GetMinimalDaysInFirstWeek()
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest053, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("zh", "CN");
    WeekInfo weekInfo(locale, status);
    uint8_t ret = weekInfo.GetMinimalDaysInFirstWeek();
    EXPECT_TRUE(ret == 1);
}

/**
 * @tc.name: HyphenationTest054
 * @tc.desc: Test WeekInfo GetFirstDayOfWeekend()
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest054, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("zh", "CN");
    WeekInfo weekInfo(locale, status);
    uint8_t ret = weekInfo.GetFirstDayOfWeekend();
    EXPECT_TRUE(ret == 7);
}

/**
 * @tc.name: HyphenationTest055
 * @tc.desc: Test WeekInfo GetLastDayOfWeekend()
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest055, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("zh", "CN");
    WeekInfo weekInfo(locale, status);
    uint8_t ret = weekInfo.GetLastDayOfWeekend();
    EXPECT_TRUE(ret == 1);
}

/**
 * @tc.name: HyphenationTest056
 * @tc.desc: Test DateTimeFormat be
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest056, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("be", "", "");
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::ABBR_MONTH_WEEKDAY_DAY;
    DateTimeFormat formatter(pattern, locale);
    string out;
    formatter.Format(0, "", out, status);
    EXPECT_TRUE(out == "чц, 1 сту");
}

/**
 * @tc.name: HyphenationTest057
 * @tc.desc: Test numberFormat be
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest057, TestSize.Level1)
{
    LocaleInfo locale("be", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    int intNum1 = 1234567;
    int intNum2 = 123456789;
    int intNum3 = 1234;
    std::string out = formatter.Format(intNum1, status);
    signed char array1[] = { 49, -62, -96, 50, 51, 52, -62, -96, 53, 54, 55, 0 };
    string expect1(reinterpret_cast<char *>(array1));
    std::string out2 = formatter.Format(intNum2, status);
    signed char array2[] = { 49, 50, 51, -62, -96, 52, 53, 54, -62, -96, 55, 56, 57, 0 };
    string expect2(reinterpret_cast<char *>(array2));
    std::string out3 = formatter.Format(intNum3, status);
    signed char array3[] = { 49, -62, -96, 50, 51, 52, 0 };
    string expect3(reinterpret_cast<char *>(array3));
    EXPECT_TRUE(out == expect1);
    EXPECT_TRUE(out2 == expect2);
    EXPECT_TRUE(out3 == expect3);
}

/**
 * @tc.name: HyphenationTest058
 * @tc.desc: Test PluralFormat GetPluralRuleIndex function
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest058, TestSize.Level1)
{
    LocaleInfo locale("be", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    int out = formatter.GetPluralRuleIndex(3, status);
    int expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(10, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(11, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(26, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(1, status);
    expect = PluralRuleType::ONE;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(2, status);
    expect = PluralRuleType::FEW;
    EXPECT_TRUE(expect == out);
    out = formatter.GetPluralRuleIndex(0, status);
    expect = PluralRuleType::MANY;
    EXPECT_TRUE(expect == out);
}

/**
 * @tc.name: HyphenationTest059
 * @tc.desc: Test MeasureFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest059, TestSize.Level1)
{
    LocaleInfo locale("en", "US");
    I18nStatus status = I18nStatus::ISUCCESS;
    MeasureFormat formatter(locale, status);
    std::string unit = "min";

    std::string expect = "12 min";
    std::string out = formatter.Format(12, unit, status);
    EXPECT_EQ(out, "12 m");
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_EQ(out, "12 m");
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_EQ(out, expect);

    expect = "12 minutes";
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_EQ(expect, out);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_EQ(expect, out);

    expect = "1 min";
    out = formatter.Format(1, unit, status);
    EXPECT_EQ(out, "1 m");
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_EQ(out, "1 m");
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_EQ(out, expect);

    expect = "1 minute";
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_EQ(out, expect);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_EQ(out, expect);
}

/**
 * @tc.name: HyphenationTest060
 * @tc.desc: Test MeasureFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest060, TestSize.Level1)
{
    LocaleInfo locale("en", "US");
    I18nStatus status = I18nStatus::ISUCCESS;
    MeasureFormat formatter(locale, status);
    std::string unit = "stroke";

    std::string expect = "12 strokes";
    std::string out = formatter.Format(12, unit, status);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_TRUE(expect.compare(out) == 0);

    expect = "1 stroke";
    out = formatter.Format(1, unit, status);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_TRUE(expect.compare(out) == 0);
}

/**
 * @tc.name: HyphenationTest061
 * @tc.desc: Test MeasureFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest061, TestSize.Level1)
{
    LocaleInfo locale("en", "US");
    I18nStatus status = I18nStatus::ISUCCESS;
    MeasureFormat formatter(locale, status);
    std::string unit = "ft";

    std::string expect = "12 ft";
    std::string out = formatter.Format(12, unit, status);
    EXPECT_EQ(out, "12 ′");
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_EQ(out, "12 ′");
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_EQ(out, expect);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_EQ(out, "12 feet");
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_EQ(out, "12 feet");

    expect = "1 ft";
    out = formatter.Format(1, unit, status);
    EXPECT_EQ(out, "1 ′");
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_EQ(out, "1 ′");
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_EQ(out, expect);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_EQ(out, "1 foot");
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_EQ(out, "1 foot");
}

/**
 * @tc.name: HyphenationTest062
 * @tc.desc: Test MeasureFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest062, TestSize.Level1)
{
    LocaleInfo locale("zh", "Hans", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    MeasureFormat formatter(locale, status);
    std::string unit = "min";

    std::string expect = "12 分钟";
    std::string out = formatter.Format(12, unit, status);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(12, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_TRUE(expect.compare(out) == 0);

    expect = "1 分钟";
    out = formatter.Format(1, unit, status);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_SHORT);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_MEDIUM);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_LONG);
    EXPECT_TRUE(expect.compare(out) == 0);
    out = formatter.Format(1, unit, status, MeasureFormatType::MEASURE_FULL);
    EXPECT_TRUE(expect.compare(out) == 0);
}

/**
 * @tc.name: HyphenationTest063
 * @tc.desc: Test LocaleInfo copy constructor
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest063, TestSize.Level1)
{
    LocaleInfo locale("km", "KH");
    LocaleInfo locale2(locale);
    const char *language = locale2.GetLanguage();
    const char *region = locale2.GetRegion();
    EXPECT_TRUE(language != nullptr);
    EXPECT_TRUE(region != nullptr);
    if (language != nullptr) {
        EXPECT_TRUE(strcmp(language, "km") == 0);
    }
    if (region != nullptr) {
        EXPECT_TRUE(strcmp(region, "KH") == 0);
    }
}

/**
 * @tc.name: HyphenationTest064
 * @tc.desc: Test DateTimeFormat km
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest064, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("km", "", "");
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::ABBR_MONTH_WEEKDAY_DAY;
    DateTimeFormat formatter(pattern, locale);
    string out;
    formatter.Format(0, "", out, status);
    EXPECT_EQ(out, "ព្រហ 1 ខែមករា");
}

/**
 * @tc.name: HyphenationTest065
 * @tc.desc: Test DateTimeFormat kk
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest065, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("kk", "", "");
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::ABBR_MONTH_WEEKDAY_DAY;
    DateTimeFormat formatter(pattern, locale);
    string out;
    formatter.Format(0, "", out, status);
    EXPECT_EQ(out, "1 Қаң., Бс");
}

/**
 * @tc.name: HyphenationTest066
 * @tc.desc: Test DateTimeFormat uz
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest066, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("uz", "", "");
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::ABBR_MONTH_WEEKDAY_DAY;
    DateTimeFormat formatter(pattern, locale);
    string out;
    formatter.Format(0, "", out, status);
    EXPECT_EQ(out, "Pay, 1-yan");
}

/**
 * @tc.name: HyphenationTest067
 * @tc.desc: Test WeekInfo GetFirstDayOfWeek
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest067, TestSize.Level1)
{
    I18nStatus status = I18nStatus::ISUCCESS;
    LocaleInfo locale("kk", "KZ");
    WeekInfo weekInfo(locale, status);
    uint8_t ret = weekInfo.GetFirstDayOfWeek();
    EXPECT_EQ(ret, 2);
    LocaleInfo locale2("km", "KH");
    WeekInfo weekInfo2(locale2, status);
    ret = weekInfo2.GetFirstDayOfWeek();
    EXPECT_EQ(ret, 1);
    LocaleInfo locale3("uz", "UZ");
    WeekInfo weekInfo3(locale3, status);
    ret = weekInfo3.GetFirstDayOfWeek();
    EXPECT_EQ(ret, 2);
}

/**
 * @tc.name: HyphenationTest068
 * @tc.desc: Test PluralFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest068, TestSize.Level1)
{
    LocaleInfo locale("km", "", "");
    I18nStatus status = I18nStatus::ISUCCESS;
    PluralFormat formatter(locale, status);
    double number = 2.3;
    int out = formatter.GetPluralRuleIndex(number, status);
    int expect = PluralRuleType::OTHER;
    EXPECT_EQ(expect, out);
    number = 10.1;
    out = formatter.GetPluralRuleIndex(number, status);
    expect = PluralRuleType::OTHER;
    EXPECT_EQ(expect, out);
    number = 1.5;
    out = formatter.GetPluralRuleIndex(number, status);
    expect = PluralRuleType::OTHER;
    EXPECT_EQ(expect, out);
}

/**
 * @tc.name: HyphenationTest069
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest069, TestSize.Level1)
{
    LocaleInfo locale("be", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::FULL;
    DateTimeFormat formatter(pattern, locale);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "серада, 7 студзеня 1970 г.";
    EXPECT_EQ(expect, out);
}

/**
 * @tc.name: HyphenationTest070
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest070, TestSize.Level1)
{
    LocaleInfo locale("kk", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::MEDIUM;
    DateTimeFormat formatter(pattern, locale);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "1970 ж. 7 Қаң.";
    EXPECT_EQ(expect, out);
}

/**
 * @tc.name: HyphenationTest071
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest071, TestSize.Level1)
{
    LocaleInfo locale("km", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::MEDIUM;
    DateTimeFormat formatter(pattern, locale);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "7 ខែមករា 1970";
    EXPECT_EQ(expect, out);
}

/**
 * @tc.name: HyphenationTest072
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 * @tc.require: issueI4WKP8
 */
HWTEST_F(I18NTest, HyphenationTest072, TestSize.Level1)
{
    LocaleInfo locale("uz", "", "");
    std::string out = "";
    time_t now = 3600 * 3 + 3600 * 24 * 6;
    I18nStatus status = I18nStatus::ISUCCESS;
    AvailableDateTimeFormatPattern pattern = AvailableDateTimeFormatPattern::FULL;
    DateTimeFormat formatter(pattern, locale);
    formatter.Format(now, "-1:45", out, status);
    std::string expect = "chorshanba, 7-yanvar, 1970";
    EXPECT_EQ(expect, out);
}

/**
 * @tc.name: HyphenationTest073
 * @tc.desc: Test numberFormat format integer
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest073, TestSize.Level1)
{
    LocaleInfo locale("be", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    int intNum1 = 1234567;
    int intNum2 = 123456789;
    int intNum3 = 1234;
    std::string out = formatter.Format(intNum1, status);
    std::string out2 = formatter.Format(intNum2, status);
    std::string out3 = formatter.Format(intNum3, status);
    EXPECT_EQ(out, "1 234 567");
    EXPECT_EQ(out2, "123 456 789");
    EXPECT_EQ(out3, "1 234");
}

/**
 * @tc.name: HyphenationTest074
 * @tc.desc: Test numberFormat format integer
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest074, TestSize.Level1)
{
    LocaleInfo locale("km", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    int intNum1 = 1234567;
    int intNum2 = 123456789;
    int intNum3 = 1234;
    std::string out = formatter.Format(intNum1, status);
    std::string out2 = formatter.Format(intNum2, status);
    std::string out3 = formatter.Format(intNum3, status);
    EXPECT_EQ(out, "1,234,567");
    EXPECT_EQ(out2, "123,456,789");
    EXPECT_EQ(out3, "1,234");
}

/**
 * @tc.name: HyphenationTest075
 * @tc.desc: Test numberFormat format integer
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest075, TestSize.Level1)
{
    LocaleInfo locale("kk", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    int intNum1 = 1234567;
    int intNum2 = 123456789;
    int intNum3 = 1234;
    std::string out = formatter.Format(intNum1, status);
    std::string out2 = formatter.Format(intNum2, status);
    std::string out3 = formatter.Format(intNum3, status);
    EXPECT_EQ(out, "1 234 567");
    EXPECT_EQ(out2, "123 456 789");
    EXPECT_EQ(out3, "1 234");
}

/**
 * @tc.name: HyphenationTest076
 * @tc.desc: Test numberFormat format integer
 * @tc.type: FUNC
 */
HWTEST_F(I18NTest, HyphenationTest076, TestSize.Level1)
{
    LocaleInfo locale("uz", "", "");
    int status = 0;
    NumberFormat formatter(locale, status);
    EXPECT_TRUE(status == 0);
    int intNum1 = 1234567;
    int intNum2 = 123456789;
    int intNum3 = 1234;
    std::string out = formatter.Format(intNum1, status);
    std::string out2 = formatter.Format(intNum2, status);
    std::string out3 = formatter.Format(intNum3, status);
    EXPECT_EQ(out, "1 234 567");
    EXPECT_EQ(out2, "123 456 789");
    EXPECT_EQ(out3, "1 234");
}
} // namespace I18N
} // namespace OHOS