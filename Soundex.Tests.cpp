#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoundexTestsuite, ConstantsReplacedByDigits) {
    char soundex[5];
    generateSoundex("BX", soundex);
    ASSERT_STREQ(soundex, "B200");
}
 
TEST(SoundexTestsuite, NonAlphabeticCharactersIgnored) {
    char soundex[5];
    generateSoundex("A1X", soundex);
    ASSERT_STREQ(soundex, "A200");
}

TEST(SoundexTestsuite, HandlesEmptyString) {
    char soundex[5];
    generateSoundex("", soundex);
    ASSERT_STREQ(soundex, "0000");
}
 
TEST(SoundexTestsuite,HandlesDifferentSoundexCodesForSameChar) {
    char soundex[5];
    generateSoundex("CUYHIJ", soundex);
    ASSERT_STREQ(soundex, "C000");
}
 
TEST(SoundexTestsuite, HandlesVowelCharacters) {
    char soundex[5];
    generateSoundex("AEIOUHWY", soundex);
    ASSERT_STREQ(soundex, "A000");
}
 
TEST(SoundexTestsuite, HandlesMultipleSameSoundexCodeCharacters) {
    char soundex[5];
    generateSoundex("YYYY", soundex);
    ASSERT_STREQ(soundex, "Y000");
}
 
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
