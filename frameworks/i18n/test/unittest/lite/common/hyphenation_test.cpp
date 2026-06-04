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

#include <gtest/gtest.h>
#include <map>
#include <vector>
#include <unistd.h>
#include "hyphenation.h"
#include "hyphenation_test.h"

using namespace OHOS::I18N;
using testing::ext::TestSize;
using namespace std;
using namespace testing;

namespace OHOS {
namespace I18N {
class HyphenationTest : public testing::Test {
public:
    void SetUp();
    void TearDown();
};

void HyphenationTest::SetUp()
{
}

void HyphenationTest::TearDown()
{
}

void Print(const char* word, std::vector<int> result, const char* expected)
{
    std::string str = "";
    for (size_t i = 0; i < result.size() ;i++) {
        if (i > 0) str += ",";
        str += std::to_string(result[i]);
    }
    printf("word:%s, result: %s expected:%s \r\n", word, str.c_str(), expected);
}

/**
 * @tc.name: HyphenationTest001
 * @tc.desc: Test LocaleInfo constructor1
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest001, TestSize.Level1)
{
    const char* alocale = "bg";
    Hyphenation* hyphen = Hyphenation::CreateInstance(alocale);
    auto result = hyphen->GetBreakCandidate("България"); //Бъл-га-ри-я
    Print("България", result, "Бъл-га-рия");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[5], 1);
    result = hyphen->GetBreakCandidate("алгоритъм"); // ал-го-ритъм
    Print("алгоритъм", result, "ал-го-ри-тъм");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("майка"); // май-ка
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("речник"); // реч-ник
    EXPECT_EQ(result[3], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest002
 * @tc.desc: Test LocaleInfo constructor2
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest002, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("da");
    auto result = hyphen->GetBreakCandidate("stavelse"); // sta-vel-se
    Print("stavelse", result, "sta-vel-se");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("afbryderknappen"); // afbryderk-nap-pen
    Print("afbryderknappen", result, "afbryderk-nap-pen");
    EXPECT_EQ(result[9], 1);
    EXPECT_EQ(result[12], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest003
 * @tc.desc: Test LocaleInfo default Constructor
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest003, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("de");
    auto result = hyphen->GetBreakCandidate("Wörterbuch"); // Wör-ter-buch
    Print("Wörterbuch", result, "Wör-ter-buch");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("Ärmel"); // Är-mel
    Print("Ärmel", result, "Är-mel");
    EXPECT_EQ(result[2], 1);
    result = hyphen->GetBreakCandidate("Übermut"); // Ü-ber-mut
    Print("Übermut", result, "Über-mut");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("Außenseiter"); // Au-ßen-sei-ter
    Print("Außenseiter", result, "Au-ßen-sei-ter");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("schließen"); // schlie-ßen
    Print("schließen", result, "schlie-ßen");
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("Katze"); // Ka-tze
    Print("Katze", result, "Kat-ze");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("Ecke"); // Ec-ke
    Print("Ecke", result, "Ecke");
    EXPECT_EQ(result[2], 0);
    result = hyphen->GetBreakCandidate("Donaudampfschifffahrt"); // Do-nau-dampf-schiff-fahrt
    Print("Donaudampfschifffahrt", result, "Do-nau-dampf-schiff-fahrt");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[10], 1);
    EXPECT_EQ(result[16], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest004
 * @tc.desc: Test LocaleInfo copy constructor
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest004, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("en-GB");
    auto result = hyphen->GetBreakCandidate("dictionary"); // dic-tion-ar-y
    Print("dictionary", result, "dic-tion-ary");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[7], 1);
    result = hyphen->GetBreakCandidate("colour"); // col-our
    Print("colour", result, "col-our");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("well-known"); // well-known
    Print("well-known", result, "well-known");
    EXPECT_EQ(result[5], 2);
    result = hyphen->GetBreakCandidate("accommodate"); // ac-com-mo-date
    Print("accommodate", result, "ac-com-mod-ate");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("university"); // uni-ver-sity
    Print("university", result, "uni-ver-sity");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("however"); // how-ever
    Print("however", result, "how-ever");
    EXPECT_EQ(result[3], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest005
 * @tc.desc: Test LocaleInfo equals function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest005, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("en-US");
    auto result = hyphen->GetBreakCandidate("dictionary"); // dic-tion-ar-y
    Print("dictionary", result, "dic-tio-nary");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("color"); // col-or
    Print("color", result, "color");
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 0);
    EXPECT_EQ(result[3], 0);
    EXPECT_EQ(result[4], 0);
    result = hyphen->GetBreakCandidate("well-known"); // well-known
    Print("well-known", result, "well-known");
    EXPECT_EQ(result[5], 2);
    result = hyphen->GetBreakCandidate("analyze"); // an-a-lyze
    Print("analyze", result, "an-a-lyze");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[3], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest006
 * @tc.desc: Test LocaleInfo GetLanguage function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest006, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("es");
    auto result = hyphen->GetBreakCandidate("llamar"); // lla-mar
    Print("llamar", result, "lla-mar");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("mucho"); // mu-cho
    Print("mucho", result, "mu-cho");
    EXPECT_EQ(result[2], 1);
    result = hyphen->GetBreakCandidate("diccionario"); // dic-cio-nar-io
    Print("diccionario", result, "dic-cio-na-rio");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    EXPECT_EQ(result[8], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest007
 * @tc.desc: Test LocaleInfo GetRegion function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest007, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("fr");
    auto result = hyphen->GetBreakCandidate("dictionnaire"); // dic-tion-nai-re
    Print("dictionnaire", result, "dic-tion-naire");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[7], 1);
    result = hyphen->GetBreakCandidate("d'accord"); // d'ac-cord
    Print("d'accord", result, "d'ac-cord");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("téléphone"); // té-lé-phone
    Print("téléphone", result, "té-lé-phone");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("antiarché"); // an-ti-ar-ché
    Print("antiarché", result, "an-ti-ar-ché");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[6], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest008
 * @tc.desc: Test LocaleInfo GetScript function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest008, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("hr");
    auto result = hyphen->GetBreakCandidate("rječnik"); // rječ-nik
    Print("rječnik", result, "rječ-nik");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("algoritam"); // al-go-ri-tam
    Print("algoritam", result, "al-go-ri-tam");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[6], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest009
 * @tc.desc: Test LocaleInfo GetId function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest009, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("lt");
    auto result = hyphen->GetBreakCandidate("kompiuteris"); // kom-piu-te-ris
    Print("kompiuteris", result, "kom-piu-te-ris");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("skiemuo"); // ski-emuo
    Print("skiemuo", result, "skie-muo");
    EXPECT_EQ(result[4], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest010
 * @tc.desc: Test LocaleInfo IsDefaultLocale function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest010, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("pl");
    auto result = hyphen->GetBreakCandidate("półach"); // pó-łach
    Print("półach", result, "pó-łach");
    EXPECT_EQ(result[2], 1);
    result = hyphen->GetBreakCandidate("komputer"); // kom-pu-ter
    Print("komputer", result, "kom-pu-ter");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[5], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest011
 * @tc.desc: Test DateTimeFormat Constructor
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest011, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("pt");
    auto result = hyphen->GetBreakCandidate("hardware"); // hard-ware
    Print("hardware", result, "hard-ware");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("software"); // soft-ware
    Print("software", result, "soft-ware");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("bênção"); // bên-ção
    Print("bênção", result, "bên-ção");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("dicionário"); // di-cio-ná-rio
    Print("dicionário", result, "di-cio-ná-rio");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[7], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest012
 * @tc.desc: Test DateTimeFormat Init function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest012, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("sl");
    auto result = hyphen->GetBreakCandidate("računalnik"); // ra-ču-nal-nik
    Print("računalnik", result, "ra-ču-nal-nik");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[7], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest013
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest013, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("be");
    auto result = hyphen->GetBreakCandidate("Беларусь"); // Бе-ла-русь
    Print("Беларусь", result, "Бе-ла-русь");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("камп'ютар"); // кам-п'ю-тар
    Print("камп'ютар", result, "ка-мп'ю-тар");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("выязычэнне"); // вы-язы-чэн-не
    Print("выязычэнне", result, "вы-язы-чэн-не");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("навукова"); // наву-ко-ва
    Print("навукова", result, "на-ву-ко-ва");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[6], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest014
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest014, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("nl");
    auto result = hyphen->GetBreakCandidate("Streuexperiment");
    Print("Streuexperiment", result, "Streu-experi-ment");
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[11], 1);
    result = hyphen->GetBreakCandidate("STREUEXPERIMENT");
    Print("STREUEXPERIMENT", result, "STREU-EXPERI-MENT");
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[11], 1);
    result = hyphen->GetBreakCandidate("AIOUEKIOUAE");
    Print("AIOUEKIOUAE", result, "AIOUE-KIOUAE");
    EXPECT_EQ(result[5], 1);
    result = hyphen->GetBreakCandidate("Iouëloaae");
    Print("Iouëloaae", result, "Iouë-loaae");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("Egostischoïsch");
    Print("Egostischoïsch", result, "Egostischo-ïsch");
    EXPECT_EQ(result[10], 1);
    result = hyphen->GetBreakCandidate("EGCÜHSËECH");
    Print("EGCÜHSËECH", result, "EGC-ÜHS-ËECH");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("Systematischen Antenmechanik");
    Print("Systematischen Antenmechanik", result, "Systematischen A[no break]ntenmechanik");
    result = hyphen->GetBreakCandidate("Systematischen Aëtenmechanik");
    Print("Systematischen Aëtenmechanik", result, "Systematischen A[no break]ëtenmechanik");
    result = hyphen->GetBreakCandidate("SYSTEMATISCHEN FNTENMECHANIK");
    Print("SYSTEMATISCHEN FNTENMECHANIK", result, "SYSTEMATISCHEN F[no break]NTENMECHANIK");
    result = hyphen->GetBreakCandidate("aandachtstrekkers");
    Print("aandachtstrekkers", result, "aan-dachts-trek-kers");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[9], 1);
    EXPECT_EQ(result[13], 1);
    result = hyphen->GetBreakCandidate("onthoofdingen");
    Print("onthoofdingen", result, "ont-hoof-din-gen");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[7], 1);
    EXPECT_EQ(result[10], 1);
    result = hyphen->GetBreakCandidate("achtendertigste");
    Print("achtendertigste", result, "acht-en-der-tig-ste");
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[6], 1);
    EXPECT_EQ(result[9], 1);
    EXPECT_EQ(result[12], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest015
 * @tc.desc: Test DateTimeFormat Format function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest015, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("nl");
    auto result = hyphen->GetBreakCandidate("beschermengelen");
    Print("beschermengelen", result, "be-scherm-en-ge-len");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[8], 1);
    EXPECT_EQ(result[10], 1);
    EXPECT_EQ(result[12], 1);
    result = hyphen->GetBreakCandidate("bijstandstrekkers");
    Print("bijstandstrekkers", result, "bij-stands-trek-kers");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[9], 1);
    EXPECT_EQ(result[13], 1);
    result = hyphen->GetBreakCandidate("ministersportefeuilles");
    Print("ministersportefeuilles", result, "mi-nis-ters-por-te-feuil-les");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[9], 1);
    EXPECT_EQ(result[12], 1);
    EXPECT_EQ(result[14], 1);
    EXPECT_EQ(result[19], 1);
    result = hyphen->GetBreakCandidate("schilderstalent");
    Print("schilderstalent", result, "schil-ders-ta-lent");
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[9], 1);
    EXPECT_EQ(result[11], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest016
 * @tc.desc: Test DateTimeFormat ApplyPattern function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest016, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("el");
    auto result = hyphen->GetBreakCandidate("ργδζθκλξραυστφχψ");
    Print("ργδζθκλξραυστφχψ", result, "ργδζθκλξ-ραυστφχψ");
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("Βγδαβγδαθθελστιφ");
    Print("Βγδαβγδαθθελστιφ", result, "Βγδαβγδαθ-θελστιφ");
    EXPECT_EQ(result[9], 1);
    result = hyphen->GetBreakCandidate("ργδζθκλξραϋστφχψ");
    Print("ργδζθκλξραϋστφχψ", result, "ργδζθκλξ-ραϋστφχψ");
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("ργδζθκλξροΫστφχψ");
    Print("ργδζθκλξροΫστφχψ", result, "ργδζθκλξρο-Ϋστφχψ");
    EXPECT_EQ(result[10], 1);
    result = hyphen->GetBreakCandidate("βγδζθκλξραίστφχ");
    Print("βγδζθκλξραίστφχ", result, "βγδζθκλξ-ραίστφχ");
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("βγδζθκλξράυστφχ");
    Print("βγδζθκλξράυστφχ", result, "βγδζθκλξρά-υστφχ");
    EXPECT_EQ(result[10], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest017
 * @tc.desc: Test DateTimeFormat ApplyPattern function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest017, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("ru");
    auto result = hyphen->GetBreakCandidate("выиграл");
    Print("выиграл", result, "вы-играл");
    EXPECT_EQ(result[2], 1);
    result = hyphen->GetBreakCandidate("выключена");
    Print("выключена", result, "вы-ключена");
    EXPECT_EQ(result[2], 1);
    result = hyphen->GetBreakCandidate("Войдите");
    Print("Войдите", result, "Вой-дите");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("надежности");
    Print("надежности", result, "над-ежности");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("Заботьтесь");
    Print("Заботьтесь", result, "Заботь-тесь");
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("объективный");
    Print("объективный", result, "объ-ективный");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("использовать");
    Print("использовать", result, "и[no break]спользовать");
    
    result = hyphen->GetBreakCandidate("данных");
    Print("данных", result, "д[no break]анных");
   
    result = hyphen->GetBreakCandidate("приложения");
    Print("приложения", result, "п[no break]риложения");
    
    result = hyphen->GetBreakCandidate("статуса");
    Print("статуса", result, "статуса");
    EXPECT_EQ(result[2], 0);
    EXPECT_EQ(result[6], 0);
    result = hyphen->GetBreakCandidate("значок");
    Print("значок", result, "значок");
    EXPECT_EQ(result[5], 0);
    result = hyphen->GetBreakCandidate("Удалить");
    Print("Удалить", result, "Удалить");
    EXPECT_EQ(result[6], 0);
    result = hyphen->GetBreakCandidate("приложений");
    Print("приложений", result, "приложений");
    EXPECT_EQ(result[9], 0);
    result = hyphen->GetBreakCandidate("Станьтщф");
    Print("Станьтщф", result, "Станьтщф");
    EXPECT_EQ(result[5], 0);
    EXPECT_EQ(result[6], 0);
    EXPECT_EQ(result[7], 0);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest018
 * @tc.desc: Test DateTimeFormat ApplyPattern function
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest018, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("ka");
    auto result = hyphen->GetBreakCandidate("კრდათვრიმც");
    Print("კრდათვრიმც", result, "კრდათ-ვრიმც");
    EXPECT_EQ(result[5], 1);
    result = hyphen->GetBreakCandidate("კრბდოყანკ");
    Print("კრბდოყანკ", result, "კრბდო-ყანკ");
    EXPECT_EQ(result[5], 1);
    result = hyphen->GetBreakCandidate("ატფო");
    Print("ატფო", result, "ატ-ფო");
    EXPECT_EQ(result[2], 1);
    result = hyphen->GetBreakCandidate("სახლისთვის");
    Print("სახლისთვის", result, "სახლის-თვის");
    EXPECT_EQ(result[6], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest019
 * @tc.desc: Test DateTimeFormat GetWeekName
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest019, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("it");
    auto result = hyphen->GetBreakCandidate("Asistenzauot");
    Print("Asistenzauot", result, "Asistenza-uot");
    EXPECT_EQ(result[9], 1);
    result = hyphen->GetBreakCandidate("intrfacnmmtcia");
    Print("intrfacnmmtcia", result, "intr-facnmmt-cia");
    EXPECT_EQ(result[4], 1);
    EXPECT_EQ(result[11], 1);
    result = hyphen->GetBreakCandidate("gnocchi");
    Print("gnocchi", result, "gnoc-chi");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("scala");
    Print("scala", result, "sca-la");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("bachi");
    Print("bachi", result, "ba-chi");
    EXPECT_EQ(result[2], 1);
    result = hyphen->GetBreakCandidate("figliastro");
    Print("figliastro", result, "fi-glia-stro");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("biscia");
    Print("biscia", result, "bi-scia");
    EXPECT_EQ(result[2], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest020
 * @tc.desc: Test DateTimeFormat GetMonthName
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest020, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("uk");
    auto result = hyphen->GetBreakCandidate("ийпінхастгфпінхаст");
    Print("ийпінхастгфпінхаст", result, "ийпінхастг-фпінхаст");
    EXPECT_EQ(result[10], 1);
    result = hyphen->GetBreakCandidate("кільце");
    Print("кільце", result, "кіль-це");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("низько");
    Print("низько", result, "низь-ко");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("об’ява");
    Print("об’ява", result, "об’-ява");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("багатоступінчастий");
    Print("багатоступінчастий", result, "багато-ступінчастий");
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("восьмигранний");
    Print("восьмигранний", result, "восьми-гранний");
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("тупінхастий");
    Print("тупінхастий", result, "тупін-хастий");
    EXPECT_EQ(result[5], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest021
 * @tc.desc: Test numberFormat format integer
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest021, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("ru");
    auto result = hyphen->GetBreakCandidate("аккаунт");
    Print("аккаунт", result, "аккаунт");
    EXPECT_EQ(result[5], 0);
    EXPECT_EQ(result[6], 0);
    result = hyphen->GetBreakCandidate("устройств");
    Print("устройств", result, "устройств");
    EXPECT_EQ(result[6], 0);
    EXPECT_EQ(result[7], 0);
    EXPECT_EQ(result[8], 0);
    result = hyphen->GetBreakCandidate("получить");
    Print("получить", result, "получить");
    EXPECT_EQ(result[7], 0);
    result = hyphen->GetBreakCandidate("автозапуск");
    Print("автозапуск", result, "ав-то-запуск");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("большой");
    Print("большой", result, "боль-шой");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("возможно");
    Print("возможно", result, "воз-мож-но");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("возможностей");
    Print("возможностей", result, "воз-мож-нос-тей");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    EXPECT_EQ(result[9], 1);
    result = hyphen->GetBreakCandidate("возникновении");
    Print("возникновении", result, "воз-ник-но-ве-нии");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    EXPECT_EQ(result[8], 1);
    result = hyphen->GetBreakCandidate("воспроизвести");
    Print("воспроизвести", result, "вос-про-из-вес-ти");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("восстановите");
    Print("восстановите", result, "вос-ста-но-ви-те");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    EXPECT_EQ(result[8], 1);
    EXPECT_EQ(result[10], 1);
    result = hyphen->GetBreakCandidate("домну");
    Print("домну", result, "домну");
    EXPECT_EQ(result[3], 0);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest022
 * @tc.desc: Test numberFormat format no group integer
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest022, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("ru");
    auto result = hyphen->GetBreakCandidate("помни");
    Print("помни", result, "помни");
    EXPECT_EQ(result[2], 0);
    result = hyphen->GetBreakCandidate("умнем");
    Print("умнем", result, "умнем");
    EXPECT_EQ(result[3], 0);
    result = hyphen->GetBreakCandidate("умнет");
    Print("умнет", result, "умнет");
    EXPECT_EQ(result[3], 0);
    result = hyphen->GetBreakCandidate("грэс");
    Print("грэс", result, "грэс");
    EXPECT_EQ(result[2], 0);
    result = hyphen->GetBreakCandidate("бездн");
    Print("бездн", result, "бездн");
    EXPECT_EQ(result[2], 0);
    result = hyphen->GetBreakCandidate("аккаунт");
    Print("аккаунт", result, "акка-унт");
    EXPECT_EQ(result[4], 1);
    result = hyphen->GetBreakCandidate("объектов");
    Print("объектов", result, "объ-ектов");
    EXPECT_EQ(result[3], 1);
    result = hyphen->GetBreakCandidate("использовать");
    Print("использовать", result, "исполь-зовать");
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("онлайнуслуг");
    Print("онлайнуслуг", result, "онлайн-услуг");
    EXPECT_EQ(result[6], 1);
    result = hyphen->GetBreakCandidate("онлайнконтента");
    Print("онлайнконтента", result, "онлайн-контента");
    EXPECT_EQ(result[6], 1);
    delete hyphen;
}

/**
 * @tc.name: HyphenationTest023
 * @tc.desc: Test numberFormat format double
 * @tc.type: FUNC
 */
HWTEST_F(HyphenationTest, HyphenationTest023, TestSize.Level1)
{
    Hyphenation* hyphen = Hyphenation::CreateInstance("nl");
    auto result = hyphen->GetBreakCandidate("vernederlandste");
    Print("vernederlandste", result, "ver-ne-der-lands-te");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[5], 1);
    EXPECT_EQ(result[8], 1);
    EXPECT_EQ(result[13], 1);
    result = hyphen->GetBreakCandidate("waterstaatsingenieurs");
    Print("waterstaatsingenieurs", result, "wa-ter-staats-in-ge-ni-eurs");
    EXPECT_EQ(result[5], 1);
    result = hyphen->GetBreakCandidate("palingsteken");
    Print("palingsteken", result, "pa-ling-ste-ken");
    EXPECT_EQ(result[2], 1);
    EXPECT_EQ(result[6], 1);
    EXPECT_EQ(result[9], 1);
    result = hyphen->GetBreakCandidate("kettingsteken");
    Print("kettingsteken", result, "ket-ting-ste-ken");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[7], 1);
    EXPECT_EQ(result[10], 1);
    result = hyphen->GetBreakCandidate("donderaal");
    Print("donderaal", result, "don-der-aal");
    EXPECT_EQ(result[3], 1);
    EXPECT_EQ(result[6], 1);
    delete hyphen;
}
} // namespace I18N
} // namespace OHOS